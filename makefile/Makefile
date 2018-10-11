#This makefile will build then compile the C++ program

CFLAGS = -c -Wall

a.out: main.o Makefile Bank.o  
	g++  -c  main.o Bank.o\
main.o: main.o Bank.h
	g++  -c  $(CFLAGS) main.cpp Bank.h
Bank.o: Bank.cpp Makefile Bank.h 
	g++  -c  $(CFLAGS) Bank.cpp
a.out: 
	g++  main.o Bank.o\
