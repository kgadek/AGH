CC			= gcc
CCPP			= g++
CPAS			= ppc386
CFLAGS_ANSI		= -ansi -pedantic -Wall -W -Wconversion -Wshadow -Wcast-qual -Wwrite-strings
CPPFLAGS		= 
PASFLAGS		= -XS -O2 
LDFLAGS			= -O2 -lm

clean:
	rm -f dict rb *.o *~

dict: dict.cpp
	$(CCPP) $(CFLAGS_ANSI) $(LDFLAGS) dict.cpp -o dict

rb: rb.pas
	$(CPAS) $(PASFLAGS) rb.pas

mmk_avl_bst_tree.o: mmk_avl_bst_tree.h mmk_avl_bst_tree.cpp
	$(CCPP) -c mmk_avl_bst_tree.cpp -o mmk_avl_bst_tree.o
