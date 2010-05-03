CC			= gcc
CXX			= g++
CPAS			= ppc386
CFLAGS_ANSI		= -ansi -pedantic -Wall -W -Wconversion -Wshadow -Wcast-qual -Wwrite-strings
CXXFLAGS		= 
PASFLAGS		= -XS -O2 
LDFLAGS			= -O2 -lm

.PHONY: clean

clean:
	rm -f mnowak_dict rb bniemcz_trie bniemcz_priorityqueue *.o *~

bniemcz_trie: bniemcz_trie.c
	$(CC) $(CFLAGS_ANSI) $(LDFLAGS) bniemcz_trie.c -o bniemcz_trie

bniemcz_priorityqueue: bniemcz_priorityqueue.c
	$(CC) $(CFLAGS_ANSI) $(LDFLAGS) bniemcz_priorityqueue.c -o bniemcz_priorityqueue

ijurkowski_zig-zag.o: ijurkowski_zig-zag.c
	$(CC) $(CFLAGS_ANSI) ijurkowski_zig-zag.c -c -o ijurkowski_zig-zag.o

mnowak_dict: mnowak_dict.cpp
	$(CXX) $(CFLAGS_ANSI) $(LDFLAGS) mnowak_dict.cpp -o mnowak_dict

mmk_avl_bst_tree.o: mmk_avl_bst_tree.h mmk_avl_bst_tree.cpp
	$(CXX) -c mmk_avl_bst_tree.cpp -o mmk_avl_bst_tree.o

rb: rb.pas
	$(CPAS) $(PASFLAGS) rb.pas
