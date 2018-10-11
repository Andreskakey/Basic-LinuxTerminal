#This makefile will build then compile the C program

CFLAGS = -c -Wall

all: overlay pgm1 pgm2 

a.out: overlay.o Makefile pgm1.o pgm2.o  
	gcc  -c -o  overlay.o pgm1.o pgm2.o\

overlay: overlay.c
	gcc  -c -o $(CFLAGS) overlay overlay.c 
pgm1: pgm1.c Makefile  overlay.c
	gcc  -c -o $(CFLAGS) pgm1 pgm1.c
pgm2: pgm2.c Makefile  overlay.c
	gcc  -c -o $(CFLAGS) pgm2 pgm2.c

a.out: 
	gcc  overlay.o pgm1.o pgm2.o\
