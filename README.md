<div align="center">
<h1>tesky v0.12</h1>


[![Logo](img/banner.png)](https://github.com/mirkonikic/tesky_gpg)<br>
<img alt="GitHub followers" src="https://img.shields.io/github/followers/mirkonikic?style=social">
<img alt="Twitter Follow" src="https://img.shields.io/twitter/follow/mirkhoff?style=social">
<img alt="GitHub tag (latest by date)" src="https://img.shields.io/github/v/tag/mirkonikic/tesky_gpg?style=plastic"> 
<img alt="GitHub release (latest by date)" src="https://img.shields.io/github/v/release/mirkonikic/tesky_gpg">
<img alt="GitHub" src="https://img.shields.io/github/license/mirkonikic/tesky_gpg">
<img alt="GitHub commit activity" src="https://img.shields.io/github/commit-activity/y/mirkonikic/tesky_gpg?style=plastic"> 
<img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/mirkonikic/tesky_gpg">
</div>
![](https://tokei.rs/b1/github/mirkonikic/tesky_gpg)
  
## About
<br>
<img alt="Supported OS: Ubuntu 21.10" src="https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white">

**Tesky** - [GPG key management](https://en.wikipedia.org/wiki/GNU_Privacy_Guard), encryption/decryption, sign/verify GUI software, based on OpenPGP standard
<br>finish this!

<br>
<br>tesky gpgme zavrsi - ed->grep - EFI programming - LinuxKernelNewbies - customArch - learnChroot - golang/erlang - Haskell - pogledaj Onura Mutlua
<br>UEFI beyond bios - LiveLinuxCD books - Kernel - xv6 - Cryptography in C - RHCSA->RHCE->RHCA cert

### Verzije:
---
Verzija v0.12 - finished linked list for keys<br>
Verzija v0.07 - implemented Cross-Platform optimization<br>
![ ](img/v0.07.gif)
<br>
Verzija v0.03 - fully finished GUI<br>
![ ](img/v0.03.gif)
<br>
Ideja v0.02.1 - wxformbuilder added za brzi dizajn interfejsa<br>
![ ](img/v0.02.1.jpg)
<br>
Verzija v0.02.0 - Began GUI and blueprint<br>
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
- [x] Fix code structure -> Header -> aarch.h <- aarch.cpp PROBLEM, extern in .h, decl in .cpp
- [x] clipboard manipulation
- [x] gpgme.h implementation
- [x] Napravi linked listu za kljuceve
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
- [ ] Certification tab -> delete key
- [ ] Notepad tab -> more functionalities
- [ ] Properties -> add ASCII ARMOR checkbox
- [ ] Properties -> add Crypto choice list
- [ ] Properties -> add HASH choice list
- [ ] Properties -> add Protocol choice list
- [ ] Properties -> Tracker or NAT traversal radio list
- [ ] Properties -> change theme -> prvo dark/light theme
- [ ] Optimize whole code
- [ ] Comment whole code
- [ ] take care of all exceptions
- [x] Fix color problem na linuxu kad promene system theme
- [ ] ********ALPHA version done:
- [ ] Certificates tab: New key, Import keys, OnInit load all keys from .tesky, 
- [ ] Notepad tab: Enc, Dec, Drag&DropFromFile, to clpbrd, to file, from clpbrd, To:[:SELEKTOVANI PUBKEY:], From:[:SELEKTOvANI PRVIKEY:], onda ti i ne treba drag&drop tab
- [ ] system tray icon taskbar - NOT WORKING
- [ ] ???????? right click on file encrypt
- [x] design for alpha version
- [ ] ********BETA version done:
- [x] making code compileable on windows, *nix and macOS - https://stackoverflow.com/questions/3627127/writing-cross-platform-c-code-windows-linux-and-mac-osx
- [ ] razmisli da za windows predjes na c# i wpf ili ostanes na c++
- [ ] ako odlucis za windows wpf, mozes sve za wx da prebacis u lin dir ili da napravis dva odvojena source code-a
- [ ] razmisli za macOS kako ces, moras da testiras u VM
- [ ] all arguments passed when starting program in terminal
- [ ] tested on Windows10-ja-pera, Windows11-pera, Windows7-ja, MacOS-zl, ArchLin-ja, Fedora-ja, Ubuntu-ja, Debian-ja, PopOS-ja, BSD-ja, Manjaro-ja, Mint-ja, Kali-ja, OpenSUSE-ja
- [ ] ********VERSION 1.0.0 STABLE RELEASE done:
- [ ] Redesign of the app for WIN, LIN, MACOS
- [ ] publish on aur
- [ ] publish on debian and ubuntu
- [ ] publish on archlinux
- [ ] ********VERSION 2.0.0 FEATURE COMPLETE RELEASE done:
- [ ] Wireshark PacketEncryptor tab - npr za skype bi sve enkriptova
- [ ] MDNetwork tab - ima slika grafa sa belim cvorovima, pa klikom ih povezujes
- [ ] File Drag and Drop tab
- [ ] Hub tab - Server-Client key sharing tab
- [ ] Chat tab
- [ ] U PROPERTIESU ima opcija i za Logger tab -> console info se ispisuje tu sa vremenom, ima export dugme
- [ ] MDNetwork_node.exe/elf - console (Port forwarding knowledge needed)
- [ ] ^ bolje tracker.exe/elf pa biras da li si za MDNetwork ili Hub, svako kad instalira dobije tracker ip ili ima u properties gde upise IP adresu trackera itd...
- [ ] RansomRev tool try to create
- [ ] Properties: ARMORED ascii, protokol, hash, algoritam, da li zelis trackera ili da probas NAT traversal p2p
- [ ] iscitaj BitTorrent protokol za ovo sve
- [ ] NAT Traversal - https://bford.info/pub/net/p2pnat/ - https://www.it.lut.fi/wiki/lib/exe/fetch.php/courses/ct30a6900/p2p_over_nat.pdf - https://en.wikipedia.org/wiki/NAT_traversal
- [ ] notepad nek ima real time enkripciju https://youtu.be/BW_B6Zadsj4
- [ ] program koji pokrenes i kriptuje ti automatski data delove paketa i dekriptuje automatski sa odgovarajucim public keyovima, kliknes dva puta i on krene, mozes da izaberes sta ces da kriptujes i onaj sa druge strane kompa treba da dekriptuje -> kao wireshark samo upoznat sa paketima i kriptuje ono sto moze drugi korisnik da dekr
- [ ] tesky chat, start - over, kad kliknes over, sacuva se chat sa slikama u folderu posled ji nivo aplikacije bi bio decentralizovani torent, gde bi uneo ip adrese i stvorio mrezu s njima, pa mozete da pristupate jedni drugima
- [ ] Drag&Drop file encryptor and decryptor
- [ ] probaj da osmislis ransomware reversing tool
- [ ] add dark and light theme not related to system, also store that info somewhere
