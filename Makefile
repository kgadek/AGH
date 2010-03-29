CC 	= gcc
CFLAGS	= -ansi -pedantic -Wall -W -Wconversion -Wshadow -Wcast-qual -Wwrite-strings -lm
LDFLAGS = -O2

sorts.o: sorts.h sorts.c
	$(CC) -c $(LDFLAGS) $(CFLAGS) sorts.c -o sorts.o
