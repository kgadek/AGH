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
#LDFLAGS			= -O2 -lm -lcppunit
LDFLAGS		= -O2 -lm	# wersja dla nieposiadajacych CppUnit
# Pliki wynikowe (tylko zlinkowane)
OUTFILES		= bst_bniemcz dict_mnowak rb_kgadek trie_bniemcz\
			  trie_rlazarz priorityqueue_bniemcz tests\
			  rb_prettyprint testerka
# Lista rzeczy do zrobienia po wydaniu komendy `make all`
ALLOBJ			= testy avl_bst_splay_tree_mmk.cpp.o bst_bniemcz\
			  dict_mnowak priorityqueue_bniemcz rb_kgadek.cpp.o\
			  rb_kgadek_pas splay_ijurkowski.c.o trie_bniemcz\
			  trie_rlazarz rb_prettyprint testerka\
			  testy/avl_kgadek_tc1.cpp.o
# CppUnit: lista modulow testerki
TESTOBJ			= test_avl.cpp.o

# Regula clean
.PHONY: clean
clean:
	rm -f $(OUTFILES) *.o *~ testy/*.o testy/*.~
# Regula all
.PHONY: all
all: $(ALLOBJ)


################################################################################
#  Testerki dwie (CppUnit)                                                     #
################################################################################
testerka: avl_kgadek.cpp.o common_kgadek.cpp.o testy/avl_kgadek_tc1.cpp.o\
		testerka.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -lcppunit $? -o $@
tests: tests.cpp.o test_avl.cpp.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -lcppunit testy.cpp $(TESTOBJ) -o testy
	./testy
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

