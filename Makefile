wx_flags=`wx-config --cxxflags --libs`
gpgme_flags=$(shell gpgme-config --libs --cflags)
gpp_flags=-Wall
FLAGS=`wx-config --cxxflags --libs`\
	$(shell gpgme-config --libs --cflags)\
	-Wall
SRC=src/*.cpp include/*/aarch.cpp
BIN=bin/tesky
CC=g++
DEPS=include/*.h include/*/aarch.h

compile: 
	g++ ${SRC} ${FLAGS} -o ${BIN}

clean:
	rm -f ${BIN}
