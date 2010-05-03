CC			= gcc
CCPP			= g++
CFLAGS_ANSI		= -ansi -pedantic -Wall -W -Wconversion -Wshadow -Wcast-qual -Wwrite-strings
CPPFLAGS		= 
LDFLAGS			= -O2 -lm

clean:
	rm -f dict *~

dict: dict.c
	$(CC) $(CFLAGS_ANSI) $(LDFLAGS) dict.c -o dict
