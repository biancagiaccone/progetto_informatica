CC = gcc
CFLAGS = -Wall

all: server client

server : server.c
	$(CC) server.c $(CFLAGS) -o server

client : client.c
	$(CC) client.c $(CFLAGS) -o client

clean 	:
	rm server
	rm client

PHONY : clean all
