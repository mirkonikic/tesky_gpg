# tesky
GPG key management, encryption/decryption, sign/verify GUI software, based on OpenPGP standard
<br>finish this!

<br>
<br>tesky gpgme zavrsi - ed->grep - EFI programming - LinuxKernelNewbies - customArch - learnChroot - golang/erlang - Haskell - pogledaj Onura Mutlua
<br>UEFI beyond bios - LiveLinuxCD books - Kernel - xv6 - Cryptography in C - RHCSA->RHCE->RHCA cert

### Verzije:
---
Verzija v0.06<br>
![ ](img/v0.06.gif)
<br>
Verzija v0.03<br>
![ ](img/v0.03.gif)
<br>
Ideja v0.02.1 - wxformbuilder added za brzi dizajn interfejsa
![ ](img/v0.02.1.jpg)
<br>
Verzija v0.02.0
![ ](img/v0.02.0.jpg)
<br>
Verzija v0.01
![ ](img/v0.01.jpg)

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
- [x] popraviti alignment u Hub tabu
- [ ] notepad nek ima real time enkripciju https://youtu.be/BW_B6Zadsj4
- [ ] program koji pokrenes i kriptuje ti automatski data delove paketa i dekriptuje automatski sa odgovarajucim public keyovima, kliknes dva puta i on krene, mozes da izaberes sta ces da kriptujes i onaj sa druge strane kompa treba da dekriptuje -> kao wireshark samo upoznat sa paketima i kriptuje ono sto moze drugi korisnik da dekr
- [ ] tesky chat, start - over, kad kliknes over, sacuva se chat sa slikama u folderu posled ji nivo aplikacije bi bio decentralizovani torent, gde bi uneo ip adrese i stvorio mrezu s njima, pa mozete da pristupate jedni drugima
- [ ] Drag&Drop file encryptor and decryptor
- [ ] probaj da osmislis ransomware reversing tool
