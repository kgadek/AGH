# Kompilator C, C++ i Pascala
CC			= gcc
CXX			= g++
CPAS			= ppc386
# Opcje kompilacji C ANSI pedantic, C++ i Pascala
CFLAGS_ANSI		= -ansi -pedantic -Wall -W -Wconversion -Wshadow\
			  -Wcast-qual -Wwrite-strings
CXXFLAGS		= -Wall
PASFLAGS		= -XS -O2
# Flagi linkera
LDFLAGS			= -O2 -lm -lcppunit
# Pliki wynikowe (tylko zlinkowane)
OUTFILES		= bst_bniemcz dict_mnowak rb_kgadek trie_bniemcz\
			  trie_rlazarz priorityqueue_bniemcz testy\
			  rb_prettyprint
# Lista rzeczy do zrobienia po wydaniu komendy `make all`
ALLOBJ			= testy avl_bst_splay_tree_mmk.cpp.o bst_bniemcz\
			  dict_mnowak priorityqueue_bniemcz rb_kgadek.cpp.o\
			  rb_kgadek_pas splay_ijurkowski.c.o trie_bniemcz\
			  trie_rlazarz rb_prettyprint
# CppUnit: lista modulow testerki
TESTOBJ			= test_avl.o

# Regula clean
.PHONY: clean
clean:
	rm -f $(OUTFILES) *.o *~
# Regula all
.PHONY: all
all: $(ALLOBJ)


################################################################################
#  Testerka (CppUnit)                                                          #
################################################################################
testy: testy.cpp.o test_avl.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) testy.cpp $(TESTOBJ) -o testy
	./testy
test_avl.o: test_avl.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c $? -o $@
################################################################################
#  Reguly ogolne                                                               #
################################################################################
%.c.o: %.c
	$(CC) $(CFLAGS_ANSI) $(LDFLAGS) -c $? -o $@
%.cpp.o: %.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c $? -o $@
################################################################################
#  Obiekty wymagajace specjalnych regul                                        #
################################################################################
rb_kgadek_pas: rb_kgadek.pas
	$(CPAS) $(PASFLAGS) $?

