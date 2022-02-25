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
	
	exit_if_err(gpgme_get_engine_info(&tesky_engine_info));
	printf("file=%s, home=%s\n", tesky_engine_info->file_name, tesky_engine_info->home_dir);

	//default je armored ascii
	gpgme_set_armor(tesky_ctx, tesky_armored);


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

	exit_if_err(gpgme_ctx_set_engine_info(tesky_ctx, tesky_protocol, "tesky v0.07", NULL));
}
void tesky_end_ctx()
{
	gpgme_release(tesky_ctx);
}
std::string tesky_ctx_get_protocol(){return gpgme_get_protocol_name(gpgme_get_protocol(tesky_ctx));}
void tesky_init_data(){printf("Ucitavam keys iz foldera\n");}
void tesky_init_keylists()
{
	pub_head_node = nullptr;
	pub_curr_key = pub_head_node;		//postaviti na pub head node, kad je popunimo
	priv_head_node = nullptr;
	priv_curr_key = priv_head_node;	//postaviti na priv head node, kad je popunimo

	n_privkey = 0;
	n_pubkey = 0;

	//proveri da li postoji .tesky i popuni liste
	//ako ne postoji ostavi praznu listu
	//napisi init_gui, koja zavisno od n kljuceva apdejtuje liste
	if(tesky_directory_exists((char *)".tesky")){	//check for dir in user home directory
		printf(".tesky data directory exists: %s\n", ".tesky");
		tesky_add_to_pubkeylist((char *)"pubkey1", (char *)"user1");
		tesky_add_to_pubkeylist((char *)"pubkey2", (char *)"user2");
		tesky_add_to_pubkeylist((char *)"pubkey3", (char *)"user3");
		tesky_add_to_pubkeylist((char *)"pubkey4", (char *)"user4");
		tesky_add_to_privkeylist((char *)"privkey5", (char *)"user5");
		tesky_add_to_privkeylist((char *)"privkey6", (char *)"user6");
		//import all keys as linked list i guess
		//or store somewhere all names of keys with some ID
		//or find a way to keep track of keys
	}
	else
	{
		//create new directory in home user dir
	}
}
void tesky_add_to_pubkeylist(char *file_name, char *user_name)
{
	pubkey *p = (pubkey *)malloc(sizeof(pubkey));	//either way ill need a new node
	if(n_pubkey == 0)	//if theres no head node
	{
		p->id = n_pubkey++;		//adding first element to list of pubkeys
		p->user_name = file_name;
		p->file_name = user_name;
		p->last = nullptr;
		p->next = nullptr;
		pub_head_node = p;
		printf("LL: added head to public key list: id: %d, fn: %s, un: %s\n", p->id, p->file_name, p->user_name);
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
	p->user_name = file_name;
	p->file_name = user_name;
	p->last = pcurr;
	p->next = nullptr;
	pcurr->next = p;
	printf("LL: added new node: %d to public key list: id: %d, fn: %s, un: %s\n", n_pubkey, p->id, p->file_name, p->user_name);
	//free(p);
	return;
}
void tesky_add_to_privkeylist(char *file_name, char *user_name)
{
	privkey *p = (privkey *)malloc(sizeof(privkey));	//either way ill need a new node
	if(n_privkey == 0)	//if theres no head node
	{
		p->id = n_privkey++;		//adding first element to list of pubkeys
		p->user_name = file_name;
		p->file_name = user_name;
		p->last = nullptr;
		p->next = nullptr;
		priv_head_node = p;
		printf("LL: added head to public key list: id: %d, fn: %s, un: %s\n", p->id, p->file_name, p->user_name);
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
	p->user_name = file_name;
	p->file_name = user_name;
	p->last = pcurr;
	p->next = nullptr;
	pcurr->next = p;
	printf("LL: added new node: %d to public key list: id: %d, fn: %s, un: %s\n", n_pubkey, p->id, p->file_name, p->user_name);
	//free(p);
	return;
}
void tesky_delete_from_pubkeylist();
void tesky_delete_from_privkeylist();
void tesky_print_publistkey()
{
	pubkey *pcurr = pub_head_node;
	while(pcurr!=nullptr)		//searching the end of the list
	{
		printf("node %d: un: %s\n", pcurr->id, pcurr->user_name);
		pcurr = pcurr->next;
	}
	return;
}
void tesky_print_privlistkey()
{
	privkey *pcurr = priv_head_node;
	while(pcurr!=nullptr)		//searching the end of the list
	{
		printf("node %d: un: %s\n", pcurr->id, pcurr->user_name);
		pcurr = pcurr->next;
	}
	return;
}

#endif