CC = gcc
FLAGS = -Wall -g

all: isort txtfind

isort: main1.o isort.o
	$(CC) $(FLAGS) -o isort main1.o isort.o 

main1.o: main1.c isort.h
	$(CC) $(FLAGS) -c main1.c 

isort.o: isort.c isort.h
	$(CC) $(FLAGS) -c isort.c 

txtfind: main2.o txtfind.o
	$(CC) $(FLAGS) -o txtfind main2.o txtfind.o 

main2.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c main2.c 

txtfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c txtfind.c 

.PHONY: clean all

clean:
	rm -f *.o isort txtfind