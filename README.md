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
Ideja v0.02.1 - wxformbuilder added za brzi dizajn interfejsa<br>
![ ](img/v0.02.1.jpg)
<br>
Verzija v0.02.0<br>
![ ](img/v0.02.0.jpg)
<br>

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
- [ ] ********PRE-ALPHA version done:
- [x] base design
- [x] menu with apropriate tabs
- [x] fix sizer alignment in Hub tab
- [x] blueprint for GUI
- [ ] clipboard manipulation
- [ ] gpgme.h implementation
- [ ] certificate creation and management
- [x] Enable gpgme.h library
- [ ] Add functionalities to all buttons
- [x] Enable Clipboard
- [ ] Enable system tray icon, na desni klik clipboard en/dec
- [ ] Right Click enc/dec files ili ako je txt file samo dec to clipbrd
- [ ] Make .tesky in ~/.tesky directory path linux
- [ ] Make .tesky in documents in Windows
- [ ] Notepad osmisliti kako i da ubacis da moze odmah u clipboard (dugme za back to clipboard ili encrypt clipboard...)
- [ ] osmisliti da na pokretanju programa on analizira .tesky i kreira linked listu ili array, pa popuni wxString u notepadu pre wxChoice
- [ ] ********ALPHA version done:
- [ ] Certificates tab
- [ ] Notepad tab
- [ ] Hub tab
- [ ] system tray icon taskbar - NOT WORKING
- [ ] ???????? right click on file encrypt
- [x] design for alpha version
- [ ] ********BETA version done:
- [ ] making code compileable on windows, *nix and macOS
- [ ] Chat tab
- [ ] Drag&Drop file encryption ?tab?
- [ ] ********VERSION 1.0.0 done:
- [ ] MDNetwork tab
- [ ] Redesign of the app for WIN, LIN, MACOS
- [ ] tested on all popular Operating Systems
- [ ] ********VERSION 2.0.0 done:
- [ ] PacketEncryptor tab
- [ ] RansomRev tool try to create
- [ ] notepad nek ima real time enkripciju https://youtu.be/BW_B6Zadsj4
- [ ] program koji pokrenes i kriptuje ti automatski data delove paketa i dekriptuje automatski sa odgovarajucim public keyovima, kliknes dva puta i on krene, mozes da izaberes sta ces da kriptujes i onaj sa druge strane kompa treba da dekriptuje -> kao wireshark samo upoznat sa paketima i kriptuje ono sto moze drugi korisnik da dekr
- [ ] tesky chat, start - over, kad kliknes over, sacuva se chat sa slikama u folderu posled ji nivo aplikacije bi bio decentralizovani torent, gde bi uneo ip adrese i stvorio mrezu s njima, pa mozete da pristupate jedni drugima
- [ ] Drag&Drop file encryptor and decryptor
- [ ] probaj da osmislis ransomware reversing tool
