CC=cc
CCFLAGS=-std=c11 -Wall -Wextra -Wall -pedantic

INCLUDE=-I../include
LDFLAGS=-L../lib -loudon
RUNPATH=../lib

BINARIES = $(patsubst %.c, %, $(wildcard *.c))

all : ${BINARIES}

% : %.c 
	$(CC) $(CCFLAGS) $(INCLUDE) -o $@ $< $(LDFLAGS) -Wl,-rpath=$(RUNPATH)

destroy : 
	rm -f $(BINARIES)
