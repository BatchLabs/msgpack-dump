CC=cc
SRCS=$(wildcard src/*.c)

all:
	$(CC) $(SRCS) -o msgpack-dump -std=c11
