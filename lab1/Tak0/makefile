outpot: count-words.o
	gcc  -g -m32 -Wall count-words.o -o outpot

count-words.o: count-words.c
	gcc -g -m32 -Wall -c count-words.c -o count-words.o

.PHONY:clean
clean:
	rm *.o outpot