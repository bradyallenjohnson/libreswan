/*
 * Libreswan config file parser (keywords.c)
 * Copyright (C) 2003-2006 Michael Richardson <mcr@xelerance.com>
 * Copyright (C) 2007-2010 Paul Wouters <paul@xelerance.com>
 * Copyright (C) 2012 Paul Wouters <paul@libreswan.org>
 * Copyright (C) 2013-2019 Paul Wouters <pwouters@redhat.com>
 * Copyright (C) 2013-2019 D. Hugh Redelmeier <hugh@mimosa.com>
 * Copyright (C) 2013 David McCullough <ucdevel@gmail.com>
 * Copyright (C) 2013-2016 Antony Antony <antony@phenome.org>
 * Copyright (C) 2016-2022 Andrew Cagney
 * Copyright (C) 2017 Mayank Totale <mtotale@gmail.com>
 * Copyright (C) 2020 Yulia Kuzovkova <ukuzovkova@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <https://www.gnu.org/licenses/gpl2.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <sys/socket.h>		/* for AF_INET/AF_INET6 */

#include "constants.h"
#include "lmod.h"
#include "lswcdefs.h"		/* for elemsof() */
#include "sparse_names.h"

#include "ipsecconf/keywords.h"
#include "ipsecconf/parser.h"	/* includes parser.tab.h generated by bison; requires keywords.h */
#include "ipsecconf/parserlast.h"

/*
 * Values for failureshunt={passthrough, drop, reject, none}
 */
static const struct sparse_name kw_failureshunt_list[] = {
	{ "none",        KFS_FAIL_NONE },
	{ "passthrough", KFS_FAIL_PASS },
	{ "drop",        KFS_FAIL_DROP },
	{ "hold",        KFS_FAIL_DROP }, /* alias */
	{ "reject",      KFS_FAIL_REJECT },
	SPARSE_NULL
};

/*
 * Values for negotiationshunt={passthrough, hold}
 */
static const struct sparse_name kw_negotiationshunt_list[] = {
	{ "passthrough", KNS_NEGO_PASS },
	{ "drop",        KNS_NEGO_HOLD }, /* alias */
	{ "hold",        KNS_NEGO_HOLD },
	SPARSE_NULL
};

/*
 * Common aliases for YES and NO, add this to a keyword list so all
 * are accepted.
 *
 * This list does not include "0" or "1" as they, for things like
 * yndev have special meanings.
 */
#define YES_NO(YES, NO)				\
	{ "yes",        YES },                  \
       { "no",         NO },			\
       { "true",       YES },			\
       { "false",      NO },			\
       { "on",         YES },			\
       { "off",        NO },			\
       { "y",          YES },			\
       { "n",          NO }

/*
 * Values for enable-tcp={no, yes, fallback}
 */

static const struct sparse_name kw_tcp_list[] = {
	YES_NO(IKE_TCP_ONLY, IKE_TCP_NO/*default*/),
	{ "fallback", IKE_TCP_FALLBACK },
	SPARSE_NULL
};

/*
 * Values for keyexchange= and ikev2=
 *
 * The ikev2= keyword, which was originally very flexible, has been
 * reduced to a boolean.  Retain original keywords for backwards
 * compatibility for now.
 */

static const struct sparse_name kw_keyexchange_list[] = {
	{ "ike",  IKE_VERSION_ROOF },
	{ "ikev1", IKEv1 },
	{ "ikev2", IKEv2 },
	SPARSE_NULL
};

static const struct sparse_name kw_ikev2_list[] = {
	/* from fo_{never,permit,propose,insist} */
	{ "never",     YN_NO },
	{ "propose",   YN_YES },	/* originally: initiate IKEv2,
					 * but allow downgrade to
					 * IKEv1; accept IKEv1 or
					 * IKEv2 */
	{ "permit",    YN_NO },		/* reverse of propose:
					 * initiate IKEv1, but allow
					 * upgrade to IKEv2; accept
					 * IKEv1 or IKEv2? */
	{ "insist",    YN_YES },
	YES_NO(YN_YES, YN_NO),
	{ "always",    YN_YES },
	SPARSE_NULL
};

#ifdef USE_XFRM_INTERFACE
/* Values for no/yes, used by ipsec-interface */
static const struct sparse_name kw_yndev_list[] = {
	YES_NO(1/*ipsec1*/, UINT32_MAX/*disabled*/),
	/* any specified number becomes ipsecXXXX */
	SPARSE_NULL
};
#endif

static const struct sparse_name kw_offload_list[] = {
	{ "no",         offload_no },
	{ "auto",       offload_auto },
	{ "crypto",     offload_crypto },
	{ "packet",     offload_packet },
	{ "yes",        offload_packet }, /* backwards compat */
       SPARSE_NULL
};

static const struct sparse_name kw_ddos_list[] = {
	{ "auto",      DDOS_AUTO },
	{ "busy",      DDOS_FORCE_BUSY },
	{ "unlimited", DDOS_FORCE_UNLIMITED },
	SPARSE_NULL
};

#ifdef USE_SECCOMP
static const struct sparse_name kw_seccomp_list[] = {
	{ "enabled", SECCOMP_ENABLED },
	{ "disabled", SECCOMP_DISABLED },
	{ "tolerant", SECCOMP_TOLERANT },
	SPARSE_NULL
};
#endif

static const struct sparse_name kw_auth_list[] = {
	{ "never",     AUTH_NEVER },
	{ "secret",    AUTH_PSK },
	{ "rsasig",    AUTH_RSASIG },
	{ "rsa",       AUTH_RSASIG }, /* alias */
	{ "ecdsa",     AUTH_ECDSA },
	{ "null",      AUTH_NULL },
	{ "eaponly",   AUTH_EAPONLY },
	SPARSE_NULL
 };

/*
 * Values for dpdaction={hold,clear,restart}
 */
static const struct sparse_name kw_dpdaction_list[] = {
	{ "hold",    DPD_ACTION_HOLD },
	{ "clear",   DPD_ACTION_CLEAR },
	{ "restart",   DPD_ACTION_RESTART },
	/* obsoleted keyword - functionality moved into "restart" */
	{ "restart_by_peer",   DPD_ACTION_RESTART },
	SPARSE_NULL
};

/*
 * Values for sendca={none,issuer,all}
 */

static const struct sparse_name kw_sendca_list[] = {
	{ "none",	CA_SEND_NONE },
	{ "issuer",	CA_SEND_ISSUER },
	{ "all",	CA_SEND_ALL },
	SPARSE_NULL
};

/*
 * Values for auto={add,start,ondemand,ignore,keep}
 */
static const struct sparse_name kw_autostart_list[] = {
	{ "ignore", AUTOSTART_IGNORE },
	{ "add",    AUTOSTART_ADD },
	{ "ondemand",  AUTOSTART_ONDEMAND },
	{ "route",  AUTOSTART_ONDEMAND }, /* backwards compatibility alias */
	{ "start",  AUTOSTART_START },
	{ "up",     AUTOSTART_START }, /* alias */
	{ "keep",   AUTOSTART_KEEP }, /* add plus once up, keep up */
	SPARSE_NULL
};

/*
 * Values for addrfamily={ipv4,ipv6}
 */
static const struct sparse_name kw_addrfamily_list[] = {
	{ "ipv4",  AF_INET },
	{ "ipv6",  AF_INET6 },
	/* aliases - undocumented on purpose */
	{ "v4",    AF_INET },
	{ "inet",  AF_INET },
	{ "v6",    AF_INET6 },
	{ "inet6", AF_INET6 },
	SPARSE_NULL
};

/*
 * Values for type={tunnel,transport,etc}
 */
static const struct sparse_name kw_type_list[] = {
	{ "tunnel",    KS_TUNNEL },
	{ "transport", KS_TRANSPORT },
	{ "pass",      KS_PASSTHROUGH },
	{ "passthrough", KS_PASSTHROUGH },
	{ "reject",    KS_REJECT },
	{ "drop",      KS_DROP },
	SPARSE_NULL
};

/*
 * Values for {rsasigkey,ecdsakey,pubkey}={ %cert, %dnsondemand, %dns, literal }
 */
static const struct sparse_name kw_pubkey_list[] = {
	{ "",             PUBKEY_PREEXCHANGED },
	{ "%cert",        PUBKEY_CERTIFICATE },
#ifdef USE_DNSSEC
	{ "%dns",         PUBKEY_DNSONDEMAND },
	{ "%dnsondemand", PUBKEY_DNSONDEMAND },
#endif
	SPARSE_NULL
};

/*
 *  Cisco interop: remote peer type
 */

static const struct sparse_name kw_remote_peer_type_list[] = {
	{ "cisco",         CISCO },
	SPARSE_NULL
};

static const struct sparse_name kw_xauthby_list[] = {
	{ "file",	XAUTHBY_FILE },
#ifdef USE_PAM_AUTH
	{ "pam",	XAUTHBY_PAM },
#endif
	{ "alwaysok",	XAUTHBY_ALWAYSOK },
	SPARSE_NULL
};

static const struct sparse_name kw_xauthfail_list[] = {
	{ "hard",         XAUTHFAIL_HARD },
	{ "soft",         XAUTHFAIL_SOFT },
	SPARSE_NULL
};

/*
 * Values for right= and left=
 */

static struct sparse_name kw_host_list[] = {
	{ "%defaultroute",  KH_DEFAULTROUTE },
	{ "%any",           KH_ANY },
	{ "%",              KH_IFACE },
	{ "%oppo",          KH_OPPO },
	{ "%opportunistic", KH_OPPO },
	{ "%opportunisticgroup", KH_OPPOGROUP },
	{ "%oppogroup",     KH_OPPOGROUP },
	{ "%group",         KH_GROUP },
	{ "%hostname",      KH_IPHOSTNAME }, /* makes no sense on input */
	SPARSE_NULL
};

static const struct sparse_name kw_phase2types_list[] = {
	/* note: these POLICY bits happen to fit in an unsigned int */
	/* note2: ah+esp is no longer supported as per RFC-8221 Section 4 */
	{ "esp",      POLICY_ENCRYPT },
	{ "ah",       POLICY_AUTHENTICATE },
	{ "default",  POLICY_ENCRYPT }, /* alias, find it last */
	SPARSE_NULL
};

/*
 * Values for {left/right}sendcert={never,sendifasked,always,forcedtype}
 */
static const struct sparse_name kw_sendcert_list[] = {
	{ "never",        CERT_NEVERSEND},
	{ "sendifasked",  CERT_SENDIFASKED },
	{ "alwayssend",   CERT_ALWAYSSEND },
	{ "always",       CERT_ALWAYSSEND },
	SPARSE_NULL
};

/*
 * Values for ocsp-method={get|post}
 *
 * This sets the NSS forcePost option for the OCSP request.
 * If forcePost is set, OCSP requests will only be sent using the HTTP POST
 * method. When forcePost is not set, OCSP requests will be sent using the
 * HTTP GET method, with a fallback to POST when we fail to receive a response
 * and/or when we receive an uncacheable response like "Unknown".
 */

static const struct sparse_name kw_ocsp_method_list[] = {
	{ "get",      OCSP_METHOD_GET },
	{ "post",     OCSP_METHOD_POST },
	SPARSE_NULL
};

static const struct sparse_name kw_global_ikev1_list[] = {
	{ "accept",      GLOBAL_IKEv1_ACCEPT },
	{ "reject",     GLOBAL_IKEv1_REJECT },
	{ "drop",     GLOBAL_IKEv1_DROP },
	SPARSE_NULL
};

static const struct sparse_name kw_eap_list[] = {
	{ "none", IKE_EAP_NONE }, /* default */
	{ "tls", IKE_EAP_TLS },
	SPARSE_NULL
};

/* MASTER KEYWORD LIST
 * Note: this table is terminated by an entry with keyname == NULL.
 */

const struct keyword_def ipsec_conf_keywords[] = {
  { "ikev1-policy",  kv_config,  kt_enum,  KBF_GLOBAL_IKEv1,  kw_global_ikev1_list, NULL, },
  { "curl-iface",  kv_config,  kt_string,  KSF_CURLIFACE, NULL, NULL, },
  { "curl-timeout",  kv_config,  kt_time,  KBF_CURLTIMEOUT_MS, NULL, NULL, },

  { "myvendorid",  kv_config,  kt_string,  KSF_MYVENDORID, NULL, NULL, },
  { "syslog",  kv_config,  kt_string,  KSF_SYSLOG, NULL, NULL, },
  { "plutodebug",  kv_config,  kt_lset,  KBF_PLUTODEBUG, NULL, &debug_lmod_info, },
  { "debug", kv_conn, kt_lset, KNCF_DEBUG, NULL, &debug_lmod_info, },
  { "logfile",  kv_config,  kt_filename,  KSF_LOGFILE, NULL, NULL, },
  { "plutostderrlog",  kv_config,  kt_filename,  KSF_LOGFILE, NULL, NULL, }, /* obsolete name, but very common :/ */
  { "logtime",  kv_config,  kt_bool,  KBF_LOGTIME, NULL, NULL, },
  { "logappend",  kv_config,  kt_bool,  KBF_LOGAPPEND, NULL, NULL, },
  { "logip",  kv_config,  kt_bool,  KBF_LOGIP, NULL, NULL, },
  { "audit-log",  kv_config,  kt_bool,  KBF_AUDIT_LOG, NULL, NULL, },
#ifdef USE_DNSSEC
  { "dnssec-enable",  kv_config,  kt_bool,  KBF_DO_DNSSEC, NULL, NULL, },
  { "dnssec-rootkey-file",  kv_config,  kt_filename, KSF_PLUTO_DNSSEC_ROOTKEY_FILE, NULL, NULL, },
  { "dnssec-anchors",  kv_config,  kt_filename, KSF_PLUTO_DNSSEC_ANCHORS, NULL, NULL, },
#endif
  { "dumpdir",  kv_config,  kt_dirname,  KSF_DUMPDIR, NULL, NULL, },
  { "ipsecdir",  kv_config,  kt_dirname,  KSF_IPSECDIR, NULL, NULL, },
  { "nssdir", kv_config, kt_dirname, KSF_NSSDIR, NULL, NULL, },
  { "secretsfile",  kv_config,  kt_dirname,  KSF_SECRETSFILE, NULL, NULL, },
  { "statsbin",  kv_config,  kt_dirname,  KSF_STATSBINARY, NULL, NULL, },
  { "uniqueids",  kv_config,  kt_bool,  KBF_UNIQUEIDS, NULL, NULL, },
  { "shuntlifetime",  kv_config,  kt_time,  KBF_SHUNTLIFETIME_MS, NULL, NULL, },
  { "global-redirect", kv_config, kt_string, KSF_GLOBAL_REDIRECT, NULL, NULL },
  { "global-redirect-to", kv_config, kt_string, KSF_GLOBAL_REDIRECT_TO, NULL, NULL, },

  { "crl-strict",  kv_config,  kt_bool,  KBF_CRL_STRICT, NULL, NULL, },
  { "crlcheckinterval",  kv_config,  kt_time,  KBF_CRL_CHECKINTERVAL_MS, NULL, NULL, },

  { "ocsp-strict",  kv_config,  kt_bool,  KBF_OCSP_STRICT, NULL, NULL, },
  { "ocsp-enable",  kv_config,  kt_bool,  KBF_OCSP_ENABLE, NULL, NULL, },
  { "ocsp-uri",  kv_config,  kt_string,  KSF_OCSP_URI, NULL, NULL, },
  { "ocsp-timeout",  kv_config,  kt_number,  KBF_OCSP_TIMEOUT, NULL, NULL, },
  { "ocsp-trustname",  kv_config,  kt_string,  KSF_OCSP_TRUSTNAME, NULL, NULL, },
  { "ocsp-cache-size",  kv_config,  kt_number,  KBF_OCSP_CACHE_SIZE, NULL, NULL, },
  { "ocsp-cache-min-age",  kv_config,  kt_time,  KBF_OCSP_CACHE_MIN_AGE_MS, NULL, NULL, },
  { "ocsp-cache-max-age",  kv_config,  kt_time,  KBF_OCSP_CACHE_MAX_AGE_MS, NULL, NULL, },
  { "ocsp-method",  kv_config | kv_processed,  kt_enum,  KBF_OCSP_METHOD,  kw_ocsp_method_list, NULL, },

  { "ddos-mode",  kv_config | kv_processed ,  kt_enum,  KBF_DDOS_MODE,  kw_ddos_list, NULL, },
#ifdef USE_SECCOMP
  { "seccomp",  kv_config | kv_processed ,  kt_enum,  KBF_SECCOMP,  kw_seccomp_list, NULL, },
#endif
  { "ddos-ike-threshold",  kv_config,  kt_number,  KBF_DDOS_IKE_THRESHOLD, NULL, NULL, },
  { "max-halfopen-ike",  kv_config,  kt_number,  KBF_MAX_HALFOPEN_IKE, NULL, NULL, },
  { "ike-socket-bufsize",  kv_config,  kt_number,  KBF_IKEBUF, NULL, NULL, },
  { "ike-socket-errqueue",  kv_config,  kt_bool,  KBF_IKE_ERRQUEUE, NULL, NULL, },
#if defined(HAVE_IPTABLES) || defined(HAVE_NFTABLES)
  { "nflog-all",  kv_config,  kt_number,  KBF_NFLOG_ALL, NULL, NULL, },
#endif
#ifdef XFRM_LIFETIME_DEFAULT
  { "xfrmlifetime",  kv_config,  kt_number,  KBF_XFRMLIFETIME, NULL, NULL, },
#endif
  { "virtual-private",  kv_config,  kt_string,  KSF_VIRTUALPRIVATE, NULL, NULL, },
  { "virtual_private",  kv_config,  kt_string,  KSF_VIRTUALPRIVATE, NULL, NULL, }, /* obsolete variant, very common */
  { "seedbits",  kv_config,  kt_number,  KBF_SEEDBITS, NULL, NULL, },
  { "keep-alive",  kv_config,  kt_number,  KBF_KEEPALIVE, NULL, NULL, },

  { "listen-tcp", kv_config, kt_bool, KBF_LISTEN_TCP, NULL, NULL },
  { "listen-udp", kv_config, kt_bool, KBF_LISTEN_UDP, NULL, NULL },

  { "listen",  kv_config,  kt_string,  KSF_LISTEN, NULL, NULL, },
  { "protostack",  kv_config,  kt_string,  KSF_PROTOSTACK,  NULL, NULL, },
  { "nhelpers",  kv_config,  kt_number,  KBF_NHELPERS, NULL, NULL, },
  { "drop-oppo-null",  kv_config,  kt_bool,  KBF_DROP_OPPO_NULL, NULL, NULL, },
  { "interfaces",  kv_config, kt_obsolete, KNCF_WARNIGNORE, NULL, NULL, }, /* obsoleted but often present keyword */

  /* these options are obsoleted (and not old aliases) */

  /*
   * This is "left=" and "right="
   */
  { "",  kv_conn | kv_leftright| kv_processed,  kt_loose_enum,  KSCF_IP,  kw_host_list, NULL, },

  { "subnet",  kv_conn | kv_leftright | kv_processed,  kt_subnet,  KSCF_SUBNET, NULL, NULL, },
  { "subnets",  kv_conn | kv_leftright,  kt_appendlist,  KSCF_SUBNETS, NULL, NULL, },
  { "sourceip",  kv_conn | kv_leftright,  kt_ipaddr,  KSCF_SOURCEIP, NULL, NULL, },
  { "ikeport",  kv_conn | kv_leftright,  kt_number,  KNCF_IKEPORT, NULL, NULL, },
  { "interface-ip", kv_conn | kv_leftright,  kt_subnet, KSCF_INTERFACE_IP, NULL, NULL, },
  { "vti",  kv_conn | kv_leftright | kv_processed,  kt_subnet,  KSCF_VTI_IP, NULL, NULL, },
  { "nexthop",  kv_conn | kv_leftright,  kt_ipaddr,  KSCF_NEXTHOP, NULL, NULL, },
  { "updown",  kv_conn | kv_leftright,  kt_filename,  KSCF_UPDOWN, NULL, NULL, },
  { "id",  kv_conn | kv_leftright,  kt_idtype,  KSCF_ID, NULL, NULL, },
  { "rsasigkey",  kv_conn | kv_leftright,  kt_pubkey,  KSCF_RSASIGKEY,  kw_pubkey_list, NULL, },
  { "ecdsakey",  kv_conn | kv_leftright,  kt_pubkey,  KSCF_ECDSAKEY,  kw_pubkey_list, NULL, },
  { "pubkey",  kv_conn | kv_leftright,  kt_pubkey,  KSCF_PUBKEY,  kw_pubkey_list, NULL, },
  { "cert",  kv_conn | kv_leftright,  kt_filename,  KSCF_CERT, NULL, NULL, },
  { "ckaid",  kv_conn | kv_leftright,  kt_string,  KSCF_CKAID, NULL, NULL, },
  { "sendcert",  kv_conn | kv_leftright,  kt_enum,  KNCF_SENDCERT,  kw_sendcert_list, NULL, },
  { "ca",  kv_conn | kv_leftright,  kt_string,  KSCF_CA, NULL, NULL, },
  { "xauthserver",  kv_conn | kv_leftright,  kt_bool,  KNCF_XAUTHSERVER, NULL, NULL, },
  { "xauthclient",  kv_conn | kv_leftright,  kt_bool,  KNCF_XAUTHCLIENT, NULL, NULL, },
  { "modecfgserver",  kv_conn | kv_leftright,  kt_bool,  KNCF_MODECONFIGSERVER, NULL, NULL, },
  { "modecfgclient",  kv_conn | kv_leftright,  kt_bool,  KNCF_MODECONFIGCLIENT, NULL, NULL, },
  { "username",  kv_conn | kv_leftright,  kt_string,  KSCF_USERNAME, NULL, NULL, },
  /* xauthusername is still used in NetworkManager-libreswan :/ */
  { "xauthusername",  kv_conn | kv_leftright,  kt_string,  KSCF_USERNAME, NULL, NULL, }, /* old alias */
  { "addresspool",  kv_conn | kv_leftright,  kt_range,  KSCF_ADDRESSPOOL, NULL, NULL, },
  { "auth",  kv_conn | kv_leftright, kt_enum,  KNCF_AUTH,  kw_auth_list, NULL, },
#if defined(HAVE_IPTABLES) || defined(HAVE_NFTABLES)
  { "cat",  kv_conn | kv_leftright,  kt_bool,  KNCF_CAT, NULL, NULL, },
#endif
  { "protoport",  kv_conn | kv_leftright | kv_processed,  kt_string,  KSCF_PROTOPORT, NULL, NULL, },
  { "autheap",  kv_conn | kv_leftright,  kt_enum,  KNCF_EAP,  kw_eap_list, NULL, },
  { "groundhog",  kv_conn | kv_leftright,  kt_string,  KSCF_GROUNDHOG, NULL, NULL, },

  /* these are conn statements which are not left/right */

  { "auto",  kv_conn | kv_duplicateok,  kt_enum,  KNCF_AUTO,  kw_autostart_list, NULL, },
  { "also",  kv_conn,  kt_appendstring,  KSCF_ALSO, NULL, NULL, },
  { "alsoflip",  kv_conn,  kt_string,  KSCF_ALSOFLIP, NULL, NULL, },
  { "ike",  kv_conn,  kt_string,  KSCF_IKE, NULL, NULL, },
  { "hostaddrfamily",  kv_conn,  kt_enum,  KNCF_HOSTADDRFAMILY,  kw_addrfamily_list, NULL, },
  { "clientaddrfamily",  kv_conn,  kt_enum,  KNCF_CLIENTADDRFAMILY,  kw_addrfamily_list, NULL, },
  { "type",  kv_conn,  kt_enum,  KNCF_TYPE,  kw_type_list, NULL, },
  { "authby",  kv_conn,  kt_string,  KSCF_AUTHBY, NULL, NULL, },
  { "keyexchange",  kv_conn,  kt_enum,  KNCF_KEYEXCHANGE,  kw_keyexchange_list, NULL, },
  { "ikev2",  kv_conn | kv_processed,  kt_enum,  KNCF_IKEv2,  kw_ikev2_list, NULL, },
  { "ppk", kv_conn | kv_processed, kt_enum, KNCF_PPK, nppi_option_names, NULL, },
  { "ppk-ids", kv_conn | kv_processed, kt_string, KSCF_PPKIDS, NULL, NULL, },
  { "intermediate",  kv_conn | kv_processed, kt_enum, KNCF_INTERMEDIATE, yn_option_names, NULL, },
  { "esn",  kv_conn | kv_processed,  kt_enum,  KNCF_ESN,  yne_option_names, NULL, },
  { "decap-dscp",  kv_conn | kv_processed,  kt_enum,  KNCF_DECAP_DSCP,  yn_option_names, NULL, },
  { "nopmtudisc",  kv_conn | kv_processed,  kt_enum,  KNCF_NOPMTUDISC,  yn_option_names, NULL, },
  { "fragmentation",  kv_conn | kv_processed,  kt_enum,  KNCF_FRAGMENTATION,  ynf_option_names, NULL, },
  { "mobike",  kv_conn,  kt_enum,  KNCF_MOBIKE, yn_option_names, NULL, },
  { "narrowing",  kv_conn,  kt_enum,  KNCF_IKEv2_ALLOW_NARROWING, yn_option_names, NULL, },
  { "pam-authorize",  kv_conn,  kt_enum,  KNCF_PAM_AUTHORIZE, yn_option_names, NULL, },
  { "send-redirect",  kv_conn,  kt_enum,  KNCF_SEND_REDIRECT, yna_option_names, NULL, },
  { "redirect-to",  kv_conn,  kt_string,  KSCF_REDIRECT_TO, NULL, NULL, },
  { "accept-redirect",  kv_conn,  kt_enum, KNCF_ACCEPT_REDIRECT, yn_option_names, NULL, },
  { "accept-redirect-to",  kv_conn,  kt_string, KSCF_ACCEPT_REDIRECT_TO, NULL, NULL, },
  { "pfs",  kv_conn,  kt_enum,  KNCF_PFS, yn_option_names, NULL, },

  { "nat-keepalive",  kv_conn,  kt_bool,  KNCF_NAT_KEEPALIVE, NULL, NULL, },

  { "initial-contact",  kv_conn,  kt_bool,  KNCF_INITIAL_CONTACT, NULL, NULL, },
  { "cisco-unity",  kv_conn,  kt_bool,  KNCF_CISCO_UNITY, NULL, NULL, },
  { "send-no-esp-tfc",  kv_conn,  kt_bool,  KNCF_NO_ESP_TFC, NULL, NULL, },
  { "fake-strongswan",  kv_conn,  kt_bool,  KNCF_VID_STRONGSWAN, NULL, NULL, },
  { "send-vendorid",  kv_conn,  kt_bool,  KNCF_SEND_VENDORID, NULL, NULL, },
  { "sha2-truncbug",  kv_conn,  kt_enum,  KNCF_SHA2_TRUNCBUG, yn_option_names, NULL, },
  { "ms-dh-downgrade",  kv_conn,  kt_enum,  KNCF_MS_DH_DOWNGRADE, yn_option_names, NULL, },
  { "require-id-on-certificate",  kv_conn,  kt_enum,  KNCF_REQUIRE_ID_ON_CERTIFICATE, yn_option_names, NULL, },
  { "dns-match-id,",  kv_conn,  kt_enum,  KNCF_DNS_MATCH_ID, yn_option_names, NULL, },
  { "ipsec-max-bytes",  kv_conn,  kt_byte,  KNCF_IPSEC_MAXBYTES, NULL, NULL, },
  { "ipsec-lifetime",  kv_conn,  kt_time,  KNCF_IPSEC_LIFETIME_MS, NULL, NULL, },
  { "keylife",  kv_conn | kv_alias,  kt_time,  KNCF_IPSEC_LIFETIME_MS, NULL, NULL, }, /* old name */
  { "lifetime",  kv_conn | kv_alias,  kt_time,  KNCF_IPSEC_LIFETIME_MS, NULL, NULL, }, /* old name */
  { "salifetime",  kv_conn,  kt_time,  KNCF_IPSEC_LIFETIME_MS, NULL, NULL, }, /* old name */
  { "ipsec-max-packets",  kv_conn,  kt_binary,  KNCF_IPSEC_MAXPACKETS, NULL, NULL, },

  { "retransmit-timeout",  kv_conn,  kt_time,  KNCF_RETRANSMIT_TIMEOUT_MS, NULL, NULL, },
  { "retransmit-interval",  kv_conn|kv_milliseconds,  kt_time,  KNCF_RETRANSMIT_INTERVAL_MS, NULL, NULL, },

  { "ikepad",  kv_conn,  kt_enum,  KNCF_IKEPAD, yn_option_names, NULL, },
  { "nat-ikev1-method",  kv_conn | kv_processed,  kt_enum,  KNCF_NAT_IKEv1_METHOD,  nat_ikev1_method_option_names, NULL, },

  { "ikev1-secctx-attr-type",  kv_config,  kt_number,  KNCF_WARNIGNORE, NULL, NULL, },  /* obsolete: not a value, a type */
  { "secctx-attr-type",  kv_config | kv_alias,  kt_number,  KNCF_WARNIGNORE, NULL, NULL, },
  { "policy-label",  kv_conn,  kt_string,  KSCF_SEC_LABEL, NULL, NULL, }, /* obsolete variant */
  { "sec-label",  kv_conn,  kt_string,  KSCF_SEC_LABEL, NULL, NULL, },

  /* Cisco interop: remote peer type */
  { "remote-peer-type",  kv_conn,  kt_enum,  KNCF_REMOTEPEERTYPE,  kw_remote_peer_type_list, NULL, },
  /* another alias used by NetworkManager-libreswan :/ */
  { "remote_peer_type",  kv_conn,  kt_enum,  KNCF_REMOTEPEERTYPE,  kw_remote_peer_type_list, NULL, },

  /* Network Manager support */
#ifdef HAVE_NM
  { "nm-configured",  kv_conn,  kt_bool,  KNCF_NMCONFIGURED, NULL, NULL, },
#endif

  { "xauthby",  kv_conn,  kt_enum,  KNCF_XAUTHBY,  kw_xauthby_list, NULL, },
  { "xauthfail",  kv_conn,  kt_enum,  KNCF_XAUTHFAIL,  kw_xauthfail_list, NULL, },
  { "modecfgpull",  kv_conn,  kt_enum,  KNCF_MODECFGPULL, yn_option_names, NULL, },
  { "modecfgdns",  kv_conn,  kt_string,  KSCF_MODECFGDNS, NULL, NULL, },
  { "modecfgdomains",  kv_conn,  kt_string,  KSCF_MODECFGDOMAINS, NULL, NULL, },
  { "modecfgbanner",  kv_conn,  kt_string,  KSCF_MODECFGBANNER, NULL, NULL, },
  { "ignore-peer-dns",  kv_conn,  kt_enum,  KNCF_IGNORE_PEER_DNS, yn_option_names, NULL, },
  { "mark",  kv_conn,  kt_string,  KSCF_CONN_MARK_BOTH, NULL, NULL, },
  { "mark-in",  kv_conn,  kt_string,  KSCF_CONN_MARK_IN, NULL, NULL, },
  { "mark-out",  kv_conn,  kt_string,  KSCF_CONN_MARK_OUT, NULL, NULL, },
  { "vti-interface",  kv_conn,  kt_string,  KSCF_VTI_IFACE, NULL, NULL, },
  { "vti-routing",  kv_conn,  kt_bool,  KNCF_VTI_ROUTING, NULL, NULL, },
  { "vti-shared",  kv_conn,  kt_bool,  KNCF_VTI_SHARED, NULL, NULL, },
#ifdef USE_XFRM_INTERFACE
  { "ipsec-interface", kv_conn, kt_loose_enum, KNCF_XFRM_IF_ID, kw_yndev_list, NULL, },
#endif

  { "nic-offload",  kv_conn,  kt_enum,  KNCF_NIC_OFFLOAD,  kw_offload_list, NULL, },

  { "encapsulation",  kv_conn,  kt_enum,  KNCF_ENCAPS,  yna_option_names, NULL, },

  { "overlapip",  kv_conn,  kt_enum,  KNCF_OVERLAPIP, yn_option_names, NULL, },
  { "reauth",  kv_conn,  kt_enum,  KNCF_REAUTH, yn_option_names, NULL, },
  { "rekey",  kv_conn,  kt_enum,  KNCF_REKEY, yn_option_names, NULL, },
  { "rekeymargin",  kv_conn,  kt_time,  KNCF_REKEYMARGIN_MS, NULL, NULL, },
  { "rekeyfuzz",  kv_conn,  kt_percent,  KNCF_REKEYFUZZ, NULL, NULL, },
  { "keyingtries",  kv_conn,  kt_number,  KNCF_KEYINGTRIES, NULL, NULL, },
  { "replay-window",  kv_conn,  kt_number,  KNCF_REPLAY_WINDOW, NULL, NULL, },
  { "ikelifetime",  kv_conn,  kt_time,  KNCF_IKELIFETIME_MS, NULL, NULL, },
  { "failureshunt",  kv_conn,  kt_enum,  KNCF_FAILURESHUNT,  kw_failureshunt_list, NULL, },
  { "negotiationshunt",  kv_conn,  kt_enum,  KNCF_NEGOTIATIONSHUNT,  kw_negotiationshunt_list, NULL, },

  { "enable-tcp",  kv_conn, kt_enum, KNCF_ENABLE_TCP, kw_tcp_list, NULL },
  { "tcp-remoteport",  kv_conn, kt_number, KNCF_TCP_REMOTEPORT, NULL, NULL },

  { "connalias",  kv_conn | kv_processed,  kt_appendstring,  KSCF_CONNALIAS, NULL, NULL, },

  /* attributes of the phase2 policy */
  { "esp",  kv_conn,  kt_string,  KSCF_ESP, NULL, NULL, },
  { "ah",  kv_conn,  kt_string,  KSCF_ESP, NULL, NULL, },
  { "phase2alg",  kv_conn | kv_alias,  kt_string,  KSCF_ESP, NULL, NULL, },	/* obsolete */

  { "phase2",  kv_conn | kv_policy,  kt_enum,  KNCF_PHASE2,  kw_phase2types_list, NULL, },

  { "compress",  kv_conn,  kt_bool,  KNCF_COMPRESS, NULL, NULL, },

  /* route metric */
  { "metric",  kv_conn,  kt_number,  KNCF_METRIC, NULL, NULL, },

  /* DPD */
  { "dpddelay",  kv_conn,  kt_string,  KSCF_DPDDELAY_MS, NULL, NULL, },
  { "ikev1-dpdtimeout",  kv_conn,  kt_string,  KSCF_DPDTIMEOUT_MS, NULL, NULL, },
  { "dpdtimeout",  kv_conn | kv_alias,  kt_string,  KSCF_DPDTIMEOUT_MS, NULL, NULL, }, /* old name */
  { "dpdaction",  kv_conn,  kt_enum,  KNCF_DPDACTION,  kw_dpdaction_list, NULL, },

  { "sendca",      kv_conn,  kt_enum,  KNCF_SEND_CA,  kw_sendca_list, NULL, },

  { "mtu",  kv_conn,  kt_number,  KNCF_MTU, NULL, NULL, },
  { "priority",  kv_conn,  kt_number,  KNCF_PRIORITY, NULL, NULL, },
  { "tfc",  kv_conn,  kt_number,  KNCF_TFC, NULL, NULL, },
  { "reqid",  kv_conn,  kt_number,  KNCF_REQID, NULL, NULL, },
#if defined(HAVE_IPTABLES) || defined(HAVE_NFTABLES)
  { "nflog",  kv_conn,  kt_number,  KNCF_NFLOG_CONN, NULL, NULL, },
#endif

  { "aggressive",  kv_conn,  kt_enum,  KNCF_AGGRESSIVE, yn_option_names, NULL, },
  /* alias for compatibility - undocumented on purpose */
  { "aggrmode",  kv_conn | kv_alias,  kt_enum,  KNCF_AGGRESSIVE, yn_option_names, NULL, },

  { NULL,  0,  0,  0, NULL, NULL, }
};

/* distinguished keyword */
static const struct keyword_def ipsec_conf_keyword_comment =
	{ "x-comment",      kv_conn,   kt_comment, 0, NULL, NULL, };


/*
 * look for one of the above tokens, and set the value up right.
 *
 * if we don't find it, then strdup() the string and return a string
 *
 */

/* type is really "token" type, which is actually int */
int parser_find_keyword(const char *s, YYSTYPE *lval)
{
	bool left = false;
	bool right = false;
	int keywordtype;

	const struct keyword_def *k;
	for (k = ipsec_conf_keywords; k->keyname != NULL; k++) {
		if (strcaseeq(s, k->keyname)) {
			if (k->validity & kv_leftright) {
#if 0 /* see github#663 */
				left = true;
#endif
				right = true;
			}
			break;
		}

		if (k->validity & kv_leftright) {
			if (strncaseeq(s, "left", 4) &&
			    strcaseeq(s + 4, k->keyname)) {
				left = true;
				break;
			}
			if (strncaseeq(s, "right", 5) &&
			    strcaseeq(s + 5, k->keyname)) {
				right = true;
				break;
			}
		}
	}

	lval->s = NULL;
	/* if we found nothing */
	if (k->keyname == NULL &&
	    (s[0] == 'x' || s[0] == 'X') && (s[1] == '-' || s[1] == '_')) {
		k = &ipsec_conf_keyword_comment;
		lval->k.string = strdup(s);
	}

	/* if we still found nothing */
	if (k->keyname == NULL) {
		lval->s = strdup(s);
		return STRING;
	}

	switch (k->type) {
	case kt_percent:
		keywordtype = PERCENTWORD;
		break;
	case kt_binary:
		keywordtype = BINARYWORD;
		break;
	case kt_byte:
		keywordtype = BYTEWORD;
		break;
	case kt_comment:
		keywordtype = COMMENT;
		break;
	case kt_bool:
		keywordtype = BOOLWORD;
		break;
	default:
		keywordtype = KEYWORD;
		break;
	}

	/* else, set up llval.k to point, and return KEYWORD */
	lval->k.keydef = k;
	lval->k.keyleft = left;
	lval->k.keyright = right;
	return keywordtype;
}

uintmax_t parser_enum(const struct keyword_def *kd, const char *s)
{
	assert(kd->type == kt_enum);
	assert(kd->validenum != NULL && kd->validenum != NULL);

	const struct sparse_name *sn = sparse_lookup(kd->validenum, s);
	if (sn != NULL) {
		return sn->value;
	}

	/* perhaps an unsigned integer? */
	uintmax_t number;
	if (shunk_to_uintmax(shunk1(s), NULL, /*base*/10, &number) == NULL) {
		return number;
	}

	/* we didn't find anything, complain */
	fprintf(stderr,
		"ERROR: %s: %d: keyword %s, invalid value: %s\n",
		parser_cur_filename(),
		parser_cur_lineno(),
		kd->keyname,
		s);
	exit(1);
}

uintmax_t parser_enum_list(const struct keyword_def *kd, const char *s)
{
	assert(kd->type == kt_list);

	unsigned int valresult = 0;

	/*
	 * Split up the string into comma separated pieces, and look
	 * each piece up in the value list provided in the definition.
	 */

	int numfound = 0;
	shunk_t cursor = shunk1(s);
	while (true) {
		shunk_t piece = shunk_token(&cursor, NULL/*delim*/, ":, \t");
		if (piece.ptr == NULL) {
			break;
		}
		if (piece.len == 0) {
			/* discard empty strings */
			continue;
		}

		assert(kd->validenum != NULL);
		for (const struct sparse_name *kev = kd->validenum;
		     kev->name != NULL; kev++) {
			if (hunk_strcaseeq(piece, kev->name)) {
				/* found it: count it */
				numfound++;
				valresult |= kev->value;
				break;
			}
		}
		if (numfound == 0) {
			/* we didn't find anything, complain */
			fprintf(stderr,
				"ERROR: %s: %d: keyword %s, invalid value: "PRI_SHUNK"\n",
				parser_cur_filename(),
				parser_cur_lineno(),
				kd->keyname,
				pri_shunk(piece));
			exit(1);
		}
	}

	return valresult;
}

lset_t parser_lset(const struct keyword_def *kd, const char *value)
{
	assert(kd->type == kt_lset);

	lmod_t result;
	zero(&result);

	/*
	 * Use lmod_args() since it both knows how to parse a comma
	 * separated list and can handle no-XXX (ex: all,no-xauth).
	 * The final set of enabled bits is returned in .set.
	 */
	if (!lmod_arg(&result, kd->info, value, true/*enable*/)) {
		/*
		 * If the lookup failed, complain (and exit!).
		 *
		 * XXX: the error diagnostic is a little vague -
		 * should lmod_arg() instead return the error?
		 */
		fprintf(stderr, "ERROR: %s: %d: keyword %s, invalid value: %s\n",
			parser_cur_filename(), parser_cur_lineno(),
			kd->keyname, value);
		exit(1);
	}

	return result.set;
}

uintmax_t parser_loose_enum(struct keyword *k, const char *s)
{
	const struct keyword_def *kd = k->keydef;

	assert(kd->type == kt_loose_enum || kd->type == kt_pubkey);
	assert(kd->validenum != NULL && kd->validenum != NULL);

	for (const struct sparse_name *kev = kd->validenum; kev->name != NULL; kev++) {
		if (strcaseeq(s, kev->name)) {
			k->string = NULL;
			return kev->value;
		}
	}

	/* perhaps an unsigned integer? */
	uintmax_t number;
	if (shunk_to_uintmax(shunk1(s), NULL, /*base*/10, &number) == NULL) {
		k->string = NULL;
		return number;
	}

	k->string = strdup(s);	/* ??? why not xstrdup? */
	return 255; /* what the heck is 255? */
}
