CC=cc
CCFLAGS=-std=c11 -Wall -Wextra -Werror -pedantic -fPIC

INCLUDE=-Iinclude

objects = $(patsubst src/%.c, build/%.o, $(wildcard src/*.c))

lib/liboudon.so : $(objects)
	$(CC) -shared $^ -o $@ 

build/%.o : src/%.c include/loudon/%.h
	$(CC) $(CCFLAGS) $(INCLUDE) -o $@ -c $<

clean :
	rm -f build/*.o

destroy : clean
	rm -r lib/*
