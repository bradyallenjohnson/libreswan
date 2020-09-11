/*
 * manifest constants
 *
 * Copyright (C) 1997 Angelos D. Keromytis.
 * Copyright (C) 1998-2002,2013 D. Hugh Redelmeier <hugh@mimosa.com>
 * Copyright (C) 2004 Michael Richardson <mcr@xelerance.com>
 * Copyright (C) 2012 Avesh Agarwal <avagarwa@redhat.com>
 * Copyright (C) 2012 Paul Wouters <paul@libreswan.org>
 * Copyright (C) 2012-2015 Paul Wouters <pwouters@redhat.com>
 * Copyright (C) 2013 Tuomo Soini <tis@foobar.fi>
 * Copyright (C) 2016 Andrew Cagney <cagney@gnu.org>
 * Copyright (C) 2017 Sahana Prasad <sahana.prasad07@gmail.com>
 * Copyright (C) 2017 Vukasin Karadzic <vukasin.karadzic@gmail.com>
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
 *
 */
#ifndef _IETF_CONSTANTS_H
#define _IETF_CONSTANTS_H

#include <sys/types.h>
#include <stdint.h>		/* XXX: needed but should it? */

/* Group parameters from draft-ietf-ike-01.txt section 6 */

#define MODP_GENERATOR "02" /* HEX! */

/* Diffie-Hellman group 22 generator (RFC 5114) */
#define MODP_GENERATOR_DH22 \
	"A4D1CBD5 C3FD3412 6765A442 EFB99905 F8104DD2 58AC507F " \
	"D6406CFF 14266D31 266FEA1E 5C41564B 777E690F 5504F213 " \
	"160217B4 B01B886A 5E91547F 9E2749F4 D7FBD7D3 B9A92EE1 " \
	"909D0D22 63F80A76 A6A24C08 7A091F53 1DBF0A01 69B6A28A " \
	"D662A4D1 8E73AFA3 2D779D59 18D08BC8 858F4DCE F97C2A24 " \
	"855E6EEB 22B3B2E5"

/* Diffie-Hellman group 23 generator (RFC 5114) */
#define MODP_GENERATOR_DH23 \
	"AC4032EF 4F2D9AE3 9DF30B5C 8FFDAC50 6CDEBE7B 89998CAF " \
	"74866A08 CFE4FFE3 A6824A4E 10B9A6F0 DD921F01 A70C4AFA " \
	"AB739D77 00C29F52 C57DB17C 620A8652 BE5E9001 A8D66AD7 " \
	"C1766910 1999024A F4D02727 5AC1348B B8A762D0 521BC98A " \
	"E2471504 22EA1ED4 09939D54 DA7460CD B5F6C6B2 50717CBE " \
	"F180EB34 118E98D1 19529A45 D6F83456 6E3025E3 16A330EF " \
	"BB77A86F 0C1AB15B 051AE3D4 28C8F8AC B70A8137 150B8EEB " \
	"10E183ED D19963DD D9E263E4 770589EF 6AA21E7F 5F2FF381 " \
	"B539CCE3 409D13CD 566AFBB4 8D6C0191 81E1BCFE 94B30269 " \
	"EDFE72FE 9B6AA4BD 7B5A0F1C 71CFFF4C 19C418E1 F6EC0179 " \
	"81BC087F 2A7065B3 84B890D3 191F2BFA"

/* Diffie-Hellman group 24 generator (RFC 5114) */
#define MODP_GENERATOR_DH24 \
	"3FB32C9B 73134D0B 2E775066 60EDBD48 4CA7B18F 21EF2054 " \
	"07F4793A 1A0BA125 10DBC150 77BE463F FF4FED4A AC0BB555 " \
	"BE3A6C1B 0C6B47B1 BC3773BF 7E8C6F62 901228F8 C28CBB18 " \
	"A55AE313 41000A65 0196F931 C77A57F2 DDF463E5 E9EC144B " \
	"777DE62A AAB8A862 8AC376D2 82D6ED38 64E67982 428EBC83 " \
	"1D14348F 6F2F9193 B5045AF2 767164E1 DFC967C1 FB3F2E55 " \
	"A4BD1BFF E83B9C80 D052B985 D182EA0A DB2A3B73 13D3FE14 " \
	"C8484B1E 052588B9 B7D2BBD2 DF016199 ECD06E15 57CD0915 " \
	"B3353BBB 64E0EC37 7FD02837 0DF92B52 C7891428 CDC67EB6 " \
	"184B523D 1DB246C3 2F630784 90F00EF8 D647D148 D4795451 " \
	"5E2327CF EF98C582 664B4C0F 6CC41659"

#if 0 /* too weak - left only as reference */
/* RFC-2049 */
#define MODP768_MODULUS \
	"FFFFFFFF FFFFFFFF C90FDAA2 2168C234 C4C6628B 80DC1CD1 " \
	"29024E08 8A67CC74 020BBEA6 3B139B22 514A0879 8E3404DD " \
	"EF9519B3 CD3A431B 302B0A6D F25F1437 4FE1356D 6D51C245 " \
	"E485B576 625E7EC6 F44C42E9 A63A3620 FFFFFFFF FFFFFFFF"
#endif

/* RFC-2049 */
/* getting on the weak side now */
#define MODP1024_MODULUS \
	"FFFFFFFF FFFFFFFF C90FDAA2 2168C234 C4C6628B 80DC1CD1 " \
	"29024E08 8A67CC74 020BBEA6 3B139B22 514A0879 8E3404DD " \
	"EF9519B3 CD3A431B 302B0A6D F25F1437 4FE1356D 6D51C245 " \
	"E485B576 625E7EC6 F44C42E9 A637ED6B 0BFF5CB6 F406B7ED " \
	"EE386BFB 5A899FA5 AE9F2411 7C4B1FE6 49286651 ECE65381 " \
	"FFFFFFFF FFFFFFFF"

/* RFC-3526 DH5 */
#define MODP1536_MODULUS \
	"FFFFFFFF FFFFFFFF C90FDAA2 2168C234 C4C6628B 80DC1CD1 " \
	"29024E08 8A67CC74 020BBEA6 3B139B22 514A0879 8E3404DD " \
	"EF9519B3 CD3A431B 302B0A6D F25F1437 4FE1356D 6D51C245 " \
	"E485B576 625E7EC6 F44C42E9 A637ED6B 0BFF5CB6 F406B7ED " \
	"EE386BFB 5A899FA5 AE9F2411 7C4B1FE6 49286651 ECE45B3D " \
	"C2007CB8 A163BF05 98DA4836 1C55D39A 69163FA8 FD24CF5F " \
	"83655D23 DCA3AD96 1C62F356 208552BB 9ED52907 7096966D " \
	"670C354E 4ABC9804 F1746C08 CA237327 FFFFFFFF FFFFFFFF "

/* RFC-3526 DH14 */
#define MODP2048_MODULUS \
	"FFFFFFFF FFFFFFFF C90FDAA2 2168C234 C4C6628B 80DC1CD1" \
	"29024E08 8A67CC74 020BBEA6 3B139B22 514A0879 8E3404DD" \
	"EF9519B3 CD3A431B 302B0A6D F25F1437 4FE1356D 6D51C245" \
	"E485B576 625E7EC6 F44C42E9 A637ED6B 0BFF5CB6 F406B7ED" \
	"EE386BFB 5A899FA5 AE9F2411 7C4B1FE6 49286651 ECE45B3D" \
	"C2007CB8 A163BF05 98DA4836 1C55D39A 69163FA8 FD24CF5F" \
	"83655D23 DCA3AD96 1C62F356 208552BB 9ED52907 7096966D" \
	"670C354E 4ABC9804 F1746C08 CA18217C 32905E46 2E36CE3B" \
	"E39E772C 180E8603 9B2783A2 EC07A28F B5C55DF0 6F4C52C9" \
	"DE2BCBF6 95581718 3995497C EA956AE5 15D22618 98FA0510" \
	"15728E5A 8AACAA68 FFFFFFFF FFFFFFFF"

/* RFC-3526 DH15 */
#define MODP3072_MODULUS \
	"FFFFFFFF FFFFFFFF C90FDAA2 2168C234 C4C6628B 80DC1CD1" \
	"29024E08 8A67CC74 020BBEA6 3B139B22 514A0879 8E3404DD" \
	"EF9519B3 CD3A431B 302B0A6D F25F1437 4FE1356D 6D51C245" \
	"E485B576 625E7EC6 F44C42E9 A637ED6B 0BFF5CB6 F406B7ED" \
	"EE386BFB 5A899FA5 AE9F2411 7C4B1FE6 49286651 ECE45B3D" \
	"C2007CB8 A163BF05 98DA4836 1C55D39A 69163FA8 FD24CF5F" \
	"83655D23 DCA3AD96 1C62F356 208552BB 9ED52907 7096966D" \
	"670C354E 4ABC9804 F1746C08 CA18217C 32905E46 2E36CE3B" \
	"E39E772C 180E8603 9B2783A2 EC07A28F B5C55DF0 6F4C52C9" \
	"DE2BCBF6 95581718 3995497C EA956AE5 15D22618 98FA0510" \
	"15728E5A 8AAAC42D AD33170D 04507A33 A85521AB DF1CBA64" \
	"ECFB8504 58DBEF0A 8AEA7157 5D060C7D B3970F85 A6E1E4C7" \
	"ABF5AE8C DB0933D7 1E8C94E0 4A25619D CEE3D226 1AD2EE6B" \
	"F12FFA06 D98A0864 D8760273 3EC86A64 521F2B18 177B200C" \
	"BBE11757 7A615D6C 770988C0 BAD946E2 08E24FA0 74E5AB31" \
	"43DB5BFC E0FD108E 4B82D120 A93AD2CA FFFFFFFF FFFFFFFF"

/* RFC-3526 DH16 */
#define MODP4096_MODULUS \
	"FFFFFFFF FFFFFFFF C90FDAA2 2168C234 C4C6628B 80DC1CD1" \
	"29024E08 8A67CC74 020BBEA6 3B139B22 514A0879 8E3404DD" \
	"EF9519B3 CD3A431B 302B0A6D F25F1437 4FE1356D 6D51C245" \
	"E485B576 625E7EC6 F44C42E9 A637ED6B 0BFF5CB6 F406B7ED" \
	"EE386BFB 5A899FA5 AE9F2411 7C4B1FE6 49286651 ECE45B3D" \
	"C2007CB8 A163BF05 98DA4836 1C55D39A 69163FA8 FD24CF5F" \
	"83655D23 DCA3AD96 1C62F356 208552BB 9ED52907 7096966D" \
	"670C354E 4ABC9804 F1746C08 CA18217C 32905E46 2E36CE3B" \
	"E39E772C 180E8603 9B2783A2 EC07A28F B5C55DF0 6F4C52C9" \
	"DE2BCBF6 95581718 3995497C EA956AE5 15D22618 98FA0510" \
	"15728E5A 8AAAC42D AD33170D 04507A33 A85521AB DF1CBA64" \
	"ECFB8504 58DBEF0A 8AEA7157 5D060C7D B3970F85 A6E1E4C7" \
	"ABF5AE8C DB0933D7 1E8C94E0 4A25619D CEE3D226 1AD2EE6B" \
	"F12FFA06 D98A0864 D8760273 3EC86A64 521F2B18 177B200C" \
	"BBE11757 7A615D6C 770988C0 BAD946E2 08E24FA0 74E5AB31" \
	"43DB5BFC E0FD108E 4B82D120 A9210801 1A723C12 A787E6D7" \
	"88719A10 BDBA5B26 99C32718 6AF4E23C 1A946834 B6150BDA" \
	"2583E9CA 2AD44CE8 DBBBC2DB 04DE8EF9 2E8EFC14 1FBECAA6" \
	"287C5947 4E6BC05D 99B2964F A090C3A2 233BA186 515BE7ED" \
	"1F612970 CEE2D7AF B81BDD76 2170481C D0069127 D5B05AA9" \
	"93B4EA98 8D8FDDC1 86FFB7DC 90A6C08F 4DF435C9 34063199" \
	"FFFFFFFF FFFFFFFF"

/* RFC-3526 DH17 */
#define MODP6144_MODULUS \
	"FFFFFFFF FFFFFFFF C90FDAA2 2168C234 C4C6628B 80DC1CD1 29024E08" \
	"8A67CC74 020BBEA6 3B139B22 514A0879 8E3404DD EF9519B3 CD3A431B" \
	"302B0A6D F25F1437 4FE1356D 6D51C245 E485B576 625E7EC6 F44C42E9" \
	"A637ED6B 0BFF5CB6 F406B7ED EE386BFB 5A899FA5 AE9F2411 7C4B1FE6" \
	"49286651 ECE45B3D C2007CB8 A163BF05 98DA4836 1C55D39A 69163FA8" \
	"FD24CF5F 83655D23 DCA3AD96 1C62F356 208552BB 9ED52907 7096966D" \
	"670C354E 4ABC9804 F1746C08 CA18217C 32905E46 2E36CE3B E39E772C" \
	"180E8603 9B2783A2 EC07A28F B5C55DF0 6F4C52C9 DE2BCBF6 95581718" \
	"3995497C EA956AE5 15D22618 98FA0510 15728E5A 8AAAC42D AD33170D" \
	"04507A33 A85521AB DF1CBA64 ECFB8504 58DBEF0A 8AEA7157 5D060C7D" \
	"B3970F85 A6E1E4C7 ABF5AE8C DB0933D7 1E8C94E0 4A25619D CEE3D226" \
	"1AD2EE6B F12FFA06 D98A0864 D8760273 3EC86A64 521F2B18 177B200C" \
	"BBE11757 7A615D6C 770988C0 BAD946E2 08E24FA0 74E5AB31 43DB5BFC" \
	"E0FD108E 4B82D120 A9210801 1A723C12 A787E6D7 88719A10 BDBA5B26" \
	"99C32718 6AF4E23C 1A946834 B6150BDA 2583E9CA 2AD44CE8 DBBBC2DB" \
	"04DE8EF9 2E8EFC14 1FBECAA6 287C5947 4E6BC05D 99B2964F A090C3A2" \
	"233BA186 515BE7ED 1F612970 CEE2D7AF B81BDD76 2170481C D0069127" \
	"D5B05AA9 93B4EA98 8D8FDDC1 86FFB7DC 90A6C08F 4DF435C9 34028492" \
	"36C3FAB4 D27C7026 C1D4DCB2 602646DE C9751E76 3DBA37BD F8FF9406" \
	"AD9E530E E5DB382F 413001AE B06A53ED 9027D831 179727B0 865A8918" \
	"DA3EDBEB CF9B14ED 44CE6CBA CED4BB1B DB7F1447 E6CC254B 33205151" \
	"2BD7AF42 6FB8F401 378CD2BF 5983CA01 C64B92EC F032EA15 D1721D03" \
	"F482D7CE 6E74FEF6 D55E702F 46980C82 B5A84031 900B1C9E 59E7C97F" \
	"BEC7E8F3 23A97A7E 36CC88BE 0F1D45B7 FF585AC5 4BD407B2 2B4154AA" \
	"CC8F6D7E BF48E1D8 14CC5ED2 0F8037E0 A79715EE F29BE328 06A1D58B" \
	"B7C5DA76 F550AA3D 8A1FBFF0 EB19CCB1 A313D55C DA56C9EC 2EF29632" \
	"387FE8D7 6E3C0468 043E8F66 3F4860EE 12BF2D5B 0B7474D6 E694F91E" \
	"6DCC4024 FFFFFFFF FFFFFFFF"

/* RFC-3526 DH18 */
#define MODP8192_MODULUS \
	"FFFFFFFF FFFFFFFF C90FDAA2 2168C234 C4C6628B 80DC1CD1" \
	"29024E08 8A67CC74 020BBEA6 3B139B22 514A0879 8E3404DD" \
	"EF9519B3 CD3A431B 302B0A6D F25F1437 4FE1356D 6D51C245" \
	"E485B576 625E7EC6 F44C42E9 A637ED6B 0BFF5CB6 F406B7ED" \
	"EE386BFB 5A899FA5 AE9F2411 7C4B1FE6 49286651 ECE45B3D" \
	"C2007CB8 A163BF05 98DA4836 1C55D39A 69163FA8 FD24CF5F" \
	"83655D23 DCA3AD96 1C62F356 208552BB 9ED52907 7096966D" \
	"670C354E 4ABC9804 F1746C08 CA18217C 32905E46 2E36CE3B" \
	"E39E772C 180E8603 9B2783A2 EC07A28F B5C55DF0 6F4C52C9" \
	"DE2BCBF6 95581718 3995497C EA956AE5 15D22618 98FA0510" \
	"15728E5A 8AAAC42D AD33170D 04507A33 A85521AB DF1CBA64" \
	"ECFB8504 58DBEF0A 8AEA7157 5D060C7D B3970F85 A6E1E4C7" \
	"ABF5AE8C DB0933D7 1E8C94E0 4A25619D CEE3D226 1AD2EE6B" \
	"F12FFA06 D98A0864 D8760273 3EC86A64 521F2B18 177B200C" \
	"BBE11757 7A615D6C 770988C0 BAD946E2 08E24FA0 74E5AB31" \
	"43DB5BFC E0FD108E 4B82D120 A9210801 1A723C12 A787E6D7" \
	"88719A10 BDBA5B26 99C32718 6AF4E23C 1A946834 B6150BDA" \
	"2583E9CA 2AD44CE8 DBBBC2DB 04DE8EF9 2E8EFC14 1FBECAA6" \
	"287C5947 4E6BC05D 99B2964F A090C3A2 233BA186 515BE7ED" \
	"1F612970 CEE2D7AF B81BDD76 2170481C D0069127 D5B05AA9" \
	"93B4EA98 8D8FDDC1 86FFB7DC 90A6C08F 4DF435C9 34028492" \
	"36C3FAB4 D27C7026 C1D4DCB2 602646DE C9751E76 3DBA37BD" \
	"F8FF9406 AD9E530E E5DB382F 413001AE B06A53ED 9027D831" \
	"179727B0 865A8918 DA3EDBEB CF9B14ED 44CE6CBA CED4BB1B" \
	"DB7F1447 E6CC254B 33205151 2BD7AF42 6FB8F401 378CD2BF" \
	"5983CA01 C64B92EC F032EA15 D1721D03 F482D7CE 6E74FEF6" \
	"D55E702F 46980C82 B5A84031 900B1C9E 59E7C97F BEC7E8F3" \
	"23A97A7E 36CC88BE 0F1D45B7 FF585AC5 4BD407B2 2B4154AA" \
	"CC8F6D7E BF48E1D8 14CC5ED2 0F8037E0 A79715EE F29BE328" \
	"06A1D58B B7C5DA76 F550AA3D 8A1FBFF0 EB19CCB1 A313D55C" \
	"DA56C9EC 2EF29632 387FE8D7 6E3C0468 043E8F66 3F4860EE" \
	"12BF2D5B 0B7474D6 E694F91E 6DBE1159 74A3926F 12FEE5E4" \
	"38777CB6 A932DF8C D8BEC4D0 73B931BA 3BC832B6 8D9DD300" \
	"741FA7BF 8AFC47ED 2576F693 6BA42466 3AAB639C 5AE4F568" \
	"3423B474 2BF1C978 238F16CB E39D652D E3FDB8BE FC848AD9" \
	"22222E04 A4037C07 13EB57A8 1A23F0C7 3473FC64 6CEA306B" \
	"4BCBC886 2F8385DD FA9D4B7F A2C087E8 79683303 ED5BDD3A" \
	"062B3CF5 B3A278A6 6D2A13F8 3F44F82D DF310EE0 74AB6A36" \
	"4597E899 A0255DC1 64F31CC5 0846851D F9AB4819 5DED7EA1" \
	"B1D510BD 7EE74D73 FAF36BC3 1ECFA268 359046F4 EB879F92" \
	"4009438B 481C6CD7 889A002E D5EE382B C9190DA6 FC026E47" \
	"9558E447 5677E9AA 9E3050E2 765694DF C81F56E8 80B96E71" \
	"60C980DD 98EDD3DF FFFFFFFF FFFFFFFF"

/* Diffie-Hellman group 22 prime (RFC 5114) */
#define MODP1024_MODULUS_DH22 \
	"B10B8F96 A080E01D DE92DE5E AE5D54EC 52C99FBC FB06A3C6 " \
	"9A6A9DCA 52D23B61 6073E286 75A23D18 9838EF1E 2EE652C0 " \
	"13ECB4AE A9061123 24975C3C D49B83BF ACCBDD7D 90C4BD70 " \
	"98488E9C 219A7372 4EFFD6FA E5644738 FAA31A4F F55BCCC0 " \
	"A151AF5F 0DC8B4BD 45BF37DF 365C1A65 E68CFDA7 6D4DA708 " \
	"DF1FB2BC 2E4A4371"

/* Diffie-Hellman group 23 prime (RFC 5114) */
#define MODP2048_MODULUS_DH23 \
	"AD107E1E 9123A9D0 D660FAA7 9559C51F A20D64E5 683B9FD1 " \
	"B54B1597 B61D0A75 E6FA141D F95A56DB AF9A3C40 7BA1DF15 " \
	"EB3D688A 309C180E 1DE6B85A 1274A0A6 6D3F8152 AD6AC212 " \
	"9037C9ED EFDA4DF8 D91E8FEF 55B7394B 7AD5B7D0 B6C12207 " \
	"C9F98D11 ED34DBF6 C6BA0B2C 8BBC27BE 6A00E0A0 B9C49708 " \
	"B3BF8A31 70918836 81286130 BC8985DB 1602E714 415D9330 " \
	"278273C7 DE31EFDC 7310F712 1FD5A074 15987D9A DC0A486D " \
	"CDF93ACC 44328387 315D75E1 98C641A4 80CD86A1 B9E587E8 " \
	"BE60E69C C928B2B9 C52172E4 13042E9B 23F10B0E 16E79763 " \
	"C9B53DCF 4BA80A29 E3FB73C1 6B8E75B9 7EF363E2 FFA31F71 " \
	"CF9DE538 4E71B81C 0AC4DFFE 0C10E64F"

/* Diffie-Hellman group 24 prime (RFC 5114) */
#define MODP2048_MODULUS_DH24 \
	"87A8E61D B4B6663C FFBBD19C 65195999 8CEEF608 660DD0F2 " \
	"5D2CEED4 435E3B00 E00DF8F1 D61957D4 FAF7DF45 61B2AA30 " \
	"16C3D911 34096FAA 3BF4296D 830E9A7C 209E0C64 97517ABD " \
	"5A8A9D30 6BCF67ED 91F9E672 5B4758C0 22E0B1EF 4275BF7B " \
	"6C5BFC11 D45F9088 B941F54E B1E59BB8 BC39A0BF 12307F5C " \
	"4FDB70C5 81B23F76 B63ACAE1 CAA6B790 2D525267 35488A0E " \
	"F13C6D9A 51BFA4AB 3AD83477 96524D8E F6A167B5 A41825D9 " \
	"67E144E5 14056425 1CCACB83 E6B486F6 B3CA3F79 71506026 " \
	"C0B857F6 89962856 DED4010A BD0BE621 C3A3960A 54E710C3 " \
	"75F26375 D7014103 A4B54330 C198AF12 6116D227 6E11715F " \
	"693877FA D7EF09CA DB094AE9 1E1A1597"

#define LOCALSECRETSIZE BYTES_FOR_BITS(256)


/* Limits on nonce sizes */

/*
 * IKEv1 RFC-2409:
 * The length of nonce payload MUST be between 8 and 256 bytes inclusive.
 */
#define IKEv1_MINIMUM_NONCE_SIZE 8 /* bytes */
#define IKEv1_MAXIMUM_NONCE_SIZE 256 /* bytes */

/*
 * IKEv2 RFC-7296:
 * Nonces used in IKEv2 MUST be randomly chosen, MUST be at least 128 bits
 * in size, and MUST be at least half the key size of the negotiated
 * pseudorandom function (PRF). However, the initiator chooses the nonce
 * before the outcome of the negotiation is known.  Because of that, the
 * nonce has to be long enough for all the PRFs being proposed.
 */
#define IKEv2_MINIMUM_NONCE_SIZE 16 /* bytes */
#define IKEv2_MAXIMUM_NONCE_SIZE 256 /* bytes */

/* Default is based on minimum IKEv2 requirement */
#define DEFAULT_NONCE_SIZE 32 /* bytes */

/*
 * Security Parameter Index (SPI):
 *
 * The IKE SA's SPI, which is a fixed part of the IKEv1/IKEv2 message
 * header, is 8 bytes long.
 *
 * The CHILD SA's SPI is 4 bytes (IKEv2: 3.3.1.  Proposal
 * Substructure).
 *
 * XXX:
 *
 * IKEv1, presumably as a way to ensure maximum confusion, used the
 * term "cookie" when describing the IKE SA's SPI in the message
 * header, and the term SPI when describing IKE SPIs (yes, one or two)
 * within a payload (the term "cookie" is included as a parenthetical
 * clarification).
 *
 * IKEv1, instead consistently uses SPI for both the IKE and CHILD
 * SAs, that is both when describing the message header and the
 * contents of payloads.  Unfortunately, IKEv2 then went on to use
 * term "cookie" when describing its new cookie mechanism (implemented
 * with notifications).
 *
 * This would have all been ok if FreeS/WAN had used the term SPI in
 * its code.
 *
 * It didn't.
 *
 * Instead it choose to use the word "cookie".  Hence lingering
 * presence of things like [ir]cookie, the macro COOKIE_SIZE (below),
 * and IKEv1 centric types such as ipsec_spi_t in the code.
 */

#define IKE_SA_SPI_SIZE			8
#define CHILD_SA_SPI_SIZE		4
#define MAX_SPI_SIZE			IKE_SA_SPI_SIZE

#define COOKIE_SIZE 			IKE_SA_SPI_SIZE

#define INTERNAL_IP6_ADDRESS_SIZE 	17
#define INTERNL_IP6_PREFIX_LEN_SIZE	1
#define INTERNL_IP6_PREFIX_LEN		128
#define INTERNL_IP4_PREFIX_LEN		32

/*
 * XXX:
 *
 * For IKEv1, the maximum number of SPI bytes in some payloads.  For
 * instance: rfc2408: 4.6.3.1 RESPONDER-LIFETIME: either sixteen (16)
 * (two eight-octet ISAKMP cookies) or four (4) (one IPSEC SPI)
 *
 * XXX: this desperately needs a better name.  In IKEv2 SPI size
 * always refers to the size of one SPI and never a pair.
 */
#define MAX_ISAKMP_SPI_SIZE 		(2 * IKE_SA_SPI_SIZE)


/* IKEv2 DOS COOKIE */
#define IKEv2_MAX_COOKIE_SIZE 64

/* Various IETF defined key lengths */

/* AES-CBC RFC 3602 The _only_ valid values are 128, 192 and 256 bits */
#define  AES_KEY_MIN_LEN        128 /* bits */
#define  AES_KEY_DEF_LEN        128 /* bits */
#define  AES_KEY_MAX_LEN        256 /* bits */

/*
 * https://tools.ietf.org/html/rfc3566#section-4.1
 */
#define AES_XCBC_DIGEST_SIZE BYTES_FOR_BITS(128)
#define AES_XCBC_DIGEST_SIZE_TRUNC BYTES_FOR_BITS(96)

/* AES-CTR RFC 3686 The _only_ valid values are 128, 192 and 256 bits */
#define AES_CTR_SALT_BYTES 4
#define  AES_CTR_KEY_MIN_LEN 128 /* bits */
#define  AES_CTR_KEY_DEF_LEN 128 /* bits */
#define  AES_CTR_KEY_MAX_LEN 256 /* bits */

/*
 * RFC 4106 AES GCM
 * https://tools.ietf.org/html/rfc4106#section-8.1
 */
#define AES_GCM_SALT_BYTES 4
#define AES_GCM_KEY_MIN_LEN 128 /* bits */
#define AES_GCM_KEY_DEF_LEN 128 /* bits */
#define AES_GCM_KEY_MAX_LEN 256 /* bits */

/*
 * RFC 4309 AES CCM
 * https://tools.ietf.org/html/rfc4309#section-7.1
 */
#define AES_CCM_SALT_BYTES 3
#define AES_CCM_KEY_MIN_LEN 128 /* bits */
#define AES_CCM_KEY_DEF_LEN 128 /* bits */
#define AES_CCM_KEY_MAX_LEN 256 /* bits */

/* The _only_ valid values are 128, 192 and 256 bits */
#define  AEAD_AES_KEY_MIN_LEN       128 /* bits */
#define  AEAD_AES_KEY_DEF_LEN       128 /* bits */
#define  AEAD_AES_KEY_MAX_LEN       256 /* bits */

/* AES-GMAC RFC 4543 The _only_ valid values are 128, 192 and 256 bits */
#define  AES_GMAC_KEY_MIN_LEN 128 /* bits */
#define  AES_GMAC_KEY_DEF_LEN 128 /* bits */
#define  AES_GMAC_KEY_MAX_LEN 256 /* bits */

/* SEED-CBC RFC 4196 The _only_ valid value is 128 */
#define  SEED_KEY_MIN_LEN 128 /* bits */
#define  SEED_KEY_DEF_LEN 128 /* bits */
#define  SEED_KEY_MAX_LEN 128 /* bits */


/*
 * https://tools.ietf.org/html/rfc2451#section-2.2
 * ESP_CAST is the cast5 algorithm, not cast6
 * We avoid cast-128 padding by enforcing a minimum of 128
 */
#define  CAST_KEY_DEF_LEN        128 /* bits */

/*
 * RFC 2451 - Blowfish accepts key sizes 40-448, default is 128
 *            128,192 and 256 are the only commonly used ones
 */

/*
 * TWOFISH-CBC is a 128-bit block cipher with variable-length key up to 256 bits
 * default is 128. 128, 192 and 256 are the only commonly used ones
 */
#define  TWOFISH_KEY_MIN_LEN 128 /* bits */
#define  TWOFISH_KEY_DEF_LEN 128 /* bits */
#define  TWOFISH_KEY_MAX_LEN 256 /* bits */

/*
 * SERPENT default 128, 128, 192 and 256 are the only commonly used ones
 */
#define  SERPENT_KEY_MIN_LEN 128 /* bits */
#define  SERPENT_KEY_DEF_LEN 128 /* bits */
#define  SERPENT_KEY_MAX_LEN 256 /* bits */

/*
 * Camellia CBC and CTR - RFC 5529
 * 128 (default), 192 and 256
 */
#define  CAMELLIA_KEY_MIN_LEN 128 /* bits */
#define  CAMELLIA_KEY_DEF_LEN 128 /* bits */
#define  CAMELLIA_KEY_MAX_LEN 256 /* bits */

#define  CAMELLIA_CTR_KEY_MIN_LEN 128 /* bits */
#define  CAMELLIA_CTR_KEY_DEF_LEN 128 /* bits */
#define  CAMELLIA_CTR_KEY_MAX_LEN 256 /* bits */


 /* ought to be supplied by md5.h */
#define MD5_DIGEST_SIZE BYTES_FOR_BITS(128)
/* IKEV2 integrity algorithms */
#define MD5_DIGEST_SIZE_96 BYTES_FOR_BITS(96)
/* ought to be supplied by sha1.h */
#define SHA1_DIGEST_SIZE BYTES_FOR_BITS(160)
#define SHA1_BLOCK_SIZE BYTES_FOR_BITS(512)
/* IKEV2 integrity algorithms */
#define SHA1_DIGEST_SIZE_96 BYTES_FOR_BITS(96)

#define SHA2_256_DIGEST_SIZE BYTES_FOR_BITS(256) /* sha2.h */
#define SHA2_384_DIGEST_SIZE BYTES_FOR_BITS(384)
#define SHA2_512_DIGEST_SIZE BYTES_FOR_BITS(512)

/* not in blapit.h */
#define DES_CBC_BLOCK_SIZE BYTES_FOR_BITS(64)
#define AES_CBC_BLOCK_SIZE BYTES_FOR_BITS(128)

#define TWOFISH_CBC_BLOCK_SIZE BYTES_FOR_BITS(128)
/* SERPENT_CBC_BLOCK_SIZE: BYTES_FOR_BITS(128) */

/*
 * hand-computed max of *_CBC_BLOCK_SIZE
 * Needs to be a compile-time constant for array allocation.
 */
#define MAX_CBC_BLOCK_SIZE BYTES_FOR_BITS(128)

#define DSS_QBITS 160 /* bits in DSS's "q" (FIPS 186-1) */

/* RFC 2404 "HMAC-SHA-1-96" section 3 */
#define HMAC_SHA1_KEY_LEN SHA1_DIGEST_SIZE	/* bytes */

/* RFC 2403 "HMAC-MD5-96" section 3 */
#define HMAC_MD5_KEY_LEN MD5_DIGEST_SIZE	/* bytes */

#define IKE_UDP_PORT 500
#define NAT_IKE_UDP_PORT 4500 /* RFC-3947 */
/* RFC3948: bytes of zeros, same size as ESP SPI */
#define NON_ESP_MARKER_SIZE 4

/* RFC8229: prefix at start of tcp stream (no NUL) */
#define IKE_IN_TCP_PREFIX { 'I', 'K', 'E', 'T', 'C', 'P', }

/* ICMP type number for neighbor discovery */
#define ICMP_NEIGHBOR_DISCOVERY 34816
#define ICMP_NEIGHBOR_SOLICITATION 34560

/* Version numbers - IKEv1 */
#define ISAKMP_MAJOR_VERSION 0x1
#define ISAKMP_MINOR_VERSION 0x0

/* version numbers - IKEv2 */
#define IKEv2_MAJOR_VERSION 0x2
#define IKEv2_MINOR_VERSION 0x0

/* Domain of Interpretation */
#define ISAKMP_DOI_ISAKMP 0
#define ISAKMP_DOI_IPSEC 1

/* IPsec DOI things */

#define IPSEC_DOI_SITUATION_LENGTH 4
#define IPSEC_DOI_LDI_LENGTH 4
#define IPSEC_DOI_SPI_SIZE 4

/*
 * SPI value 0 is invalid and values 1-255 are reserved to IANA.
 * ESP: RFC 2402 2.4; AH: RFC 2406 2.1
 * IPComp RFC 2393 substitutes a CPI in the place of an SPI.
 * see also draft-shacham-ippcp-rfc2393bis-05.txt.
 * We (Libreswan) reserve 0x100 to 0xFFF for manual keying, so
 * Pluto won't generate these values.
 */
#define IPSEC_DOI_SPI_MIN 0x100
#define IPSEC_DOI_SPI_OUR_MIN 0x1000


/*
 * Payload types
 * RFC2408 Internet Security Association and Key Management Protocol (ISAKMP)
 * section 3.1
 *
 * RESERVED 14-127
 * Private USE 128-255
 */
enum next_payload_types_ikev1 {
	ISAKMP_NEXT_NONE = 0, /* No other payload following - See also v2_PROPOSAL_LAST */
	ISAKMP_NEXT_SA = 1, /* Security Association */
	ISAKMP_NEXT_P = 2, /* Proposal - See also v2_PROPOSAL_NON_LAST */
	ISAKMP_NEXT_T = 3, /* Transform */
	ISAKMP_NEXT_KE = 4, /* Key Exchange */
	ISAKMP_NEXT_ID = 5, /* Identification */
	ISAKMP_NEXT_CERT = 6, /* Certificate */
	ISAKMP_NEXT_CR = 7, /* Certificate Request */
	ISAKMP_NEXT_HASH = 8, /* Hash */
	ISAKMP_NEXT_SIG = 9, /* Signature */
	ISAKMP_NEXT_NONCE = 10, /* Nonce */
	ISAKMP_NEXT_N = 11, /* Notification */
	ISAKMP_NEXT_D = 12, /* Delete */
	ISAKMP_NEXT_VID = 13, /* Vendor ID */
	ISAKMP_NEXT_MCFG_ATTR = 14, /* Mode config Attribute */
	/* NAT-Traversal: NAT-D (bad drafts) Conflicts with RFC 3547 (not 3947!) and RFC 6407 */
	/* old value: ISAKMP_NEXT_NATD_BADDRAFTS = 15 */
	ISAKMP_NEXT_SAK = 15, /* SA KEK Payload - RFC 6407 */
	ISAKMP_NEXT_TEK = 16, /* SA TEK Payload - RFC 6407 */
	ISAKMP_NEXT_KD = 17, /* Key Download - RFC 3547 */
	ISAKMP_NEXT_SEQ = 18, /* Sequence Number - RFC 3547 */
	ISAKMP_NEXT_POP = 19, /* Proof of Possession - RFC 3547 */
	ISAKMP_NEXT_NATD_RFC = 20, /* NAT-Traversal: NAT-D RFC 3947 */
	ISAKMP_NEXT_NATOA_RFC = 21, /* NAT-Traversal: NAT-OA RFC 3947 */
	ISAKMP_NEXT_GAP = 22, /* Group Associated Policy = RFC 6407 */
	/* 23-127 Unassigned */
	/* 128 - 255 Private Use */
	ISAKMP_NEXT_NATD_DRAFTS = 130, /* NAT-Traversal: NAT-D (drafts) */
	ISAKMP_NEXT_NATOA_DRAFTS = 131, /* NAT-Traversal: NAT-OA (drafts) */
	/* Cisco/Microsoft proprietary IKE fragmentation */
	ISAKMP_NEXT_IKE_FRAGMENTATION = 132,

	ISAKMP_NEXT_ROOF /* roof on payload types */
};

enum ikev2_last_proposal {
	/* if there is a next proposal, then the lp needs to be set right */
	v2_PROPOSAL_LAST = 0, /* matches IKEv1 ISAKMP_NEXT_NONE by design */
	v2_PROPOSAL_NON_LAST = 2 /* matches IKEv1 ISAKMP_NEXT_P by design */
};

enum ikev2_last_transform {
	/* if there is a next transform, then the lt needs to be set right */
	v2_TRANSFORM_LAST = 0, /* matches IKEv1 ISAKMP_NEXT_NONE by design */
	v2_TRANSFORM_NON_LAST = 3 /* matches IKEv1 ISAKMP_NEXT_T by design */
};

enum next_payload_types_ikev2 {
	ISAKMP_NEXT_v2NONE = 0,
	/* 1 - 32 Reserved for IKEv1 */
	ISAKMP_NEXT_v2SA = 33,	/* Security Association */
	ISAKMP_NEXT_v2KE = 34,	/* Key Exchange payload */
	ISAKMP_NEXT_v2IDi = 35,	/* ID payload - initiator */
	ISAKMP_NEXT_v2IDr = 36,	/* ID payload - responder */
	ISAKMP_NEXT_v2CERT = 37,	/* CERTificate */
	ISAKMP_NEXT_v2CERTREQ = 38,	/* CERTificate REQuest */
	ISAKMP_NEXT_v2AUTH = 39,	/* AUTHentication */
	ISAKMP_NEXT_v2Ni = 40,	/* Nonce - initiator */
	ISAKMP_NEXT_v2Nr = ISAKMP_NEXT_v2Ni,	/* Nonce - responder */
	ISAKMP_NEXT_v2N = 41,	/* Notify */
	ISAKMP_NEXT_v2D = 42,	/* Delete */
	ISAKMP_NEXT_v2V = 43,	/* Vendor ID */
	ISAKMP_NEXT_v2TSi = 44,	/* Traffic Selector - initiator */
	ISAKMP_NEXT_v2TSr = 45,	/* Traffic Selector - responder */
	ISAKMP_NEXT_v2SK = 46,	/* Encrypted payload */
	ISAKMP_NEXT_v2CP = 47,	/* Configuration Payload (MODECFG) */
	ISAKMP_NEXT_v2EAP = 48,	/* Extensible Authentication Payload */
	ISAKMP_NEXT_v2GSPM = 49, /* RFC-6467 Generic Secure Password Method */
	ISAKMP_NEXT_v2IDG = 50, /* Group Identification draft-yeung-g-ikev2 */
	ISAKMP_NEXT_v2GSA = 51, /* Group Security Association draft-yeung-g-ikev2 */
	ISAKMP_NEXT_v2KD = 52, /* Key Download draft-yeung-g-ikev2 */
	ISAKMP_NEXT_v2SKF = 53,	/* Encrypted and Authenticated Fragment fragment */
	/* 54-127 Unassigned */
	/* 128 - 255 Private Use */
	/* Cisco/Microsoft proprietary IKE fragmentation - private use for libreswan */
	ISAKMP_NEXT_v2IKE_FRAGMENTATION = 132,
	ISAKMP_NEXT_v2ROOF,	/* roof on payload types */
};

#define ISAKMP_v2PAYLOAD_TYPE_BASE	ISAKMP_NEXT_v2SA	/* lowest value of a v2 payload type */

/*
 * Value to use when emitting a payload that the other end won't
 * recognize forcing it down the unknown (and not just unsupported)
 * payload code path:
 *
 * - fills the entire 8-bit field (so signed vs unsigned overflows)
 *
 * - too big to fit in an lset_t (so would overflow that code)
 *
 * - not "known" by pluto (so enum name lookups fail)
 *
 * - since it isn't known, it is also, by definition unsupported
 */
#define ISAKMP_NEXT_v2UNKNOWN		255

/*
 * These values are to be used within the Type field of an Attribute (14)
 * ISAKMP payload.
 */
#define ISAKMP_CFG_REQUEST 1
#define ISAKMP_CFG_REPLY 2
#define ISAKMP_CFG_SET 3
#define ISAKMP_CFG_ACK 4

/* Mode Config attribute values */
#define INTERNAL_IP4_ADDRESS 1
#define INTERNAL_IP4_NETMASK 2
#define INTERNAL_IP4_DNS 3
#define INTERNAL_IP4_NBNS 4 /* unused by us, WINS is long dead */
#define INTERNAL_ADDRESS_EXPIRY 5
#define INTERNAL_IP4_DHCP 6
#define APPLICATION_VERSION 7
#define INTERNAL_IP6_ADDRESS 8
#define INTERNAL_IP6_NETMASK 9
#define INTERNAL_IP6_DNS 10
#define INTERNAL_IP6_NBNS 11
#define INTERNAL_IP6_DHCP 12
#define INTERNAL_IP4_SUBNET 13
#define SUPPORTED_ATTRIBUTES 14
#define INTERNAL_IP6_SUBNET 15
#define MIP6_HOME_PREFIX 16
#define INTERNAL_IP6_LINK 17
#define INTERNAL_IP6_PREFIX 18
#define HOME_AGENT_ADDRESS 19


/* 65001 - 65535 Private Use */
#define FICTIVE_AUTH_METHOD_XAUTH_PSKEY_I 65500
/* extended authentication modes */
#define XAUTH_AUTH_INIT_PSK 65001
#define XAUTH_AUTH_RESP_PSK 65002
#define XAUTH_AUTH_INIT_DSS 65003
#define XAUTH_AUTH_RESP_DSS 65004
#define XAUTH_AUTH_INIT_RSA 65005
#define XAUTH_AUTH_RESP_RSA 65006
#define XAUTH_AUTH_INIT_RSA_ENC 65007
#define XAUTH_AUTH_RESP_RSA_ENC 65008
#define XAUTH_AUTH_INIT_RSA_REV 65009
#define XAUTH_AUTH_RESP_RSA_REV 65010

/*
 * GSS mode - should only be allowed after receiving vendorids:
 * MD5("A GSS-API Authentication Method for IKE")
 * MD5("GSSAPI") (recognized by Windows 2000)
 * MD5("MS NT5 ISAKMPOAKLEY") (sent by Windows 2000)
 */
/*
 * Note: OAKLEY_ATTR_AUTH_METHOD_GSSAPI_KRB conflicts
 * with XAUTH_AUTH_INIT_PSK
 */
#define OAKLEY_ATTR_AUTH_METHOD_GSSAPI_KRB 65001
#define OAKLEY_ATTR_GSS_ID 16384
#define MAXPADLWORD 20

/* hybrid authentication modes */
#define HYBRID_AUTH_INIT_RSA 64221
#define HYBRID_AUTH_RESP_RSA 64222
#define HYBRID_AUTH_INIT_DSS 64223
#define HYBRID_AUTH_RESP_DSS 64224

/* XAUTH attribute values (draft-ietf-ipsec-isakmp-xauth-06 4.2) */
#define XAUTH_TYPE 16520
#define XAUTH_USER_NAME 16521
#define XAUTH_USER_PASSWORD 16522
#define XAUTH_PASSCODE 16523
#define XAUTH_MESSAGE 16524
#define XAUTH_CHALLENGE 16525
#define XAUTH_DOMAIN 16526
#define XAUTH_STATUS 16527
#define XAUTH_NEXT_PIN 16528
#define XAUTH_ANSWER 16529

/* Values of XAUTH_STATUS attribute (draft-ietf-ipsec-isakmp-xauth-06 4.2) */
#define XAUTH_STATUS_FAIL	0
#define XAUTH_STATUS_OK	1

/* Values of XAUTH_TYPE attributes */
#define XAUTH_TYPE_GENERIC 0
#define XAUTH_TYPE_CHAP 1
#define XAUTH_TYPE_OTP 2
#define XAUTH_TYPE_SKEY 3

/* proprietary Microsoft attributes */
#define INTERNAL_IP4_SERVER 23456
#define INTERNAL_IP6_SERVER 23457

/* Unity (Cisco) Mode Config attribute values */
#define MODECFG_BANNER 28672
#define CISCO_SAVE_PW 28673
#define MODECFG_DOMAIN 28674
#define CISCO_SPLIT_DNS 28675
#define CISCO_SPLIT_INC 28676
#define CISCO_UDP_ENCAP_PORT 28677
#define CISCO_SPLIT_EXCLUDE 28678
#define CISCO_DO_PFS 28679
#define CISCO_FW_TYPE 28680
#define CISCO_BACKUP_SERVER 28681
#define CISCO_DDNS_HOSTNAME 28682
#define CISCO_UNKNOWN_SEEN_ON_IPHONE 28683

/* checkpoint extended authentication attributes */
#define CHKPT_TYPE 13
#define CHKPT_USER_NAME 14
#define CHKPT_USER_PASSWORD 15
#define CHKPT_MESSAGE 17
#define CHKPT_CHALLENGE 18
#define CHKPT_STATUS 20

/* checkpoint configuration attributes */
#define CHKPT_DEF_DOMAIN 16387
#define CHKPT_MAC_ADDRESS 16388
#define CHKPT_MARCIPAN_REASON_CODE 16389
#define CHKPT_UNKNOWN1 16400
#define CHKPT_UNKNOWN2 16401
#define CHKPT_UNKNOWN3 16402

/*
 * Exchange types
 * RFC2408 "Internet Security Association and Key Management Protocol (ISAKMP)"
 * section 3.1
 *
 * ISAKMP Future Use 6 - 31
 * DOI Specific Use 32 - 239
 * Private Use 240 - 255
 *
 * Note: draft-ietf-ipsec-dhless-enc-mode-00.txt Appendix A
 * defines "DHless RSA Encryption" as 6.
 */

enum isakmp_xchg_types {
	ISAKMP_XCHG_NONE = 0,
	ISAKMP_XCHG_BASE = 1,
	ISAKMP_XCHG_IDPROT = 2, /* ID Protection */
	ISAKMP_XCHG_AO = 3, /* Authentication Only */
	ISAKMP_XCHG_AGGR = 4, /* Aggressive */
	ISAKMP_XCHG_INFO = 5, /* Informational */
	ISAKMP_XCHG_MODE_CFG = 6, /* Mode Config */

	/* Private exchanges to pluto -- openswan mistakenly uses these */
	ISAKMP_XCHG_STOLEN_BY_OPENSWAN_FOR_ECHOREQUEST = 30, /* Echo Request */
	ISAKMP_XCHG_STOLEN_BY_OPENSWAN_FOR_ECHOREPLY = 31, /* Echo Reply */

	/* Extra exchange types, defined by Oakley
	 * RFC2409 "The Internet Key Exchange (IKE)", near end of Appendix A
	 */
	ISAKMP_XCHG_QUICK = 32, /* Oakley Quick Mode */
	ISAKMP_XCHG_NGRP = 33, /* Oakley New Group Mode */

	/* IKEv2 things */
	ISAKMP_v2_IKE_SA_INIT = 34,
	ISAKMP_v2_IKE_AUTH = 35,
	ISAKMP_v2_CREATE_CHILD_SA = 36,
	ISAKMP_v2_INFORMATIONAL = 37,
	ISAKMP_v2_IKE_SESSION_RESUME = 38, /* RFC 5723 */
	ISAKMP_v2_GSA_AUTH = 39, /* draft-yeung-g-ikev2 */
	ISAKMP_v2_GSA_REGISTRATION = 40, /* draft-yeung-g-ikev2 */
	ISAKMP_v2_GSA_REKEY = 41, /* draft-yeung-g-ikev2 */
	ISAKMP_v2_UNASSIGNED_42 = 42, /* avoid hole in enum */
	ISAKMP_v2_IKE_INTERMEDIATE = 43, /* draft-ietf-ipsecme-ikev2-intermediate */
	/* 42, 44 - 239 Unassigned */
	/* 240 - 255 Private Use */

	/* libreswan private use */
	ISAKMP_XCHG_ECHOREQUEST_PRIVATE = 244, /* Private Echo Request */
	ISAKMP_XCHG_ECHOREPLY_PRIVATE = 245, /* Private Echo Reply */
};

/* ISAKMP header flag bits */
#define ISAKMP_FLAGS_v1_ENCRYPTION (1 << 0) /* bit 0 of flags - IKEv1 encrypt */
#define ISAKMP_FLAGS_v1_COMMIT (1 << 1) /* bit 1 of flags - IKEv1 commit - unused */
#define ISAKMP_FLAGS_v1_AUTH (1 << 2) /* bit 2 of flags - IKEv1 authonly - unused */
#define ISAKMP_FLAGS_v2_IKE_I (1 << 3) /* bit 3 of flags - IKEv2 Original Initiator */
#define ISAKMP_FLAGS_v2_VER (1 << 4) /* bit 4 of flags - IKEv2 Version flag */
#define ISAKMP_FLAGS_v2_MSG_R (1 << 5) /* bit 5 of flags - IKEv2 Message response */
#define ISAKMP_FLAGS_RESERVED_BIT6 (1 << 6) /* RESERVED */
#define ISAKMP_FLAGS_RESERVED_BIT7 (1 << 7) /* RESERVED */
extern const char *const isakmp_flag_names[];

/* IKEv2 header field sizes and offsets from the start of the header */
#define ADJ_LENGTH_SIZE 4
#define ADJ_LENGTH_OFFSET 24
#define EXCH_TYPE_OFFSET 18

/* SK payload header field sizes */
#define SK_HEADER_SIZE 4
#define ADJ_PAYLOAD_LENGTH_SIZE 2

/* Situation definition for IPsec DOI */
extern const char *const sit_bit_names[];

#define SIT_IDENTITY_ONLY 0x01
#define SIT_SECRECY 0x02
#define SIT_INTEGRITY 0x04

/*
 * See https://tools.ietf.org/html/rfc5996#section-3.2
 * Critical bit in each payload
 */
extern const char *const critical_names[];
#define ISAKMP_PAYLOAD_NONCRITICAL 0x00
#define ISAKMP_PAYLOAD_CRITICAL 0x80
/* These are followed by 7 more bits, currently RESERVED */
/* Note we use 1 of those bits for IMPAIR-SEND-BOGUS-ISAKMP-FLAG */
#define ISAKMP_PAYLOAD_LIBRESWAN_BOGUS 0x01

/*
 * Protocol IDs
 * RFC2407 The Internet IP security Domain of Interpretation for ISAKMP 4.4.1
 */

/*
 * extern enum_names protocol_names;
 */
#define PROTO_RESERVED 0
#define PROTO_ISAKMP 1
#define PROTO_IPSEC_AH 2
#define PROTO_IPSEC_ESP 3
#define PROTO_IPCOMP 4 /* only in IKEv1 */

/*
 * IKEv2 Security Protocol Identifiers - RFC 5996
 *
 * https://www.iana.org/assignments/ikev2-parameters/ikev2-parameters.xhtml#ikev2-parameters-18
 *
 * According to the IKEv2 RFC, these values are stored in 'Protocol
 * ID' field of a payload (see: 3.3.1.  Proposal Substructure; 3.10.
 * Notify Payload; 3.11.  Delete Payload).
 *
 * The value '0' is a little odd.  While IANA lists it as Reserved, a
 * notify payload must use that value for notifications that do not
 * include an SPI.  Hence 'NONE' is used.
 */
enum ikev2_sec_proto_id {
	IKEv2_SEC_PROTO_NONE = 0,
#define PROTO_v2_RESERVED IKEv2_SEC_PROTO_NONE
	IKEv2_SEC_PROTO_IKE = 1,
	IKEv2_SEC_PROTO_AH = 2,
#define PROTO_v2_AH IKEv2_SEC_PROTO_AH
	IKEv2_SEC_PROTO_ESP = 3,
#define PROTO_v2_ESP IKEv2_SEC_PROTO_ESP
	IKEv2_SEC_FC_ESP_HEADER = 4, /* RFC 4595 */
	IKEv2_SEC_FC_CT_AUTHENTICATION = 5, /* RFC 4595 */
	/* 6 - 200 Unassigned */
	/* 201 - 255 Private use */
};

/*
 * IKEv2 proposal
 * See https://www.iana.org/assignments/ikev2-parameters
 * Assume indexing is [1..IKEv2_TRANS_TYPE_ROOF)
 */
enum ikev2_trans_type {
	IKEv2_TRANS_TYPE_ENCR = 1,
	IKEv2_TRANS_TYPE_PRF = 2,
	IKEv2_TRANS_TYPE_INTEG = 3,
	IKEv2_TRANS_TYPE_DH = 4, /* same as in IKEv1 */
	IKEv2_TRANS_TYPE_ESN = 5,

	IKEv2_TRANS_TYPE_ROOF
};

/*
 * IKE and ESP encryption algorithms (note iana lists two table columns for these)
 * https://www.iana.org/assignments/ikev2-parameters/ikev2-parameters.xhtml#ikev2-parameters-5
 * (TODO: rename this to ikev2_encr_esp_ike)
 */
enum ikev2_trans_type_encr {
	IKEv2_ENCR_reserved = 0,
	IKEv2_ENCR_DES_IV64 = 1,
	IKEv2_ENCR_DES = 2,
	IKEv2_ENCR_3DES = 3,
	IKEv2_ENCR_RC5 = 4,
	IKEv2_ENCR_IDEA = 5,
	IKEv2_ENCR_CAST = 6,
	IKEv2_ENCR_BLOWFISH = 7,
	IKEv2_ENCR_3IDEA = 8,
	IKEv2_ENCR_DES_IV32 = 9,
	IKEv2_ENCR_RES10 = 10,
	IKEv2_ENCR_NULL = 11,
	IKEv2_ENCR_AES_CBC = 12,
	IKEv2_ENCR_AES_CTR = 13,
	IKEv2_ENCR_AES_CCM_8 = 14,
	IKEv2_ENCR_AES_CCM_12 = 15,
	IKEv2_ENCR_AES_CCM_16 = 16,
	IKEv2_UNUSED_17 = 17,
	IKEv2_ENCR_AES_GCM_8 = 18,
	IKEv2_ENCR_AES_GCM_12 = 19,
	IKEv2_ENCR_AES_GCM_16 = 20,
	IKEv2_ENCR_NULL_AUTH_AES_GMAC = 21,
	IKEv2_RESERVED_IEEE_P1619_XTS_AES = 22,
	IKEv2_ENCR_CAMELLIA_CBC = 23,
	IKEv2_ENCR_CAMELLIA_CTR = 24,
	IKEv2_ENCR_CAMELLIA_CCM_A = 25, /* CAMELLIA_CCM_8 RFC 5529 */
	IKEv2_ENCR_CAMELLIA_CCM_B = 26, /* CAMELLIA_CCM_12 RFC 5529 */
	IKEv2_ENCR_CAMELLIA_CCM_C = 27, /* CAMELLIA_CCM_16 RFC 5529 */
	IKEv2_ENCR_CHACHA20_POLY1305 = 28, /* RFC7634 */

	IKEv2_ENCR_PSTATS_ROOF,

	/* 29 - 1023 Reserved to IANA */
	/* 1024 - 65535 Private Use */
	IKEv2_ENCR_SERPENT_CBC = 65004,
	IKEv2_ENCR_TWOFISH_CBC = 65005,
	IKEv2_ENCR_TWOFISH_CBC_SSH = 65289,
	IKEv2_ENCR_INVALID = 65536,
};

enum ikev2_trans_type_prf {
	IKEv2_PRF_HMAC_MD5 = 1, /* RFC2104 */
	IKEv2_PRF_HMAC_SHA1 = 2, /* RFC2104 */
	IKEv2_PRF_HMAC_TIGER = 3, /* RFC2104 */
	IKEv2_PRF_AES128_XCBC = 4, /* RFC4434 */
	IKEv2_PRF_HMAC_SHA2_256 = 5, /* RFC4868 */
	IKEv2_PRF_HMAC_SHA2_384 = 6, /* RFC4868 */
	IKEv2_PRF_HMAC_SHA2_512 = 7, /* RFC4868 */
	IKEv2_PRF_AES128_CMAC = 8, /* RFC4615 */
	IKEv2_PRF_9_INVALID = 9,

	IKEv2_PRF_PSTATS_ROOF,

	/* 9 - 1023 Reserved to IANA RFC4306 */
	/* 1024 - 65535 Private Use RFC4306 */
	IKEv2_PRF_INVALID = 65536
};

enum ikev2_trans_type_integ {
	IKEv2_AUTH_NONE = 0, /* RFC4306 */
	IKEv2_AUTH_HMAC_MD5_96 = 1, /* RFC2403 */
	IKEv2_AUTH_HMAC_SHA1_96 = 2, /* RFC2404 */
	IKEv2_AUTH_DES_MAC = 3, /* RFC4306 */
	IKEv2_AUTH_KPDK_MD5 = 4, /* RFC1826 */
	IKEv2_AUTH_AES_XCBC_96 = 5, /* RFC3566 */
	IKEv2_AUTH_HMAC_MD5_128 = 6, /* RFC4595 */
	IKEv2_AUTH_HMAC_SHA1_160 = 7, /* RFC4595 */
	IKEv2_AUTH_AES_CMAC_96 = 8, /* RFC4494 */
	IKEv2_AUTH_AES_128_GMAC = 9, /* RFC4543 */
	IKEv2_AUTH_AES_192_GMAC = 10, /* RFC4543 */
	IKEv2_AUTH_AES_256_GMAC = 11, /* RFC4543 */
	IKEv2_AUTH_HMAC_SHA2_256_128 = 12, /* RFC4595 */
	IKEv2_AUTH_HMAC_SHA2_384_192 = 13, /* RFC4306 */
	IKEv2_AUTH_HMAC_SHA2_512_256 = 14, /* RFC4306 */

	IKEv2_AUTH_PSTATS_ROOF,

	/* 15 - 1023 Reserved to IANA RFC4306 */
	/* 1024 - 65535 Private Use RFC4306 */
	IKEv2_AUTH_INVALID = 65536
};

enum ikev2_trans_type_esn {
	IKEv2_ESN_DISABLED = 0,
	IKEv2_ESN_ENABLED = 1,
};

/*
 * RFC 4306 Section 3.3.5
 * Interestingly, there is only one attribute defined.
 */
enum ikev2_trans_attr_type {
	IKEv2_KEY_LENGTH = 14,	/* note: == OAKLEY_KEY_LENGTH */
};

/* RFC 5966 Section 3.13.1 */
enum ikev2_ts_type {
	/* 0-6 RESERVED */
	IKEv2_TS_IPV4_ADDR_RANGE = 7,
	IKEv2_TS_IPV6_ADDR_RANGE = 8,
	IKEv2_TS_FC_ADDR_RANGE = 9, /* RFC4595, not implemented */
	/* 10-240 Unassigned */
	/* 241-255 Private use */
};

#define KEY_IKE 1

/* the following are from RFC 2393/draft-shacham-ippcp-rfc2393bis-05.txt 3.3 */
typedef uint16_t cpi_t;
#define IPCOMP_CPI_SIZE 2
#define IPCOMP_FIRST_NEGOTIATED 256
#define IPCOMP_LAST_NEGOTIATED 61439

/*
 * Oakley transform attributes
 * draft-ietf-ipsec-ike-01.txt appendix A
 * https://www.iana.org/assignments/ipsec-registry/ipsec-registry.xhtml#ipsec-registry-2
 */

enum ikev1_oakley_attr {
	OAKLEY_ATTR_undefined = 0,	/* not in standard */
	OAKLEY_ENCRYPTION_ALGORITHM = 1,
	OAKLEY_HASH_ALGORITHM = 2,
	OAKLEY_AUTHENTICATION_METHOD = 3,
	OAKLEY_GROUP_DESCRIPTION = 4,
	OAKLEY_GROUP_TYPE = 5,
	OAKLEY_GROUP_PRIME = 6, /* B/V */
	OAKLEY_GROUP_GENERATOR_ONE = 7, /* B/V */
	OAKLEY_GROUP_GENERATOR_TWO = 8, /* B/V */
	OAKLEY_GROUP_CURVE_A = 9, /* B/V */
	OAKLEY_GROUP_CURVE_B = 10, /* B/V */
	OAKLEY_LIFE_TYPE = 11,
	OAKLEY_LIFE_DURATION = 12, /* B/V */
	OAKLEY_PRF = 13,
	OAKLEY_KEY_LENGTH = 14,
	OAKLEY_FIELD_SIZE = 15,
	OAKLEY_GROUP_ORDER = 16, /* B/V */
	/* OAKLEY_BLOCK_SIZE = 17, */	/* ??? where does this come from? */
	/* 17-16383 Unassigned */
	/* 16384-32767 Reserved for private use */
};

/*
 * IPsec DOI attributes
 * RFC2407 The Internet IP security Domain of Interpretation for ISAKMP 4.5
 */

enum ikev1_ipsec_attr {
	SA_LIFE_TYPE = 1,
	SA_LIFE_DURATION = 2, /* B/V */
	GROUP_DESCRIPTION = 3,
	ENCAPSULATION_MODE = 4,
	AUTH_ALGORITHM = 5,
	KEY_LENGTH = 6,
	KEY_ROUNDS = 7,
	COMPRESS_DICT_SIZE = 8,
	COMPRESS_PRIVATE_ALG = 9, /* B/V */
	ECN_TUNNEL = 10, /*B*/ /*RFC 3168*/ /* Originally mistakenly grabbed for SECCTX */
		ECN_TUNNEL_or_old_SECCTX = ECN_TUNNEL,
	SECCTX = 32001, /* B/V */ /* chosen from private range as in RFC 2407 */
};

/*
 * SA Lifetime Type attribute
 * RFC2407 The Internet IP security Domain of Interpretation for ISAKMP 4.5
 * Default time specified in 4.5
 *
 * There are two defaults for IPSEC SA lifetime, SA_LIFE_DURATION_DEFAULT,
 * and PLUTO_SA_LIFE_DURATION_DEFAULT.
 * SA_LIFE_DURATION_DEFAULT is specified in RFC2407 "The Internet IP
 * Security Domain of Interpretation for ISAKMP" 4.5. It applies when
 * an ISAKMP negotiation does not explicitly specify a life duration.
 */

#define SA_LIFE_TYPE_SECONDS 1
#define SA_LIFE_TYPE_KBYTES 2

/* Encapsulation Mode attribute */

#define ENCAPSULATION_MODE_UNSPECIFIED 0 /* not legal -- used internally */
#define ENCAPSULATION_MODE_TUNNEL 1
#define ENCAPSULATION_MODE_TRANSPORT 2
#define ENCAPSULATION_MODE_UDP_TUNNEL_RFC 3
#define ENCAPSULATION_MODE_UDP_TRANSPORT_RFC 4
#define ENCAPSULATION_MODE_UDP_TUNNEL_DRAFTS 61443
#define ENCAPSULATION_MODE_UDP_TRANSPORT_DRAFTS 61444

/* Auth Algorithm attribute */
/* https://www.iana.org/assignments/isakmp-registry/isakmp-registry.xml#isakmp-registry-20 */
enum ikev1_auth_attribute {
	AUTH_ALGORITHM_NONE = 0, /* our private designation */
	AUTH_ALGORITHM_HMAC_MD5 = 1,
	AUTH_ALGORITHM_HMAC_SHA1 = 2,
	AUTH_ALGORITHM_DES_MAC = 3,
	AUTH_ALGORITHM_KPDK = 4,
	AUTH_ALGORITHM_HMAC_SHA2_256 = 5,	/* not in an rfc? */
	AUTH_ALGORITHM_HMAC_SHA2_384 = 6,	/* not in an rfc? */
	AUTH_ALGORITHM_HMAC_SHA2_512 = 7,	/* not in an rfc? */
	AUTH_ALGORITHM_HMAC_RIPEMD = 8,	/* RFC 2857 */
	AUTH_ALGORITHM_AES_XCBC = 9,	/* RFC 3566 */
	AUTH_ALGORITHM_SIG_RSA = 10,	/* RFC 4359 */
	AUTH_ALGORITHM_AES_128_GMAC = 11,	/* RFC 4542 */
	AUTH_ALGORITHM_AES_192_GMAC = 12,	/* RFC 4542 */
	AUTH_ALGORITHM_AES_256_GMAC =  13,	/* RFC 4542 */

	AUTH_ALGORITHM_PSTATS_ROOF,

	/* 14-61439 Unassigned */
	/* 61440-65535 Reserved for private use */

	AUTH_ALGORITHM_AES_CMAC_96 = 250,  /* IKEv2==8 */
	AUTH_ALGORITHM_NULL_KAME = 251,	/* why do we load this ? */
	AUTH_ALGORITHM_HMAC_SHA2_256_TRUNCBUG = 252,
};

typedef uint16_t ipsec_auth_t;

/*
 * Oakley Lifetime Type attribute
 * draft-ietf-ipsec-ike-01.txt appendix A
 * As far as I can see, there is no specification for
 * OAKLEY_ISAKMP_SA_LIFETIME_DEFAULT. This could lead to interop problems!
 * For no particular reason, we chose one hour.
 * The value of OAKLEY_ISAKMP_SA_LIFETIME_MAXIMUM is our local policy.
 */

#define OAKLEY_LIFE_SECONDS 1
#define OAKLEY_LIFE_KILOBYTES 2

/*
 * Oakley PRF attribute (none defined)
 * draft-ietf-ipsec-ike-01.txt appendix A
 */

/*
 * HMAC
 * - see RFC 2104 for the definition of the HMAC procedure for early hash algorithms
 * - see RFC 4868 for how to construct HMAC for SHA2 functions
 */
#define HMAC_IPAD 0x36
#define HMAC_OPAD 0x5C

/*
 * Largest HMAC hash function blocksize ("B" in RFC 2104).
 *
 * Needs to be a compile-time constant for array allocation.
 * Must be as large as the largest value that appears in a
 * struct hash_desc's hash_block_size field.
 */
#define MAX_HMAC_BLOCKSIZE	128	/* RFC 4868 specifies this for SHA512 */

/*
 * IKEv1 Oakley Encryption Algorithm attribute
 * https://www.iana.org/assignments/ipsec-registry/ipsec-registry.xhtml#ipsec-registry-4
 */

enum ikev1_encr_attribute  {
	OAKLEY_DES_CBC = 1,
	OAKLEY_IDEA_CBC  = 2,
	OAKLEY_BLOWFISH_CBC = 3,
	OAKLEY_RC5_R16_B64_CBC = 4,
	OAKLEY_3DES_CBC = 5,
	OAKLEY_CAST_CBC = 6,
	OAKLEY_AES_CBC = 7,
	OAKLEY_CAMELLIA_CBC = 8,

	/* remainder until private use are NOT official IKEv1 entries */
	OAKLEY_AES_CTR = 13, /* taken from IKEv2 */
	OAKLEY_AES_CCM_8 = 14,
	OAKLEY_AES_CCM_12 = 15,
	OAKLEY_AES_CCM_16 = 16,

	OAKLEY_AES_GCM_8 = 18,
	OAKLEY_AES_GCM_12 = 19,
	OAKLEY_AES_GCM_16 = 20,

	OAKLEY_CAMELLIA_CTR = 24,
	OAKLEY_CAMELLIA_CCM_A = 25,
	OAKLEY_CAMELLIA_CCM_B = 26,
	OAKLEY_CAMELLIA_CCM_C = 27,

	OAKLEY_ENCR_PSTATS_ROOF,

	/* private user numbers */
	OAKLEY_MARS_CBC = 65001,
	OAKLEY_RC6_CBC = 65002,
	OAKLEY_ID_65003 = 65003, /* unused - make enums easier */
	OAKLEY_SERPENT_CBC = 65004,
	OAKLEY_TWOFISH_CBC = 65005,
	OAKLEY_TWOFISH_CBC_SSH = 65289,
};

#define OAKLEY_ENCRYPT_MAX 65535 /* pretty useless :) */

/*
 * IKEv1 Oakley Hash Algorithm attribute
 * https://www.iana.org/assignments/ipsec-registry/ipsec-registry.xhtml#ipsec-registry-6
 */

typedef uint16_t oakley_hash_t;
enum ikev1_hash_attribute  {
	/* 0 reserved */
	OAKLEY_MD5 = 1,
	OAKLEY_SHA1 = 2,
	OAKLEY_TIGER = 3,
	OAKLEY_SHA2_256 = 4,
	OAKLEY_SHA2_384 = 5,
	OAKLEY_SHA2_512 = 6,

	OAKLEY_HASH_PSTATS_ROOF,
};
#define OAKLEY_HASH_MAX 9

/*
 * Oakley Authentication Method attribute
 * IANA: https://www.iana.org/assignments/ipsec-registry/ipsec-registry.xhtml#ipsec-registry-8
 * XAUTH: https://tools.ietf.org/html/draft-ietf-ipsec-isakmp-xauth-06
 * Hybrid: https://tools.ietf.org/html/draft-ietf-ipsec-isakmp-hybrid-auth-05
 */

enum ikev1_auth_method {
	OAKLEY_PRESHARED_KEY = 1,
	OAKLEY_DSS_SIG = 2,
	OAKLEY_RSA_SIG = 3,
	OAKLEY_RSA_ENC = 4,

	OAKLEY_AUTH_ROOF,
	OAKLEY_AUTH_PSTATS_ROOF = OAKLEY_AUTH_ROOF,	/* we only support methods above */

	OAKLEY_RSA_REVISED_MODE = 5, /* Not implemented */
	/* 6 - 8 Reserved */
	OAKLEY_ECDSA_P256 = 9, /* RFC 4754 */
	OAKLEY_ECDSA_P384 = 10, /* RFC 4754 */
	OAKLEY_ECDSA_P521 = 11, /* RFC 4754 */
	/* 12 - 65000 Unassigned */
	OAKLEY_AUTH_NULL = 13, /* draft-ietf-ipsecme-ikev2-null-auth */
	/*
	 * Note: the below xauth names are mapped via xauth_calcbaseauth()
	 * to the base functions 1-4
	 */
	HybridInitRSA = 64221,
	HybridRespRSA = 64222,
	HybridInitDSS = 64223,
	HybridRespDSS = 64224,
	/* For XAUTH.  Don't actually store in st->st_oakley.auth (???) */
	XAUTHInitPreShared = 65001,
	XAUTHRespPreShared = 65002,
	XAUTHInitDSS = 65003,
	XAUTHRespDSS = 65004,
	XAUTHInitRSA = 65005,
	XAUTHRespRSA = 65006,
	XAUTHInitRSAEncryption = 65007,
	XAUTHRespRSAEncryption = 65008,
	XAUTHInitRSARevisedEncryption = 65009,
	XAUTHRespRSARevisedEncryption = 65010,
};


/* typedef to make our life easier */
typedef uint16_t oakley_auth_t;

enum ikev2_cp_attribute_type {
	/*
	 * IKEv2 CP Attribute types
	 * https://www.iana.org/assignments/ikev2-parameters/ikev2-parameters.xhtml#ikev2-parameters-21
	 */
	IKEv2_CP_ATTR_RESERVED = 0,
	IKEv2_INTERNAL_IP4_ADDRESS = 1,
	IKEv2_INTERNAL_IP4_NETMASK = 2,
	IKEv2_INTERNAL_IP4_DNS = 3,
	IKEv2_INTERNAL_IP4_NBNS = 4 /* unused by us, WINS is long dead */,
	IKEv2_RESERVED_5 = 5,
	IKEv2_INTERNAL_IP4_DHCP = 6,
	IKEv2_APPLICATION_VERSION = 7,
	IKEv2_INTERNAL_IP6_ADDRESS = 8,
	IKEv2_RESERVED_9 = 9,
	IKEv2_INTERNAL_IP6_DNS = 10,
	IKEv2_RESERVED_11 = 11,
	IKEv2_INTERNAL_IP6_DHCP  =12,
	IKEv2_INTERNAL_IP4_SUBNET = 13,
	IKEv2_SUPPORTED_ATTRIBUTES = 14,
	IKEv2_INTERNAL_IP6_SUBNET = 15,
	IKEv2_MIP6_HOME_PREFIX = 16,
	IKEv2_INTERNAL_IP6_LINK = 17,
	IKEv2_INTERNAL_IP6_PREFIX = 18,
	IKEv2_HOME_AGENT_ADDRESS = 19,
	IKEv2_P_CSCF_IP4_ADDRESS = 20,
	IKEv2_P_CSCF_IP6_ADDRESS = 21,
	IKEv2_FTT_KAT = 22,
	IKEv2_EXTERNAL_SOURCE_IP4_NAT_INFO = 23,
	IKEv2_TIMEOUT_PERIOD_FOR_LIVENESS_CHECK = 24,
	IKEv2_INTERNAL_DNS_DOMAIN = 25,
	IKEv2_INTERNAL_DNSSEC_TA = 26
};


/* extern enum_names ikev2_cp_names; */
enum ikev2_cp_type {
	IKEv2_CP_CFG_REQUEST = 1,
	IKEv2_CP_CFG_REPLY = 2,
	IKEv2_CP_CFG_SET = 3,
	IKEv2_CP_CFG_ACK = 4
};

/*
 * extern enum_names ikev2_auth_names;
 * https://www.iana.nl/assignments/ikev2-parameters/ikev2-parameters.xhtml
 * IKEv2 Authentication Method
 */

enum ikev2_auth_method {
	IKEv2_AUTH_RESERVED = 0,
	IKEv2_AUTH_RSA = 1,
	IKEv2_AUTH_PSK = 2,
	IKEv2_AUTH_DSA = 3,
	/* 4 - 8 unassigned */
	IKEv2_AUTH_P256 = 9, /* RFC 4754 */
	IKEv2_AUTH_P384 = 10, /* RFC 4754 */
	IKEv2_AUTH_P521 = 11, /* RFC 4754 */
	IKEv2_AUTH_GSPM = 12, /* RFC 6467 */
	IKEv2_AUTH_NULL = 13, /* draft-ietf-ipsecme-ikev2-null-auth */
	IKEv2_AUTH_DIGSIG = 14, /* RFC 7427 */
	/* 15 - 200 unassigned */
	/* 201 - 255 private use */
};

/*
 * Oakley Group Description attribute
 * draft-ietf-ipsec-ike-01.txt appendix A
 */
typedef enum ike_trans_type_dh oakley_group_t;

/*	you must also touch: constants.c, crypto.c */
/* https://www.iana.org/assignments/ipsec-registry/ipsec-registry.xhtml#ipsec-registry-10 */
/* https://www.iana.org/assignments/ikev2-parameters/ikev2-parameters.xhtml#ikev2-parameters-8 */
enum ike_trans_type_dh {
	OAKLEY_GROUP_NONE = 0,	/* RFC 7296 */
	OAKLEY_GROUP_MODP768 = 1,
	OAKLEY_GROUP_MODP1024 = 2,
	OAKLEY_GROUP_GP155 = 3, /* IKEv2 reserved */
	OAKLEY_GROUP_GP185 = 4, /* IKEv2 reserved */
	OAKLEY_GROUP_MODP1536 = 5, /* RFC 3526 */
	OAKLEY_GROUP_EC2N_2_1 = 6, /* draft-ietf-ipsec-ike-ecc-groups - IKEv2 reserved */
	OAKLEY_GROUP_EC2N_2_2 = 7, /* draft-ietf-ipsec-ike-ecc-groups - IKEv2 reserved */
	OAKLEY_GROUP_EC2N_2_3 = 8, /* draft-ietf-ipsec-ike-ecc-groups - IKEv2 reserved */
	OAKLEY_GROUP_EC2N_2_4 = 9, /* draft-ietf-ipsec-ike-ecc-groups - IKEv2 reserved */
	OAKLEY_GROUP_EC2N_2_5 = 10, /* draft-ietf-ipsec-ike-ecc-groups - IKEv2 reserved */
	OAKLEY_GROUP_EC2N_2_6 = 11, /* draft-ietf-ipsec-ike-ecc-groups - IKEv2 reserved */
	OAKLEY_GROUP_EC2N_2_7 = 12, /* draft-ietf-ipsec-ike-ecc-groups - IKEv2 reserved */
	OAKLEY_GROUP_EC2N_2_8 = 13, /* draft-ietf-ipsec-ike-ecc-groups - IKEv2 reserved */
	OAKLEY_GROUP_MODP2048 = 14, /* RFC 3526 */
	OAKLEY_GROUP_MODP3072 = 15, /* RFC 3526 */
	OAKLEY_GROUP_MODP4096 = 16, /* RFC 3526 */
	OAKLEY_GROUP_MODP6144 = 17, /* RFC 3526 */
	OAKLEY_GROUP_MODP8192 = 18, /* RFC 3526 */
	OAKLEY_GROUP_ECP_256 = 19, /* RFC 5903 */
	OAKLEY_GROUP_ECP_384 = 20, /* RFC 5903 */
	OAKLEY_GROUP_ECP_521 = 21, /* RFC 5903 */
	OAKLEY_GROUP_DH22 = 22, /* RFC 5114 */
	OAKLEY_GROUP_DH23 = 23, /* RFC 5114 */
	OAKLEY_GROUP_DH24 = 24, /* RFC 5114 */
	OAKLEY_GROUP_ECP_192 = 25, /* RFC 5114 */
	OAKLEY_GROUP_ECP_224 = 26, /* RFC 5114 */
	/* From here on, values are only valid for IKEv2 */
	OAKLEY_GROUP_BRAINPOOL_P224R1 = 27, /* RFC 6932 */
	OAKLEY_GROUP_BRAINPOOL_P256R1 = 28, /* RFC 6932 */
	OAKLEY_GROUP_BRAINPOOL_P384R1 = 29, /* RFC 6932 */
	OAKLEY_GROUP_BRAINPOOL_P512R1 = 30, /* RFC 6932 */
	OAKLEY_GROUP_CURVE25519 = 31, /* RFC-ietf-ipsecme-safecurves-05 */
	OAKLEY_GROUP_CURVE448 = 32, /* RFC-ietf-ipsecme-safecurves-05 */

	OAKLEY_GROUP_PSTATS_ROOF

	/* 33 - 32767 Unassigned */
	/* 32768 - 65535 Reserved for private use */
};
/*
 * Oakley Group Type attribute
 * draft-ietf-ipsec-ike-01.txt appendix A
 */
#define OAKLEY_GROUP_TYPE_MODP 1
#define OAKLEY_GROUP_TYPE_ECP 2
#define OAKLEY_GROUP_TYPE_EC2N 3

/*
 * Notify messages -- error types
 * See RFC2408 ISAKMP 3.14.1
 */

/*
 * IKEv1 RFC2408 https://www.iana.org/assignments/ipsec-registry
 * extern enum_names notification_names;
 * extern enum_names ipsec_notification_names;
 */
typedef enum {
	NOTHING_WRONG = 0, /* Unofficial! Must be zero to match default C initial value. */
	INVALID_PAYLOAD_TYPE = 1,
	DOI_NOT_SUPPORTED = 2,
	SITUATION_NOT_SUPPORTED = 3,
	INVALID_COOKIE = 4,
	INVALID_MAJOR_VERSION = 5,
	INVALID_MINOR_VERSION = 6,
	INVALID_EXCHANGE_TYPE = 7,
	INVALID_FLAGS = 8,
	INVALID_MESSAGE_ID = 9,
	INVALID_PROTOCOL_ID = 10,
	INVALID_SPI = 11,
	INVALID_TRANSFORM_ID = 12,
	ATTRIBUTES_NOT_SUPPORTED = 13,
	NO_PROPOSAL_CHOSEN = 14,
	BAD_PROPOSAL_SYNTAX = 15,
	PAYLOAD_MALFORMED = 16,
	INVALID_KEY_INFORMATION = 17,
	INVALID_ID_INFORMATION = 18,
	INVALID_CERT_ENCODING = 19,
	INVALID_CERTIFICATE = 20,
	CERT_TYPE_UNSUPPORTED = 21,
	INVALID_CERT_AUTHORITY = 22,
	INVALID_HASH_INFORMATION = 23,
	AUTHENTICATION_FAILED = 24,
	INVALID_SIGNATURE = 25,
	ADDRESS_NOTIFICATION = 26,
	NOTIFY_SA_LIFETIME = 27,
	CERTIFICATE_UNAVAILABLE = 28,
	UNSUPPORTED_EXCHANGE_TYPE = 29,
	UNEQUAL_PAYLOAD_LENGTHS = 30,

	v1N_ERROR_PSTATS_ROOF, /* used to cap statistics array */

	/* 31-8191 RESERVED (Future Use) */

	/*
	 * Sub-Registry: Notify Messages - Status Types (16384-24575)
	 */
	CONNECTED = 16384, /* INITIAL_CONTACT */

	/*
	 * IPSEC DOI additions; status types (RFC2407 IPSEC DOI 4.6.3)
	 * These must be sent under the protection of an ISAKMP SA.
	 */
	IPSEC_RESPONDER_LIFETIME = 24576,
	IPSEC_REPLAY_STATUS = 24577,
	IPSEC_INITIAL_CONTACT = 24578,

	/* Cisco specific messages */
	ISAKMP_N_CISCO_HELLO = 30000,
	ISAKMP_N_CISCO_WWTEBR = 30001,
	ISAKMP_N_CISCO_SHUT_UP = 30002,

	ISAKMP_N_IOS_KEEP_ALIVE_REQ = 32768,
	ISAKMP_N_IOS_KEEP_ALIVE_ACK = 32769,

	ISAKMP_N_CISCO_LOAD_BALANCE = 40501,
	ISAKMP_N_CISCO_UNKNOWN_40502 = 40502,
	ISAKMP_N_CISCO_PRESHARED_KEY_HASH = 40503,

	/* RFC 3706 DPD */
	R_U_THERE = 36136,
	R_U_THERE_ACK = 36137,

	/*
	 * Netscreen / Juniper private use - notification contains
	 * internal ip
	 */
	NETSCREEN_NHTB_INFORM = 40001,
} notification_t;

/*
 * https://www.iana.org/assignments/ikev2-parameters/ikev2-parameters.xml#ikev2-parameters-13
 * IKEv2 is very similar, but different. Let's not re-use and confuse
 **/
typedef enum {
	/* IKEv2 */
	/* 0-8191 Reserved, ExpertReview */
	v2N_NOTHING_WRONG = 0, /* Unofficial! Must be zero to match default C initial value. */

	/*
	 * Error notifications.
	 */
	v2N_ERROR_FLOOR = 1,
	v2N_UNSUPPORTED_CRITICAL_PAYLOAD = 1,
	/* Reserved = 2, */
	/* Reserved = 3, */
	v2N_INVALID_IKE_SPI = 4,
	v2N_INVALID_MAJOR_VERSION = 5, /* same as ikev1 */
	/* Reserved = 6, */
	v2N_INVALID_SYNTAX = 7,
	/* Reserved = 8, */
	v2N_INVALID_MESSAGE_ID = 9, /* same as ikev1 */
	/* Reserved = 10, */
	v2N_INVALID_SPI = 11, /* same as ikev1 */
	/* Reserved = 12, */
	/* Reserved = 13, */
	v2N_NO_PROPOSAL_CHOSEN = 14, /* same as ikev1 */
	/* Reserved = 15, */
	/* Reserved = 16, */
	v2N_INVALID_KE_PAYLOAD = 17,
	/* Reserved = 18 to 23, */
	v2N_AUTHENTICATION_FAILED = 24, /* same as ikev1 */
	/* Reserved = 25 to 33, */
	v2N_SINGLE_PAIR_REQUIRED = 34,
	v2N_NO_ADDITIONAL_SAS = 35,
	v2N_INTERNAL_ADDRESS_FAILURE = 36,
	v2N_FAILED_CP_REQUIRED = 37,
	v2N_TS_UNACCEPTABLE = 38,
	v2N_INVALID_SELECTORS = 39,
	v2N_UNACCEPTABLE_ADDRESSES = 40,
	v2N_UNEXPECTED_NAT_DETECTED = 41,
	v2N_USE_ASSIGNED_HoA = 42, /* RFC 5026 */
	v2N_TEMPORARY_FAILURE = 43, /* RFC 7296 */
	v2N_CHILD_SA_NOT_FOUND = 44, /* RFC 7296 */
	v2N_INVALID_GROUP_ID = 45, /* draft-yeung-g-ikev2 */
	v2N_AUTHORIZATION_FAILED = 46, /* draft-yeung-g-ikev2 */

	v2N_ERROR_PSTATS_ROOF, /* used to cap error statistics array */

	/*
	 * Status notifications.
	 */
	v2N_STATUS_FLOOR = 16384,

	/* old IKEv1 entries - might be in private use for IKEv2N */
	v2N_INITIAL_CONTACT = 16384,
	v2N_SET_WINDOW_SIZE = 16385,
	v2N_ADDITIONAL_TS_POSSIBLE = 16386,
	v2N_IPCOMP_SUPPORTED = 16387,
	v2N_NAT_DETECTION_SOURCE_IP = 16388,
	v2N_NAT_DETECTION_DESTINATION_IP = 16389,
	v2N_COOKIE = 16390,
	v2N_USE_TRANSPORT_MODE = 16391,
	v2N_HTTP_CERT_LOOKUP_SUPPORTED = 16392,
	v2N_REKEY_SA = 16393,
	v2N_ESP_TFC_PADDING_NOT_SUPPORTED = 16394,
	v2N_NON_FIRST_FRAGMENTS_ALSO = 16395,

	/* IKEv2N extensions */
	v2N_MOBIKE_SUPPORTED = 16396, /* RFC-4555 */
	v2N_ADDITIONAL_IP4_ADDRESS = 16397, /* RFC-4555 */
	v2N_ADDITIONAL_IP6_ADDRESS = 16398, /* RFC-4555 */
	v2N_NO_ADDITIONAL_ADDRESSES = 16399, /* RFC-4555 */
	v2N_UPDATE_SA_ADDRESSES = 16400, /* RFC-4555 */
	v2N_COOKIE2 = 16401, /* RFC-4555 */
	v2N_NO_NATS_ALLOWED = 16402, /* RFC-4555 */
	v2N_AUTH_LIFETIME = 16403, /* RFC-4478 */
	v2N_MULTIPLE_AUTH_SUPPORTED = 16404, /* RFC-4739 */
	v2N_ANOTHER_AUTH_FOLLOWS = 16405, /* RFC-4739 */
	v2N_REDIRECT_SUPPORTED = 16406, /* RFC-5685 */
	v2N_REDIRECT = 16407, /* RFC-5685 */
	v2N_REDIRECTED_FROM = 16408, /* RFC-5685 */
	v2N_TICKET_LT_OPAQUE = 16409, /* RFC-5723 */
	v2N_TICKET_REQUEST = 16410, /* RFC-5723 */
	v2N_TICKET_ACK = 16411, /* RFC-5723 */
	v2N_TICKET_NACK = 16412, /* RFC-5723 */
	v2N_TICKET_OPAQUE = 16413, /* RFC-5723 */
	v2N_LINK_ID = 16414, /* RFC-5739 */
	v2N_USE_WESP_MODE = 16415, /* RFC-5840 */
	v2N_ROHC_SUPPORTED = 16416, /* RFC-5857 */
	v2N_EAP_ONLY_AUTHENTICATION = 16417, /* RFC-5998 */
	v2N_CHILDLESS_IKEV2_SUPPORTED = 16418, /* RFC-6023 */
	v2N_QUICK_CRASH_DETECTION = 16419, /* RFC-6290 */
	v2N_IKEV2_MESSAGE_ID_SYNC_SUPPORTED = 16420, /* RFC-6311 */
	v2N_IPSEC_REPLAY_COUNTER_SYNC_SUPPORTED = 16421, /* RFC-6311 */
	v2N_IKEV2_MESSAGE_ID_SYNC = 16422, /* RFC-6311 */
	v2N_IPSEC_REPLAY_COUNTER_SYNC = 16423, /* RFC-6311 */
	v2N_SECURE_PASSWORD_METHODS = 16424, /* RFC-6467 */
	v2N_PSK_PERSIST = 16425, /* RFC-6631 */
	v2N_PSK_CONFIRM = 16426, /* RFC-6631 */
	v2N_ERX_SUPPORTED = 16427, /* RFC-6867 */
	v2N_IFOM_CAPABILITY = 16428, /* 3GPP TS 24.303 v10.6.0 annex B.2 */
	v2N_SENDER_REQUEST_ID = 16429, /* draft-yeung-g-ikev2 */
	v2N_IKEV2_FRAGMENTATION_SUPPORTED = 16430, /* RFC-7383 */
	v2N_SIGNATURE_HASH_ALGORITHMS = 16431, /* RFC-7427 */
	v2N_CLONE_IKE_SA_SUPPORTED = 16432, /* RFC-7791 */
	v2N_CLONE_IKE_SA = 16433, /* RFC-7791 */
	v2N_PUZZLE = 16434, /* RFC-8019 */
	v2N_USE_PPK = 16435, /* draft-ietf-ipsecme-qr-ikev2 */
	v2N_PPK_IDENTITY = 16436, /* draft-ietf-ipsecme-qr-ikev2 */
	v2N_NO_PPK_AUTH = 16437, /* draft-ietf-ipsecme-qr-ikev2 */
	v2N_INTERMEDIATE_EXCHANGE_SUPPORTED = 16438, /* draft-ietf-ipsecme-ikev2-intermediate-04 */

	v2N_STATUS_PSTATS_ROOF, /* used to cap status statistics array */

	/* 16438 - 40959 Unassigned */

	/* 40960 - 65535 Private Use */

	v2N_NULL_AUTH = 40960,

} v2_notification_t;

/* draft-ietf-ipsecme-qr-ikev2-01 created registry */
enum ppk_id_type {
	PPK_ID_OPAQUE = 1,
	PPK_ID_FIXED = 2,

	/* 3 - 127      Reserved for IANA */
	/* 128 - 255    Private Use */
};

/* IKEv2 Redirect Mechanism - RFC 5685 */
enum gw_identity_type {
	/* 0 - reserved */
	GW_IPV4 = 1,
	GW_IPV6 = 2,
	GW_FQDN = 3,

	/* 4 - 240	Unassigned */
	/* 241 - 255	Private Use */
};

#define MAX_REDIRECTS 5
#define REDIRECT_LOOP_DETECT_PERIOD 300

/* Public key algorithm number in IPSECKEY DNS RR. See RFC 4025 2.4 */
enum pubkey_alg {
	PUBKEY_ALG_DSA = 1,
	PUBKEY_ALG_RSA = 2,
	PUBKEY_ALG_ECDSA = 3,
};

/*
 * IKEv1 Identification type values
 * RFC 2407 The Internet IP security Domain of Interpretation for
 * ISAKMP 4.6.2.1
 * https://www.iana.org/assignments/isakmp-registry/isakmp-registry.xhtml#isakmp-registry-31
 *
 * IKEv2 Identification type values
 * RFC 5996
 * https://www.iana.org/assignments/ikev2-parameters/ikev2-parameters.xhtml#ikev2-parameters-10
 */

enum ike_id_type {
	ID_FROMCERT = -1,	/* taken from certificate - private to Pluto */
	ID_NONE = 0,	/* private to Pluto */

	ID_IPV4_ADDR = 1,
	ID_FQDN = 2,
	ID_USER_FQDN = 3,
	ID_RFC822_ADDR  = ID_USER_FQDN,	/* alias */
	ID_IPV4_ADDR_SUBNET = 4,	/* XXX IKEv1 only but we use it */
	ID_IPV6_ADDR = 5,
	ID_IPV6_ADDR_SUBNET = 6,	/* XXX IKEv1 only but we use it */
	ID_IPV4_ADDR_RANGE = 7,	/* XXX IKEv1 only but we use it */
	ID_IPV6_ADDR_RANGE = 8,	/* XXX IKEv1 only but we use it */
	ID_DER_ASN1_DN = 9,
	ID_DER_ASN1_GN = 10,
	ID_KEY_ID = 11,
	ID_FC_NAME = 12,	/* RFC 4595 */
	ID_NULL = 13, /* RFC 7619 */
	/* In IKEv1 registry, non-IKE value ID_LIST = 12 as per RFC 3554 */
	/* 14-248 Unassigned */
	/* 249-255 Reserved for private use */
};

/*
 * Certificate type values
 * RFC 2408 ISAKMP, chapter 3.9
 * https://tools.ietf.org/html/rfc2408#section-3.9
 * (no corresponding IANA registry?)
 *
 * IKEv2 Certificate Encodings
 * https://www.iana.org/assignments/ikev2-parameters/ikev2-parameters.xhtml#ikev2-parameters-11
 */
enum ike_cert_type {
	CERT_NONE = 0,	/* (non-RFC) none, or guess from file contents */
	CERT_PKCS7_WRAPPED_X509 = 1, /* self-signed certificate from disk */
	CERT_PGP = 2,
	CERT_DNS_SIGNED_KEY = 3, /* KEY RR from DNS */
	CERT_X509_SIGNATURE = 4,
	CERT_X509_KEY_EXCHANGE = 5,	/* v1 only */
	CERT_KERBEROS_TOKENS = 6,
	CERT_CRL = 7,
	CERT_ARL = 8,
	CERT_SPKI = 9,
	CERT_X509_ATTRIBUTE = 10,

	/* IKEv2 only from here */
	CERT_RAW_RSA = 11, /* raw RSA from config file */
	CERT_X509_CERT_URL = 12,
	CERT_X509_BUNDLE_URL = 13,
	CERT_OCSP_CONTENT = 14, /* RFC 4806 */
	CERT_RAW_PUBLIC_KEY = 15, /* RFC 7670 */
	/* 16 - 200 Unassigned */
	/* 201 - 255 Private use */
};

/*
 * (IKEv1) IPsec AH transform values
 *
 * IKEv1: https://www.iana.org/assignments/isakmp-registry/isakmp-registry.xhtml#isakmp-registry-7
 * IKEv2: https://www.iana.org/assignments/ikev2-parameters/ikev2-parameters.xhtml#ikev2-parameters-7
 *
 * IKEv1 and IKEv2 versions are very different :(
 * See: ikev2_trans_type_integ
 */
enum ipsec_authentication_algo {
	AH_NONE = 0, /* Internal use - IKEv1 is reserved */
	/* 1 IKEv1 RESERVED, IKEv2 AUTH_HMAC_MD5_96 */
	AH_MD5 = 2, /* IKEv2 AUTH_HMAC_SHA1_96 */
	AH_SHA = 3, /* IKEv2 AUTH_DES_MAC */
	AH_DES = 4, /* IKEv2 AUTH_KPDK_MD5 */
	AH_SHA2_256 = 5, /* IKEv2 AUTH_AES_XCBC_96 */
	AH_SHA2_384 = 6, /* IKEv2 AUTH_HMAC_MD5_128 */
	AH_SHA2_512 = 7, /* IKEv2 AUTH_HMAC_SHA1_160 */
	AH_RIPEMD = 8, /* IKEv2 AUTH_AES_CMAC_96 */
	AH_AES_XCBC_MAC = 9, /* IKEv2 AUTH_AES_128_GMAC */
	AH_RSA = 10, /* IKEv2 AUTH_AES_192_GMAC */
	AH_AES_128_GMAC = 11, /* IKEv2 AUTH_AES_256_GMAC */
	AH_AES_192_GMAC = 12, /* IKEv2 AUTH_HMAC_SHA2_256_128 */
	AH_AES_256_GMAC = 13, /* IKEv2 AUTH_HMAC_SHA2_384_192 */

	AH_PSTATS_ROOF,

	/* 14 IKEv1 unassigned, IKEv2 AUTH_HMAC_SHA2_512_256 */
	/* IKEv1 14-248 Unassigned */
	/* IKEv1 249 - 255 Reserved for private use */
	/* IKEv2 15-1023 Unassigned */
	/* IKEv2 1024 - 65535 Reserved for private use */
	AH_AES_CMAC_96 = 250,      /* IKEv2=8 */
	AH_NULL = 251,		/* comes from kame? */
	AH_SHA2_256_TRUNCBUG = 252,	/* our own stolen value */
};

/*
 * IKEv1 IPsec ESP transform values
 * IKEv1: https://www.iana.org/assignments/isakmp-registry/isakmp-registry.xhtml#isakmp-registry-9
 * IKEv2: https://www.iana.org/assignments/ikev2-parameters/ikev2-parameters.xhtml#ikev2-parameters-5
 *
 * Up to id=20 IKEv1 and IKEv2 match, after that things get messy.
 * This is because pluto and the kernel keep trying to use the IKEv1
 * ESP value when dealing with IKEv2-only algorithms.
 *
 * Where there is a conflict between IKEv1 and IKEv2, the IKEv1 value
 * is included.  If there's no IKEv1 value then the IKEv2 value is
 * used (should these be dropped).
 */

enum ipsec_cipher_algo {
	ESP_reserved = 0,
	ESP_DES_IV64 = 1,
	ESP_DES = 2,	/* obsoleted */
	ESP_3DES = 3,
	ESP_RC5 = 4,
	ESP_IDEA = 5,
	ESP_CAST = 6,
	ESP_BLOWFISH = 7,	/* obsoleyed */
	ESP_3IDEA = 8,
	ESP_DES_IV32 = 9,
	ESP_RC4 = 10,
	ESP_NULL = 11,
	ESP_AES = 12,	/* CBC 128 bit AES */
	ESP_AES_CTR = 13,
	ESP_AES_CCM_8 = 14,
	ESP_AES_CCM_12 = 15,
	ESP_AES_CCM_16 = 16,
	ESP_ID17 = 17,	/* unassigned=17 */
	ESP_AES_GCM_8 = 18,
	ESP_AES_GCM_12 = 19,
	ESP_AES_GCM_16 = 20,
	ESP_SEED_CBC = 21, /* IKEv1, IKEv2 is NULL_AUTH_AES_GMAC */
	ESP_CAMELLIA = 22, /* IKEv1, IKEv2 is ESP_RESERVED_FOR_IEEE_P1619_XTS_AES */
	ESP_NULL_AUTH_AES_GMAC = 23, /* IKEv1, IKEv2 is CAMELLIA_CBC */

	ESP_PSTATS_ROOF,

	ESP_CAMELLIA_CTR = 24, /* not assigned in/for IKEv1 */
	ESP_CAMELLIA_CCM_8 = 25, /* not assigned in/for IKEv1 */
	ESP_CAMELLIA_CCM_12 = 26, /* not assigned in/for IKEv1 */
	ESP_CAMELLIA_CCM_16 = 27, /* not assigned in/for IKEv1 */
	/* IKEv1: 24-248 Unassigned */
	/* IKEv1: 249-255 reserved for private use */
	/* IKEv2: 28-1023 Unassigned */
	/* IKEv2: 1024-65535 reserved for private use */
	ESP_MARS = 249,
	ESP_RC6 = 250,
	ESP_KAME_NULL = 251,	/* kame? */
	ESP_SERPENT = 252,
	ESP_TWOFISH = 253,
	ESP_ID254 = 254,
	ESP_ID255 = 255,
};

/*
 * IPCOMP transform values are (currently) identical for IKEv1 and IKEv2
 * IKEv1: RFC2407 The Internet IP security Domain of Interpretation for ISAKMP 4.4.5
 * IKEv2: https://www.iana.org/assignments/ikev2-parameters/ikev2-parameters.xhtml#ikev2-parameters-17
 */

enum ipsec_comp_algo {
	IPCOMP_NONE=0,
	IPCOMP_OUI=1, /* unspecified */
	IPCOMP_DEFLATE=2,
	IPCOMP_LZS=3, /* RFC 2395 */
	IPCOMP_LZJH=4, /* RFC 3051 */
	/* 5-47 Reserved for approved algorithms */
	/* 48-63 Reserved for private use */
	/* 64-255 Unassigned */
};

/*
 * Internet Key Exchange Version 2 (IKEv2) Parameters: IKEv2 Hash Algorithms
 * https://www.iana.org/assignments/ikev2-parameters/ikev2-parameters.xhtml#hash-algorithms
 *
 * Currently it is only used by RFC 7427 Signature Authentication in
 * the Internet Key Exchange Version 2.
 */

enum ikev2_hash_algorithm {
	IKEv2_HASH_ALGORITHM_RESERVED = 0,
	IKEv2_HASH_ALGORITHM_SHA1     = 1,
	IKEv2_HASH_ALGORITHM_SHA2_256 = 2,
	IKEv2_HASH_ALGORITHM_SHA2_384 = 3,
	IKEv2_HASH_ALGORITHM_SHA2_512 = 4,
	IKEv2_HASH_ALGORITHM_IDENTITY = 5, /* RFC 4307-bis */
	/* 6-1023 Unassigned */
	/* 1024-65535 Reserved for private use */
	IKEv2_HASH_ALGORITHM_ROOF
};

/*
 * RFC 7427: 4.  Hash Algorithm Notification
 *
 * The Notification Data field contains the list of 16-bit hash
 * algorithm identifiers from the Hash Algorithm Identifiers of IANA's
 * "Internet Key Exchange Version 2 (IKEv2) Parameters" registry.
 * There is no padding between the hash algorithm identifiers.
 */
#define RFC_7427_HASH_ALGORITHM_IDENTIFIER_SIZE 2

/*
 * RFC 7427 , section 3 describes the Authentication data format for
 * Digital Signatures.
 * ASN.1 Length (1 octet): length of ASN.1-encoded AlgorithmIdentifier object
 * Algorithm Identifier (variable length): The AlgorithmIdentifier ASN.1 object.
 */

/*
 * Size of algorithm RSASSA-PSS with SHA2 is 67 bytes for all its variants
 */
#define ASN1_SHA2_RSA_PSS_SIZE 67
/* length of ASN.1 Algorithm Identifier(variable length) is 1 byte */
#define ASN1_LEN_ALGO_IDENTIFIER 1

#define RSA_PSS_SHA256_BLOB \
	0x30, 0x41, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x0a, 0x30, 0x34, 0xa0,\
	0x0f, 0x30, 0x0d, 0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x05, 0x00,\
	0xa1, 0x1c, 0x30, 0x1a, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x08, 0x30,\
	0x0d, 0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x05, 0x00, 0xa2, 0x03,\
	0x02, 0x01, 0x20

#define RSA_PSS_SHA384_BLOB \
	0x30, 0x41, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x0A, 0x30, 0x34, 0xA0,\
	0x0F, 0x30, 0x0D, 0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x02, 0x05, 0x00,\
	0xA1, 0x1C, 0x30, 0x1A, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x08, 0x30,\
	0x0D, 0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x02, 0x05, 0x00, 0xA2, 0x03,\
	0x02, 0x01, 0x30

#define RSA_PSS_SHA512_BLOB \
	0x30, 0x41, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x0A, 0x30, 0x34, 0xA0,\
	0x0F, 0x30, 0x0D, 0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x03, 0x05, 0x00,\
	0xA1, 0x1C, 0x30, 0x1A, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x08, 0x30,\
	0x0D, 0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x03, 0x05, 0x00, 0xA2, 0x03,\
	0x02, 0x01, 0x40

#define LEN_RSA_PSS_SHA2_BLOB ASN1_SHA2_RSA_PSS_SIZE

/* RFC 7427 Appendix A.1 */

#define ASN1_SHA2_RSA_v15_SIZE 16 /* including one length byte prefix */
/* sha256WithRSAEncryption */
#define RSA_v15_SHA256_BLOB \
	0x0f, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x0b, 0x05, 0x00
/* sha384WithRSAEncryption */
#define RSA_v15_SHA384_BLOB \
	0x0f, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x0c, 0x05, 0x00
/* sha512WithRSAEncryption */
#define RSA_v15_SHA512_BLOB \
	0x0f, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x0d, 0x05, 0x00

/* ECDSA */
#define ASN1_SHA1_ECDSA_SIZE 11
#define ASN1_SHA2_ECDSA_SIZE 12

#define ECDSA_SHA1_BLOB \
	0x30, 0x09, 0x06, 0x07, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x04, 0x01

#define ECDSA_SHA256_BLOB \
	0x30, 0x0a, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x04, 0x03, 0x02

#define ECDSA_SHA384_BLOB \
	0x30, 0x0a, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x04, 0x03, 0x03

#define ECDSA_SHA512_BLOB \
	0x30, 0x0a, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x04, 0x03, 0x04

#define LEN_ECDSA_SHA1_BLOB ASN1_SHA1_ECDSA_SIZE

#define LEN_ECDSA_SHA2_BLOB ASN1_SHA2_ECDSA_SIZE

/* Limits on size of RSA moduli.
 * The upper bound matches that of DNSSEC (see RFC 2537).
 * The lower bound must be more than 11 octets for certain
 * the encoding to work, but it must be much larger for any
 * real security. For now, we require 512 bits.
 */

#define RSA_MIN_OCTETS_RFC 12

#define RSA_MIN_OCTETS BYTES_FOR_BITS(512)
#define RSA_MIN_OCTETS_UGH \
	"RSA modulus too small for security: less than 512 bits"

#define RSA_MAX_OCTETS BYTES_FOR_BITS(8192)
#define RSA_MAX_OCTETS_UGH "RSA modulus too large: more than 8192 bits"

/* Note: RFC 2537 encoding adds a few bytes. If you use a small
 * modulus like 3, the overhead is only 2 bytes
 */
#define RSA_MAX_ENCODING_BYTES (RSA_MAX_OCTETS + 2)

#define ISA_MAJ_SHIFT 4
#define ISA_MIN_MASK (~((~0u) << ISA_MAJ_SHIFT))

/* ISAKMP attributes are encoded with the Attribute Format field
 * and the Attribute Type field encoded in one pair of octets.
 * The AF is the high-order bit and the Type is the next 15 bits.
 * See RFC 2408 "ISAKMP" section 3.3.
 * The following definitions are used to pack and unpack these.
 */
#define ISAKMP_ATTR_AF_MASK 0x8000
#define ISAKMP_ATTR_AF_TV ISAKMP_ATTR_AF_MASK /* value in lv */
#define ISAKMP_ATTR_AF_TLV 0 /* length in lv; value follows */

#define ISAKMP_ATTR_RTYPE_MASK 0x7FFF

#endif /* _IETF_CONSTANTS_H */
