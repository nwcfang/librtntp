CC=gcc
CFLAGS=-Wall -ggdb -O0
LDFLAGS= 

all: udp-server udp-client

udp-server: udp-server.o
	$(CC) $(LDFLAGS) -o $@ udp-server.o -ltio

udp-client: udp-client.o
	$(CC) $(LDFLAGS) -o $@ udp-client.o -ltio
.PHONY: clean
clean:
	rm -rf udp-server.o udp-client.o udp-server udp-client
