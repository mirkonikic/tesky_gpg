#if defined(__linux__)
#include "aarch.h"

void aarch_info(){printf("Operating system is: Linux :)\n");}
bool directory_exists(char *pathname)
{
    std::string HOME = getenv("HOME");
    HOME += "/";
    HOME += pathname;
    DIR* dir = opendir(HOME.c_str());
    if (dir) return true || closedir(dir);   //closedir vraca 0 => 0 || 1 = 1
    //else if (ENOENT == errno) //its surely false
    return false;
}
void init_gpgme()
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
}
void init_data(){printf("Ucitavam keys iz foldera\n");}


#endif