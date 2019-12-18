CC = gcc
FLAGS = -Wall -g


all:runisort libers runtxtfind liber

libers:libers.a

libers.a:isort.o isort.h
	ar rcs libers.a isort.o isort.h

isort.o:isort.c isort.h
	$(CC) $(FLAGS) -c isort.c

main1.o:main1.c isort.h
	$(CC) $(FLAGS) -c main1.c	

runisort:main1.o libers.a	
	$(CC) $(FLAGS) -o runisort main1.o libers.a 	

liber:liber.a

liber.a:txtfind.o txtfind.h
	ar rcs liber.a txtfind.o txtfind.h

txtfind.o:txtfind.c txtfind.h
	$(CC) $(FLAGS) -c txtfind.c

main2.o:main2.c txtfind.h
	$(CC) $(FLAGS) -c main2.c

runtxtfind:main2.o liber.a
	$(CC) $(FLAGS) -o run main2.o liber.a 

.PHONY:clean all

clean:
	rm -f *.o *.a *.so runtxtfind runisort