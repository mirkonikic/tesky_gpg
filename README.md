# tesky
GPG key management, encryption/decryption, sign/verify GUI software, based on OpenPGP standard
<br>finish this!

<br>
<br>tesky gpgme zavrsi - ed->grep - EFI programming - LinuxKernelNewbies - customArch - learnChroot - golang/erlang - Haskell - pogledaj Onura Mutlua
<br>UEFI beyond bios - LiveLinuxCD books - Kernel - xv6 - Cryptography in C - RHCSA->RHCE->RHCA cert

### Verzije:
---
Verzija v0.05<br>
![ ](img/version_v0.5.gif)
<br>
Verzija v0.03<br>
![ ](img/version_v0.3.gif)
<br>
Ideja v0.02.1 - wxformbuilder added za brzi dizajn interfejsa
![ ](img/version_v0.2.1.jpg)
<br>
Verzija v0.02
![ ](img/version_v0.2.jpg)
<br>
Verzija v0.01
![ ](img/version_v0.1.jpg)

<br>
Isto kao kleopatra za windows, na desnom kliku stoji encrypt, gore desno u taskbaru kao telegram stoji otvoren program
<br>
Kad se otvori isto ima notepad i certificates sekciju, pronadji samo jezik u kom pises
<br>
A videcu kad ispisem za linux, da ispisem i za Windows u C#, sa nicer GUI-jem
<br>
OpenGPG and Horowitz Keyserver Protocol
<br>
https://github.com/gpg/gnupg
<br>
GUI Framework: WxWidgets -> TaskBarIcon, Clipboard and RightClick
<br>
Na task bar icon mozes da kliknes SetRecipient, ClEncrypt, ClDecrypt, ClEncryptTo.., ClDecryptFrom.., Encrypt, Decrypt
<br>
Gde setRecipient postavi nekog od public kljuceva na recipienta, da ne bi morao za svaki ClEncrypt da biras kome saljes
<br>
ClEncrypt je Clipboard, a obicno Encrypt je da izadje prompt
<br>
koristi .tgpg direktorijum u home/user direktorijumu
<br>
pisacu u C++
<br>
za GPGME lib, u C++ ukljuciti         #include "gpgme.h"   onda imas pristup metodama za poziv enkripcije, umesto sam da implementiras sve


### TODO
- [ ] finished icon taskbar implementation - NOT WORKING
- [ ] finished clipboard encryption decryption - HASNT STARTED
- [ ] finished right click on file encrypt
- [ ] finished certificate creation and management in application
- [ ] finished notepad part in application
- [ ] finished application design
- [ ] finished making code compileable on windows, *nix and macOS
- [ ] Create Sizers for frame
- [x] Create Notebook
- [x] Create tabs for notebook
- [ ] Create Certificates, Notepad and Properties tabs
- [ ] Enable gpgme.h library
- [ ] Add functionalities to buttons
- [ ] Enable Clipboard
- [ ] Enable system tray icon, na desni klik clipboard en/dec
- [ ] Right Click enc/dec files ili ako je txt file samo dec to clipbrd
- [ ] Make .tesky in ~/.tesky directory path linux
- [ ] Make .tesky in documents in Windows
- [ ] Notepad osmisliti kako i da ubacis da moze odmah u clipboard
- [ ] osmisliti da na pokretanju programa on analizira .tesky i kreira linked listu ili array, pa popuni wxString u notepadu pre wxChoice
- [ ] popraviti alignment u Hub tabu