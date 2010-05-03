CC			= gcc
CXX			= g++
CPAS			= ppc386
CFLAGS_ANSI		= -ansi -pedantic -Wall -W -Wconversion -Wshadow -Wcast-qual -Wwrite-strings
CXXFLAGS		= 
PASFLAGS		= -XS -O2 
LDFLAGS			= -O2 -lm

.PHONY: clean

clean:
	rm -f dict rb *.o *~

dict: dict.cpp
	$(CXX) $(CFLAGS_ANSI) $(LDFLAGS) dict.cpp -o dict

mmk_avl_bst_tree.o: mmk_avl_bst_tree.h mmk_avl_bst_tree.cpp
	$(CXX) -c mmk_avl_bst_tree.cpp -o mmk_avl_bst_tree.o

rb: rb.pas
	$(CPAS) $(PASFLAGS) rb.pas
