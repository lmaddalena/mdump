test: test.o mdump.o
	gcc -std=c99 mdump.o test.o -o test

test.o : ../test.c
	gcc -std=c99 -c ../test.c

mdump.o : ../mdump.c ../mdump.h
	gcc -std=c99 -c ../mdump.c
