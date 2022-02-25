#if defined(__linux__)
#include "aarch.h"

gpgme_error_t err;
gpgme_engine_info_t tesky_engine_info;
gpgme_ctx_t tesky_ctx;
int tesky_armored = 1;
int n_pubkey = 0;
int n_privkey = 0;
pubkey *pub_head_node = nullptr;
privkey *priv_head_node = nullptr;
pubkey *pub_curr_key = nullptr;
privkey *priv_curr_key = nullptr;
gpgme_pubkey_algo_t tesky_algorithm;
gpgme_hash_algo_t tesky_hash;
gpgme_protocol_t tesky_protocol;

void tesky_aarch_info(){printf("Operating system is: Linux :)\n");}
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
void tesky_init_gpgme()
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
void tesky_init_ctx(gpgme_protocol_t protocol_passed, int armored_passed, gpgme_hash_algo_t hash_passed, gpgme_pubkey_algo_t algo_passed)
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

	//set engine
	exit_if_err(gpgme_ctx_set_engine_info(tesky_ctx, tesky_protocol, tesky_engine_info->file_name, tesky_engine_info->home_dir));
	
	//initialize engine
	err = gpgme_get_engine_info(&tesky_engine_info);
	
	//data container
		//gpgme_data_t

	//creating data buffer:
	//	1. Memory Based Data Buffers
		//gpgme_data_new(gpgme_data_t *dh)
	//	2. File Based Data Buffers
		//gpgme_data_new_from_fd(gpgme_data_t *dh, int FD)
	//	3. Callback Based Data Buffers
	
	//destroying data buffers:
		//gpgme_data_release(gpgme_data_t)

	//I/O with data buffers
		//read from dh to buffer size length
			//gpgme_data_read(gpgme_data_t dh, void *buffer, size_t length)
		//write from buffer to dh, size length
			//gpgme_data_write(gpgme_data_t dh, void *buffer, size_t length)

	//change cursor position in data_t
		//gpgme_data_seek(gpgme_data_t dh, off_t offset, int whence);
		//int whence -> SEEK_SET, SEEK_CUR, SEEK_END

	
	

	//destroy new ctx
	//gpgme_release(tesky_ctx);

}
void tesky_update_ctx(gpgme_protocol_t protocol_passed, gpgme_hash_algo_t hash_passed, gpgme_pubkey_algo_t algo_passed)
{
	tesky_protocol = protocol_passed;
	tesky_hash = hash_passed;
	tesky_algorithm = algo_passed;

	//change protocol of context
	exit_if_err(gpgme_set_protocol(tesky_ctx, tesky_protocol));

	exit_if_err(gpgme_ctx_set_engine_info(tesky_ctx, tesky_protocol, tesky_engine_info->file_name, NULL));
}
void tesky_end_ctx()
{
	gpgme_release(tesky_ctx);
}
std::string tesky_ctx_get_protocol(){return gpgme_get_protocol_name(gpgme_get_protocol(tesky_ctx));}

//JOS NE ZNAM
void tesky_init_data(){printf("Ucitavam keys iz foldera\n");}

//TODO:
//Generate new key pair
void tesky_new_keypair()
{
	//gpgme_genkey_result_t result;
	//gpgme_key_t key;

	//ZA OVO CE MI TREBATI NOV wxFRAME
	//mozda bolje prvo da probam enkr i dekr sa postojecim kljucevima :)
}

//TODO:
//In Encryption add a new key -> encrypt -> release new key
//Nemoj da ubacujes kljuc u memoriju dok ne kliknu encrypt
void sign_and_encrypt(const char *data, const char *public_key_fingerprint, const char *path, const char *file_name)
{
	//gpgme_key_t public_key;
	
	//LOAD KEYS INTO GPGME
	//use the key

}

//LinkedList methods
void tesky_init_keylists()
{
	pub_head_node = nullptr;
	pub_curr_key = pub_head_node;		//postaviti na pub head node, kad je popunimo
	priv_head_node = nullptr;
	priv_curr_key = priv_head_node;	//postaviti na priv head node, kad je popunimo

	n_privkey = 0;
	n_pubkey = 0;

	//load all keys from gpg to linked list :D
	//when you need the key, search for it with UID
	err = (gpgme_op_keylist_start(tesky_ctx, NULL, 0));
	gpgme_key_t key;
    while (!err)
    {
        err = gpgme_op_keylist_next (tesky_ctx, &key);
        if (err)
          break;
        	printf("%s\n", key->subkeys->keyid);
        if (key->uids && key->uids->name)
			printf("%s\n", key->uids->name);
        if (key->uids && key->uids->email)
        	printf("%s\n", key->uids->email);
        putchar ('\n');

		//add to linked list :)
		if(key->secret == 0)
			tesky_add_to_pubkeylist(key->subkeys->keyid, key->uids->name, key->uids->email, key->protocol);
		//else if(key->secret == 1)
		//	tesky_add_to_privkeylist(key_data[0], key_data[1], key_data[2], key->protocol);

        gpgme_key_release (key);
    }

	gpgme_op_keylist_end(tesky_ctx);

	tesky_print_publistkey();
	//tesky_print_privlistkey();
}
void tesky_add_to_pubkeylist(char *uid, char *user_name, char *email, gpgme_protocol_t protocol)
{
	printf("aa");
	pubkey *p = (pubkey *)malloc(sizeof(pubkey));	//either way ill need a new node
	if(n_pubkey == 0)	//if theres no head node
	{
		printf("aa");
		p->id = n_pubkey++;		//adding first element to list of pubkeys
		p->uid = uid;
		p->user_name = user_name;
		p->email = email;
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
	p->uid = uid;
	p->user_name = user_name;
	p->email = email;
	p->protocol = protocol;
	p->last = pcurr;
	p->next = nullptr;
	pcurr->next = p;
	printf("LL: added node to public key list: id: %d, uid: %s, un: %s\n", p->id, p->uid, p->user_name);
	//free(p);
	return;
}
void tesky_add_to_privkeylist(char *uid, char *user_name, char *email, gpgme_protocol_t protocol)
{
	privkey *p = (privkey *)malloc(sizeof(privkey));	//either way ill need a new node
	if(n_privkey == 0)	//if theres no head node
	{
		p->id = n_privkey++;		//adding first element to list of pubkeys
		p->uid = uid;
		p->user_name = user_name;
		p->email = email;
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
	p->uid = uid;
	p->user_name = user_name;
	p->email = email;
	p->protocol = protocol;
	p->last = pcurr;
	p->next = nullptr;
	pcurr->next = p;
	printf("LL: added head to private key list: id: %d, uid: %s, un: %s\n", p->id, p->uid, p->user_name);
	//free(p);
	return;
}
//TODO: delete key from list methods
void tesky_delete_from_pubkeylist();
void tesky_delete_from_privkeylist();
//^^
void tesky_print_publistkey()
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
void tesky_print_privlistkey()
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

#endif