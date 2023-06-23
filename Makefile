CC = gcc

all: libhtmc.a main

main: main.c libhtmc.a
	$(CC) -o main.exe $^ -I.
	./main.exe

libhtmc: htmc.o htmc_helpers.o
	ar rcs libhtmc.a $^

htmc.o: htmc.c
	$(CC) -c htmc.c -o htmc.o -I.

htmc_helpers.o: htmc_helpers.c
	$(CC) -c htmc_helpers.c -o htmc_helpers.o -I.