#ifndef __AARCH_H__
#define __AARCH_H__
#if defined(__linux__)

//inclusions
#include <stdio.h>
#include <ostream>
#include <dirent.h>
#include <filesystem>
#include <errno.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
    //gpg library
#include <gpgme.h>	//interface to gnupg

//macros
#define exit_if_err(err) \
	do { \
		if(err != GPG_ERR_NO_ERROR) { \
			fprintf(stderr, "%s:%d: %s: %s\n", __FILE__, \
				__LINE__, gpgme_strsource(err), gpgme_strerror(err)); \
			exit(1); \
		} \
	} while(0) \

#define TESKY_DEFAULT_PROTOCOL GPGME_PROTOCOL_OpenPGP
#define TESKY_DEFAULT_HASH GPGME_MD_SHA512
#define TESKY_DEFAULT_ALGO GPGME_PK_RSA_E
#define TESKY_DEFAULT_ARMORED 1
#define BUF_SIZE 512
//variables
    typedef gpgme_data_t tesky_data;                    //za prenos podataka
    typedef struct public_key
    {
        int id;
        char *uid;
        char *user_name;
        char *email;
        gpgme_protocol_t protocol;
        //char *data;
        struct public_key *next;
        struct public_key *last;
    }pubkey;
    typedef struct private_key
    {
        int id;
        char *uid;
        char *user_name;
        char *email;
        gpgme_protocol_t protocol;
        //char *data;
        struct private_key *next;
        struct private_key *last;
    }privkey;
    extern int n_pubkey;           //number of nodes in pubkey linked list
    extern int n_privkey;           //number of nodes in privkey linked list
    extern pubkey *pub_head_node;       //beginning of the pubkey linked list
    extern privkey *priv_head_node;     //beginning of the privkey linked list
    extern pubkey *pub_curr_key;        //holds selected public key
    extern privkey *priv_curr_key;      //holds selected private key
    extern gpgme_error_t err;  //err = funkc => if(err == GPGME_ERR...)
    extern gpgme_engine_info_t tesky_engine_info;
    extern gpgme_data_t ciphertext_for_dec;
    extern gpgme_data_t plaintext_for_enc;
    extern gpgme_key_t selected_pubkey;
    extern gpgme_key_t selected_privkey;
    extern gpgme_ctx_t tesky_ctx;    //configuration, status and result 
    extern int tesky_armored;
    //gpgme_off_t file_size;
    //gpgme_key_t pub_key;
    //gpgme_key_t priv_key;
    extern gpgme_pubkey_algo_t tesky_algorithm;
    extern gpgme_hash_algo_t tesky_hash;
    extern gpgme_protocol_t tesky_protocol;   //default protocol is OpenPGP
//function declarations
//information about platform
void tesky_aarch_info();
//check if the directory exists
bool tesky_directory_exists(char* pathname);
//initialize gpgme library
void tesky_init_gpgme();
//ctx
void tesky_init_ctx(gpgme_protocol_t protocol_passed=TESKY_DEFAULT_PROTOCOL, int armored_passed=TESKY_DEFAULT_ARMORED, gpgme_hash_algo_t hash_passed=TESKY_DEFAULT_HASH, gpgme_pubkey_algo_t algo_passed=TESKY_DEFAULT_ALGO);
void tesky_update_ctx(gpgme_protocol_t protocol_passed=TESKY_DEFAULT_PROTOCOL, gpgme_hash_algo_t hash_passed=TESKY_DEFAULT_HASH, gpgme_pubkey_algo_t algo_passed=TESKY_DEFAULT_ALGO);
void tesky_end_ctx();

//Key manipulation
void tesky_generate_new_keypair(const char *key_info);
void tesky_import_key(const char *pathname);
//void tesky_export_key();
//void delete_key();

//linkedlists manipulation
void tesky_init_keylists();
void tesky_add_to_pubkeylist(char *uid, char *user_name, char *email, gpgme_protocol_t protocol);
void tesky_add_to_privkeylist(char *uid, char *user_name, char *email, gpgme_protocol_t protocol);
void tesky_delete_from_pubkeylist();
void tesky_delete_from_privkeylist();
void tesky_print_publistkey();
void tesky_print_privlistkey();

//encrypt/decrypt
std::string tesky_encrypt_data(const char *buffer, size_t size);
std::string tesky_decrypt_data(const char *buffer, size_t size);
void tesky_load_pubkey();
void tesky_load_privkey();
std::string print_data(gpgme_data_t dh);
//mozda razdvoj na tekst i file metode

//finish
//  + inicijalizujes engine
//  + pokrenes ctx
//  + postavis protokol, algo i hash
//  - napravis buffer za podatke
//  - potrazis i ucitas u [:OPCIJA:] sve kljuceve iz .tesky
//      + odluci dal je OPCIJA -> 1. LINKEDLIST ili 2. STRING
//      + 1) ucitamo svaki kao node, sa ID-jem, filename, key_t ucitan...
//      - 2) samo ucitamo imena fajlova u string -> std::string += ":ime_pubkey_3"
//          - posle splitBy(":") i upisati u pub key listu
//          - problem jer necu znati kako da odaberem fajl koji je selektovan
//          - mozda moze da se dobije id selektovanog elementa -> for(i=0; i<id; i++)
//      + initialize linked list
//      + add to linked list
//      + delete from linked list sa ID
//      + odluci dal ces ucitati sve u linked listu ili samo filename pa load
//      + mozda samo ucitaj selektovane, pa kad promenimo prepisi
//  - mozes i da kreiras novi pub priv key genkey()
//  + podesis privkey
//  + podesis pubkey
//  - enkriptujes char* sa pubkeyom
//  - dekriptujes char* sa privkeyom
//  - enkriptujes fajl sa pubkeyom
//  - dekriptujes fajl sa privkeyom





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
#endif