#if defined(__linux__)

//inclusions
#include <stdio.h>
#include <ostream>
#include <dirent.h>
#include <filesystem>
#include <errno.h>
#include <stdlib.h>
#include <locale.h>
    //gpg library
#include <gpgme.h>	//interface to gnupg
//variables
    //gpgme_error_t err;  //err = funkc => if(err == GPGME_ERR...)
    //gpgme_data_t eng_data;  //user -> data -> engine
    //gpgme_ctx_t eng_ctx;    //configuration, status and result 
    //gpgme_off_t file_size;
    //gpgme_key_t pub_key;
    //gpgme_key_t priv_key;

//function declarations
void aarch_info();
bool directory_exists(char* pathname);
void init_gpgme();
void init_data();
#endif

/* ENCRYPTION
GPGME_PK_RSA
    This value indicates the RSA (Rivest, Shamir, Adleman) algorithm.
GPGME_PK_RSA_E
    Deprecated. This value indicates the RSA (Rivest, Shamir, Adleman) algorithm for encryption and decryption only.
GPGME_PK_RSA_S
    Deprecated. This value indicates the RSA (Rivest, Shamir, Adleman) algorithm for signing and verification only.
GPGME_PK_DSA
    This value indicates DSA, the Digital Signature Algorithm.
GPGME_PK_ELG
    This value indicates ElGamal.
GPGME_PK_ELG_E
    This value also indicates ElGamal and is used specifically in GnuPG.
GPGME_PK_ECC
    This value is a generic indicator for ellipic curve algorithms.
GPGME_PK_ECDSA
    This value indicates ECDSA, the Elliptic Curve Digital Signature Algorithm as defined by FIPS 186-2 and RFC-6637.
GPGME_PK_ECDH
    This value indicates ECDH, the Eliptic Curve Diffie-Hellmann encryption algorithm as defined by RFC-6637.
GPGME_PK_EDDSA
    This value indicates the EdDSA algorithm.
*/

/* HASH
GPGME_MD_MD5
GPGME_MD_SHA1
GPGME_MD_RMD160
GPGME_MD_MD2
GPGME_MD_TIGER
GPGME_MD_HAVAL
GPGME_MD_SHA256
GPGME_MD_SHA384
GPGME_MD_SHA512
GPGME_MD_SHA224
Since: 1.5.0
GPGME_MD_MD4
GPGME_MD_CRC32
GPGME_MD_CRC32_RFC1510
GPGME_MD_CRC24_RFC2440
*/

/* SELFTEST - GPG_ERR_SOURCE_UNKNOWN - proveri svaku od ovih za self test
GPG_ERR_SOURCE_UNKNOWN
GPG_ERR_SOURCE_GPGME
GPG_ERR_SOURCE_GPG
GPG_ERR_SOURCE_GPGSM
GPG_ERR_SOURCE_GCRYPT
GPG_ERR_SOURCE_GPGAGENT
GPG_ERR_SOURCE_PINENTRY
GPG_ERR_SOURCE_SCD
GPG_ERR_SOURCE_KEYBOX
GPG_ERR_SOURCE_USER_1
GPG_ERR_SOURCE_USER_2
GPG_ERR_SOURCE_USER_3
GPG_ERR_SOURCE_USER_4
*/

/* SELFTEST - GPG_ERR
GPG_ERR_EOF
GPG_ERR_NO_ERROR
GPG_ERR_GENERAL
GPG_ERR_ENOMEM
GPG_ERR_E...
GPG_ERR_INV_VALUE
GPG_ERR_UNUSABLE_PUBKEY
GPG_ERR_UNUSABLE_SECKEY
GPG_ERR_NO_DATA
GPG_ERR_CONFLICT
GPG_ERR_NOT_IMPLEMENTED
GPG_ERR_DECRYPT_FAILED
GPG_ERR_BAD_PASSPHRASE
GPG_ERR_CANCELED
GPG_ERR_INV_ENGINE
GPG_ERR_AMBIGUOUS_NAME
GPG_ERR_WRONG_KEY_USAGE
GPG_ERR_CERT_REVOKED
GPG_ERR_CERT_EXPIRED
GPG_ERR_NO_CRL_KNOWN
GPG_ERR_NO_POLICY_MATCH
GPG_ERR_NO_SECKEY
GPG_ERR_MISSING_CERT
GPG_ERR_BAD_CERT_CHAIN
GPG_ERR_UNSUPPORTED_ALGORITHM
GPG_ERR_BAD_SIGNATURE
GPG_ERR_NO_PUBKEY
*/
