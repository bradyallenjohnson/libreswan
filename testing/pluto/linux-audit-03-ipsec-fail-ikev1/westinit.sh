/testing/guestbin/swan-prep
setenforce 1
ipsec start
../../guestbin/wait-until-pluto-started
ipsec auto --add ikev1-ipsec-fail
ipsec auto --add ikev1-aggr-ipsec-fail
#ipsec whack --impair timeout_on_retransmit
echo "initdone"
