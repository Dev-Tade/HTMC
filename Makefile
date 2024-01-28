CC = gcc
DEBUG = -ggdb

all: libhtmc main run

main: main.c ./build/libhtmc.a
	$(CC) -o main.exe $^ $(DEBUG)

run: main
	./main.exe

clean:
	rm *.o
	rm *.a
	rm *.exe 
	rm ./build/*

libhtmc: htmc.o tags.o
	ar rcs ./build/libhtmc.a $^
	rm *.o

htmc.o: ./src/htmc.c
	$(CC) -c $< -o htmc.o -I./src $(DEBUG)

tags.o: ./src/tags.c
	$(CC) -c $< -o tags.o -I./src $(DEBUG)