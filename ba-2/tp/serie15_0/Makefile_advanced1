

# Makefile

CC = gcc 

CFLAGS = -Wall -ansi 


all: eatFruit.x


fruits.o   :  fruits.c fruits.h 

	$(CC) $(CFLAGS) -c fruits.c -o fruits.o


persons.o  :  persons.c persons.h fruits.h 

	$(CC) $(CFLAGS) -c persons.c -o persons.o


eatFruit.o :  fruits.h persons.h eatFruit.c 

	$(CC) $(CFLAGS) -c eatFruit.c -o eatFruit.o


eatFruit.x   :  fruits.o persons.o eatFruit.o 

	gcc eatFruit.o persons.o fruits.o -o eatFruit.x
