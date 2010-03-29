CC 	= gcc
CFLAGS	= -ansi -pedantic -Wall -W -Wconversion -Wshadow -Wcast-qual -Wwrite-strings
LDFLAGS = -O2

sorts.o: sorts.h sorts.c
	$(CC) -c $(LDFLAGS) $(CFLAGS) sorts.c -o sorts.o
sort_test.o: sort_test.c
	$(CC) -c $(LDFLAGS) $(CFLAGS) sort_test.c -o sort_test.o
sort: sorts.o sort_test.o
	$(CC) $(CFLAGS) $(LDFLAGS) sorts.o sort_test.o -o sort 
