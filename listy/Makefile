CC				= gcc
CCPP			= g++
CFLAGS_ANSI		= -ansi -pedantic -Wall -W -Wconversion -Wshadow -Wcast-qual -Wwrite-strings
CPPFLAGS		= 
LDFLAGS			= -O2 -lm

clean:
	rm -f midz_skiplist mmk_list.o *~

midz_skiplist: midz_skiplist.c
	$(CC) $(CFLAGS_ANSI) $(LDFLAGS) midz_skiplist.c -o midz_skiplist

mmk_list.o: mmk_list.h
	$(CCPP) $(CPPFLAGS) $(LDFLAGS) mmk_list.h -c -o mmk_list.o
