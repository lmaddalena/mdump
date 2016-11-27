CC = gcc

CFLAGS = -std=c99 -g
ODIR = bin
PROG = test.out

all: test.o mdump.o
	$(CC) $(LDFLAGS) $(ODIR)/*.o -o $(ODIR)/$(PROG)

test.o : test.c
	$(CC) $(CFLAGS) -c test.c -o $(ODIR)/test.o

mdump.o : mdump.c mdump.h
	$(CC) $(CFLAGS) -c mdump.c -o $(ODIR)/mdump.o

clean:
	rm -f $(ODIR)/$(PROG) $(ODIR)/*.o

