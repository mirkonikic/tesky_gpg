#include "../include/crypter.h"

//gpgme_error_t err;
//gpgme_engine_info_t tesky_engine_info;
//gpgme_ctx_t tesky_ctx;
//int tesky_armored = 1;
//int n_pubkey = 0;
//int n_privkey = 0;
//pubkey *pub_head_node = nullptr;
//privkey *priv_head_node = nullptr;
//pubkey *pub_curr_key = nullptr;
//privkey *priv_curr_key = nullptr;
//gpgme_data_t ciphertext_for_dec;
//gpgme_data_t plaintext_for_enc;
//gpgme_key_t selected_pubkey;
//gpgme_key_t selected_privkey;
//gpgme_pubkey_algo_t tesky_algorithm;
//gpgme_hash_algo_t tesky_hash;
//gpgme_protocol_t tesky_protocol;


/*
	gpgme_error_t gpgme_op_genkey (gpgme_ctx_t ctx, const char *parms, gpgme_data_t public, gpgme_data_t secret)
The function gpgme_op_genkey generates a new key pair in the context ctx. The meaning of public and secret depends on the crypto backend.

GPG does not support public and secret, they should be NULL. GnuPG will generate a key pair and add it to the standard key ring. The fingerprint of the generated key is available with gpgme_op_genkey_result.

GpgSM requires public to be a writable data object. GpgSM will generate a secret key (which will be stored by gpg-agent, and return a certificate request in public, which then needs to be signed by the certification authority and imported before it can be used. GpgSM does not make the fingerprint available.

The argument parms specifies parameters for the key in an string that looks something like XML. The details about the format of parms are specific to the crypto engine used by ctx. The first line of the parameters must be <GnupgKeyParams format="internal"> and the last line must be </GnupgKeyParams>. Every line in between the first and last lines is treated as a Header: Value pair. In particular, no XML escaping is necessary if you need to include the characters <, >, or &.

Here is an example for GnuPG as the crypto engine (all parameters of OpenPGP key generation are documented in the GPG manual):

<GnupgKeyParms format="internal">
Key-Type: default
Subkey-Type: default
Name-Real: Joe Tester
Name-Comment: with stupid passphrase
Name-Email: joe@foo.bar
Expire-Date: 0
Passphrase: abc
</GnupgKeyParms>
Here is an example for GpgSM as the crypto engine (all parameters of OpenPGP key generation are documented in the GPGSM manual):

<GnupgKeyParms format="internal">
Key-Type: RSA
Key-Length: 1024
Name-DN: C=de,O=g10 code,OU=Testlab,CN=Joe 2 Tester
Name-Email: joe@foo.bar
</GnupgKeyParms>

*/







/*	Potrebno za kjluceve, al za svaki slucaj cuvam ovde
const char key_info[] = "<GnupgKeyParms format=\"internal\">\n"
						"Key-Type: default\n"
						"Subkey-Type: default\n"
						"Name-Real: Joe Tester\n"
						"Name-Comment: with stupid passphrase\n"
						"Name-Email: joe@foo.bar\n"
						"Expire-Date: 0\n"
						"Passphrase: abc\n"
						"</GnupgKeyParms>\n";
*/


Crypter::Crypter(){}

void Crypter::tesky_aarch_info(){printf("Operating system is: Linux :)\n");}

/*	Vise mi ne treba
bool tesky_directory_exists(char *pathname)
{
    std::string HOME = getenv("HOME");
    HOME += "/";
    HOME += pathname;
    DIR* dir = opendir(HOME.c_str());
    if (dir) return true || closedir(dir);   //closedir vraca 0 => 0 || 1 = 1
    //else if (ENOENT == errno) //its surely false
    return false;
}
*/

void Crypter::tesky_init_gpgme()
{
    printf("gpgme version: %s\n", gpgme_check_version(NULL));
	/* Initialize the locale environment. */
	setlocale (LC_ALL, "");
	gpgme_set_locale (NULL, LC_CTYPE, setlocale (LC_CTYPE, NULL));
	#ifdef LC_MESSAGES
		gpgme_set_locale (NULL, LC_MESSAGES, setlocale (LC_MESSAGES, NULL));
	#endif
	printf("protocol name: %s\n", gpgme_get_protocol_name(GPGME_PROTOCOL_OpenPGP));
	printf("homedir name: %s\n", gpgme_get_dirinfo("homedir"));
	printf("engine version: %d\n", gpgme_engine_check_version(GPGME_PROTOCOL_OpenPGP));
	printf("rsa value: %s\n", gpgme_pubkey_algo_name (GPGME_PK_RSA_E));
	printf("hash value: %s\n", gpgme_hash_algo_name (GPGME_MD_SHA512));

	//proveri dal radi engine
	exit_if_err(gpgme_get_engine_info(&tesky_engine_info));
	printf("file=%s, home=%s\n", tesky_engine_info->file_name, tesky_engine_info->home_dir);

	//Setting up default data
	tesky_protocol = TESKY_DEFAULT_PROTOCOL; 	//default protocol OpenPGP
	tesky_hash = TESKY_DEFAULT_HASH;			//default hash
	tesky_algorithm = TESKY_DEFAULT_ALGO;		//default algorithm
	tesky_armored = TESKY_DEFAULT_ARMORED;		//ASCII ARMORED JE PO DEFAULTU
}

//CTX methods
//void tesky_init_ctx(gpgme_protocol_t protocol_passed=TESKY_DEFAULT_PROTOCOL, gpgme_hash_algo_t hash_passed=TESKY_DEFAULT_HASH, gpgme_pubkey_algo_t algo_passed=TESKY_DEFAULT_ALGO)
void Crypter::tesky_init_ctx(gpgme_protocol_t protocol_passed, int armored_passed, gpgme_hash_algo_t hash_passed, gpgme_pubkey_algo_t algo_passed)
{
	tesky_protocol = protocol_passed;
	tesky_hash = hash_passed;
	tesky_algorithm = algo_passed;
	tesky_armored = armored_passed;
	//create new ctx
	exit_if_err(gpgme_new(&tesky_ctx));

	//set ctx protocol
	exit_if_err(gpgme_set_protocol(tesky_ctx, tesky_protocol));

	//start engine
	exit_if_err(gpgme_engine_check_version(tesky_protocol));

	//armor ascii
	gpgme_set_armor(tesky_ctx, 1);
	
	//set engine
	exit_if_err(gpgme_ctx_set_engine_info(tesky_ctx, tesky_protocol, tesky_engine_info->file_name, tesky_engine_info->home_dir));
	
	//initialize engine
	err = gpgme_get_engine_info(&tesky_engine_info);
	
}

void Crypter::tesky_update_ctx(gpgme_protocol_t protocol_passed, gpgme_hash_algo_t hash_passed, gpgme_pubkey_algo_t algo_passed)
{
	tesky_protocol = protocol_passed;
	tesky_hash = hash_passed;
	tesky_algorithm = algo_passed;

	//change protocol of context
	exit_if_err(gpgme_set_protocol(tesky_ctx, tesky_protocol));

	exit_if_err(gpgme_ctx_set_engine_info(tesky_ctx, tesky_protocol, tesky_engine_info->file_name, NULL));
}

void Crypter::tesky_end_ctx()
{
	gpgme_release(tesky_ctx);
}

std::string Crypter::tesky_ctx_get_protocol(){return gpgme_get_protocol_name(gpgme_get_protocol(tesky_ctx));}

//Key Manipulation methods
void Crypter::tesky_import_key(const char *pathname)
{
	printf("IMPORT: path: %s\n", pathname);
	//otvori file sa imenom pathname
	FILE *fp;
	gpgme_data_t key_data;
	gpgme_key_t key_imp;

	fp = fopen(pathname, "r");
	//prosledi file descriptor metodi ispod
	//al prvo proveri da li je moguce da bude kljuc
	tesky_init_ctx();
	
	gpgme_data_new_from_fd (&key_data, fileno(fp));
	
	gpgme_op_import (tesky_ctx, key_data);
	
	gpgme_import_result_t import_result = gpgme_op_import_result (tesky_ctx);
	if(import_result->imported == 0)
		printf("Nije hteo da importuje\n");
	else
	{
		if(import_result->secret_imported == 0){
			gpgme_get_key (tesky_ctx, import_result->imports->fpr, &key_imp, 0);
			tesky_add_to_pubkeylist(key_imp->subkeys->keyid, key_imp->uids->name, key_imp->uids->email, key_imp->protocol);
		}
		else{
			gpgme_get_key (tesky_ctx, import_result->imports->fpr, &key_imp, 1);
			tesky_add_to_privkeylist(key_imp->subkeys->keyid, key_imp->uids->name, key_imp->uids->email, key_imp->protocol);
		}
	}
	//release tesky_ctx
	gpgme_release(tesky_ctx);
}

//TODO:
//Generate new key pair
void Crypter::tesky_generate_new_keypair(const char* key_info)
{
	//gpgme_genkey_result_t result;
	//gpgme_key_t key;

	//ZA OVO CE MI TREBATI NOV wxFRAME
	//mozda bolje prvo da probam enkr i dekr sa postojecim kljucevima :)

	gpgme_error_t err;	
	gpgme_genkey_result_t result;
	tesky_init_ctx();

	//const char *key_info;
	//default key info
	/* primer
	const char key_info[] = "<GnupgKeyParms format=\"internal\">\n"
						"Key-Type: default\n"
						"Subkey-Type: default\n"
						"Name-Real: Joe Tester\n"
						"Name-Comment: with stupid passphrase\n"
						"Name-Email: joe@foo.bar\n"
						"Expire-Date: 0\n"
						"Passphrase: abc\n"
						"</GnupgKeyParms>\n";
	*/

	/* start generate key */
	/* You can find the gpgme_op_createkey function in the GPGME
	documentation. This func equals to gpg --quick-generate-key */

	/* GPG does not support public and secret, they should be NULL.
	GnuPG will generate a key pair and add it to the standard key ring.*/
	err = gpgme_op_genkey(tesky_ctx, key_info,
		/*public*/ NULL, /*private*/ NULL);
	exit_if_err(err);
	result = gpgme_op_genkey_result(tesky_ctx);

	printf("Key: %s, %s, %s\n", result->fpr,
		result->primary ? "primary" : "no primary",
		result->sub ? "sub" : "no sub");

	

//TODO
//	dodati u linked listu da bi se gui updateovao :)
	//update_pubilc_key_list
	//update_private_key_list
//privremeno resenje
	
	
	gpgme_release(tesky_ctx);
}

//TODO:
//In Encryption add a new key -> encrypt -> release new key
//Nemoj da ubacujes kljuc u memoriju dok ne kliknu encrypt
std::string Crypter::tesky_encrypt_data(const char *buffer, size_t size)
{
	std::string result_ciphertext;
	//printf("%s\n", buffer); //:) radi
	//decyprtion je ciphertext for dec
	//initialize plaintext and fill with passed data
	gpgme_data_new_from_mem(&plaintext_for_enc, buffer, strlen(buffer), 0);
	//initialize ciphertext for result of encryption
	gpgme_data_new(&ciphertext_for_dec);

//TODO:	
//	PROVERI DAL JE CURR PUBKEY NULL
	tesky_load_pubkey();
	//tesky_load_privkey()
	tesky_init_ctx();
	gpgme_op_encrypt(tesky_ctx, &selected_pubkey, GPGME_ENCRYPT_ALWAYS_TRUST, plaintext_for_enc, ciphertext_for_dec);

	gpgme_encrypt_result_t result = gpgme_op_encrypt_result(tesky_ctx);
	if (result->invalid_recipients)
    {
      fprintf (stderr, "Invalid recipient encountered: %s\n",
	       result->invalid_recipients->fpr);
      exit (1);
    }

	result_ciphertext = print_data(ciphertext_for_dec);
	//print_data(plaintext_for_enc);
	//gpgme_data_read(ciphertext_for_dec, result_ciphertext, );
	free(selected_pubkey);
	gpgme_data_release(plaintext_for_enc);
	gpgme_data_release(ciphertext_for_dec);
	gpgme_release(tesky_ctx);

	//err = gpgme_op_encrypt_start(tesky_ctx, &selected_pubkey, GPGME_ENCRYPT_ALWAYS_TRUST, plaintext_for_enc, ciphertext_for_dec);
	//gpgme_wait(tesky_ctx, &err, true);


	//printf("%s\n", ciphertext_for_dec);
	//gpgme_data_read (ciphertext_for_dec, void *buffer, );

	//promeni u char *
	printf("LOG: Encryption done :)\n");
	return result_ciphertext;
}

std::string Crypter::tesky_decrypt_data(const char *buffer, size_t size)
{
	std::string result_plaintext;
	//printf("%s\n", buffer); //:) radi
	//decyprtion je ciphertext for dec
	//initialize plaintext and fill with passed data
	gpgme_data_new_from_mem(&ciphertext_for_dec, buffer, strlen(buffer), 0);
	//initialize ciphertext for result of encryption
	gpgme_data_new(&plaintext_for_enc);

//TODO:	
//	PROVERI DAL JE CURR PUBKEY NULL
	//tesky_load_privkey();
	//tesky_load_privkey()
	tesky_init_ctx();
	gpgme_op_decrypt(tesky_ctx, ciphertext_for_dec, plaintext_for_enc);

	gpgme_decrypt_result_t result = gpgme_op_decrypt_result(tesky_ctx);

	if (result->unsupported_algorithm)
    {
      fprintf (stderr, "%s:%i: unsupported algorithm: %s\n",
	       __FILE__, __LINE__, result->unsupported_algorithm);
      exit (1);
    }

	//print_data(ciphertext_for_dec);
	result_plaintext =  print_data(plaintext_for_enc);
	//gpgme_data_read(ciphertext_for_dec, result_ciphertext, );
	gpgme_data_release(plaintext_for_enc);
	gpgme_data_release(ciphertext_for_dec);
	gpgme_release(tesky_ctx);

	//err = gpgme_op_encrypt_start(tesky_ctx, &selected_pubkey, GPGME_ENCRYPT_ALWAYS_TRUST, plaintext_for_enc, ciphertext_for_dec);
	//gpgme_wait(tesky_ctx, &err, true);


	//printf("%s\n", ciphertext_for_dec);
	//gpgme_data_read (ciphertext_for_dec, void *buffer, );

	//promeni u char *
	printf("LOG: Decryption done :)\n");
	return result_plaintext;
}

void Crypter::tesky_load_pubkey()
{
	tesky_init_ctx();
	err = (gpgme_op_keylist_start(tesky_ctx, NULL, 0));
	gpgme_key_t key;
    while (!err)
    {
        err = gpgme_op_keylist_next (tesky_ctx, &key);
        if (err)
          break;
        	//printf("%s\n", key->subkeys->keyid);
        if (key->uids && key->uids->name)
			//printf("%s\n", key->uids->name);
        if (key->uids && key->uids->email)
        	//printf("%s\n", key->uids->email);
        putchar ('\n');

		if(strcmp(pub_curr_key->uid, key->subkeys->keyid) == 0)
		{
			printf("LOG: found the curr_pubkey \n");
			selected_pubkey = key;
			printf("LOG: selected pubkey: %s %s\n", pub_curr_key->uid, selected_pubkey->subkeys->keyid);
			return;
		}	

        gpgme_key_release (key);
    }

	gpgme_op_keylist_end(tesky_ctx);
	gpgme_release(tesky_ctx);
}
//tesky_load_privkey()

std::string Crypter::print_data(gpgme_data_t dh)
{
	std::string data;
	char buf[BUF_SIZE+1];
	int ret;

	ret = gpgme_data_seek(dh, 0, SEEK_SET);
	if(ret)	
		exit_if_err(gpgme_err_code_from_errno (errno));
	while((ret = gpgme_data_read (dh, buf, BUF_SIZE)) > 0){
		//fwrite(buf, ret, 1, stdout);
		std::string bufs(buf, ret);
		data += bufs;
	}
	if(ret < 0)
		exit_if_err(gpgme_err_code_from_errno (errno));

	ret = gpgme_data_seek(dh, 0, SEEK_SET);

	return data;
}

//LinkedList methods
void Crypter::tesky_init_keylists()
{
	pub_head_node = nullptr;
	pub_curr_key = pub_head_node;		//postaviti na pub head node, kad je popunimo
	priv_head_node = nullptr;
	priv_curr_key = priv_head_node;	//postaviti na priv head node, kad je popunimo

	n_privkey = 0;
	n_pubkey = 0;

//TODO:
//	PROBLEM OKO CUVANJA VREDNOSTI KLJUCA U NODE
//	JER NESTANU KAD IZADJU IZ MEMORIJE
//	NZM KAKO DA IH STOREUJEM

	//load all keys from gpg to linked list :D
	//when you need the key, search for it with UID
	
	//tesky_populate_priv_list()			- koristi gpgme_set_keylist_mode(tesky_ctx, GPGME_KEYLIST_MODE_WITH_SECRET); 
	//tesky_populate_public_list()			- napravi nov ctx
	
	//import private keys
	tesky_init_ctx();
	gpgme_set_keylist_mode(tesky_ctx, GPGME_KEYLIST_MODE_WITH_SECRET);
	err = (gpgme_op_keylist_start(tesky_ctx, NULL, 0));
	gpgme_key_t key;
    while (!err)
    {
        err = gpgme_op_keylist_next (tesky_ctx, &key);
        if (err)
          break;
        	//printf("%s\n", key->subkeys->keyid);
        if (key->uids && key->uids->name)
			//printf("%s\n", key->uids->name);
        if (key->uids && key->uids->email)
        	//printf("%s\n", key->uids->email);
        //putchar ('\n');

		//add to linked list :)
		//if(key->secret == 0)
		//	tesky_add_to_pubkeylist(key->subkeys->keyid, key->uids->name, key->uids->email, key->protocol);
		if(key->secret == 1)
			tesky_add_to_privkeylist(key->subkeys->keyid, key->uids->name, key->uids->email, key->protocol);

        gpgme_key_release (key);
    }

	gpgme_op_keylist_end(tesky_ctx);
	gpgme_release(tesky_ctx);



	//import public keys
	tesky_init_ctx();
	err = (gpgme_op_keylist_start(tesky_ctx, NULL, 0));
	gpgme_key_t key2;
    while (!err)
    {
        err = gpgme_op_keylist_next (tesky_ctx, &key2);
        if (err)
          break;
        	//printf("%s\n", key->subkeys->keyid);
        if (key2->uids && key2->uids->name)
			//printf("%s\n", key->uids->name);
        if (key2->uids && key2->uids->email)
        	//printf("%s\n", key->uids->email);
        //putchar ('\n');

		//add to linked list :)
		if(key2->secret == 0)
			tesky_add_to_pubkeylist(key2->subkeys->keyid, key2->uids->name, key2->uids->email, key2->protocol);
		//if(key->secret == 1)
		//	tesky_add_to_privkeylist(key->subkeys->keyid, key->uids->name, key->uids->email, key->protocol);

        gpgme_key_release (key2);
    }

	gpgme_op_keylist_end(tesky_ctx);
	gpgme_release(tesky_ctx);





  tesky_print_publistkey();
  tesky_print_privlistkey();
}

void Crypter::tesky_add_to_pubkeylist(char *uid, char *user_name, char *email, gpgme_protocol_t protocol)
{
	pubkey *p = (pubkey *)malloc(sizeof(pubkey));	//either way ill need a new node
	if(n_pubkey == 0)	//if theres no head node
	{
		p->id = n_pubkey++;		//adding first element to list of pubkeys
		p->uid = strdup(uid);
		p->user_name = strdup(user_name);
		p->email = strdup(email);
		p->protocol = protocol;
		p->last = nullptr;
		p->next = nullptr;
		pub_head_node = p;
		printf("LL: added head to public key list: id: %d, uid: %s, un: %s\n", p->id, p->uid, p->user_name);
		//free(p);
		return;
	}

	//you can also do this with one node, pcurr->next->next->last = pcurr->next;..
	pubkey *pcurr = pub_head_node;
	while(pcurr->next!=nullptr)		//searching the end of the list
	{
		pcurr = pcurr->next;
	}

	p->id = n_pubkey++;		//adding another element to list of pub keys from 0, because wxWidgets counts from 0, but n_pubkey will grow accordingly since ++ is on right side :D
	p->uid = strdup(uid);
	p->user_name = strdup(user_name);
	p->email = strdup(email);
	p->protocol = protocol;
	p->last = pcurr;
	p->next = nullptr;
	pcurr->next = p;
	printf("LL: added node to public key list: id: %d, uid: %s, un: %s\n", p->id, p->uid, p->user_name);
	//free(p);
	return;
}

void Crypter::tesky_add_to_privkeylist(char *uid, char *user_name, char *email, gpgme_protocol_t protocol)
{
	privkey *p = (privkey *)malloc(sizeof(privkey));	//either way ill need a new node
	if(n_privkey == 0)	//if theres no head node
	{
		p->id = n_privkey++;		//adding first element to list of pubkeys
		p->uid = strdup(uid);
		p->user_name = strdup(user_name);
		p->email = strdup(email);
		p->protocol = protocol;
		p->last = nullptr;
		p->next = nullptr;
		priv_head_node = p;
		printf("LL: added head to private key list: id: %d, uid: %s, un: %s\n", p->id, p->uid, p->user_name);
		//free(p);
		return;
	}

	//you can also do this with one node, pcurr->next->next->last = pcurr->next;..
	privkey *pcurr = priv_head_node;
	while(pcurr->next!=nullptr)		//searching the end of the list
	{
		pcurr = pcurr->next;
	}

	p->id = n_privkey++;		//adding another element to list of pub keys from 0, because wxWidgets counts from 0, but n_pubkey will grow accordingly since ++ is on right side :D
	p->uid = strdup(uid);
	p->user_name = strdup(user_name);
	p->email = strdup(email);
	p->protocol = protocol;
	p->last = pcurr;
	p->next = nullptr;
	pcurr->next = p;
	printf("LL: added head to private key list: id: %d, uid: %s, un: %s\n", p->id, p->uid, p->user_name);
	//free(p);
	return;
}

//TODO: delete key from list methods
//void tesky_delete_from_pubkeylist();
//void tesky_delete_from_privkeylist();

void Crypter::tesky_print_publistkey()
{
	printf("PUBLIC LIST:\n");
	pubkey *pcurr = pub_head_node;
	while(pcurr!=nullptr)		//searching the end of the list
	{
		printf("node %d: uid: %s un: %s em: %s proto: %s\n", pcurr->id, pcurr->uid, pcurr->user_name, pcurr->email, gpgme_get_protocol_name(pcurr->protocol));
		pcurr = pcurr->next;
	}
	return;
}
void Crypter::tesky_print_privlistkey()
{
	printf("PRIVATE LIST:\n");
	privkey *pcurr = priv_head_node;
	while(pcurr!=nullptr)		//searching the end of the list
	{
		printf("node %d: uid: %s un: %s em: %s proto: %s\n", pcurr->id, pcurr->uid, pcurr->user_name, pcurr->email, gpgme_get_protocol_name(pcurr->protocol));
		pcurr = pcurr->next;
	}
	return;
}
