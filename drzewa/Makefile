# Kompilator C, C++ i Pascala
CC			= gcc
CXX			= g++
CPAS			= ppc386
# Opcje kompilacji C ANSI pedantic, C++ i Pascala
CFLAGS			= -ansi -pedantic -Wall -W -Wconversion -Wshadow\
			  -Wcast-qual -Wwrite-strings
CXXFLAGS		= -W -Wall -Wshadow -Weffc++ -Wformat -Wsequence-point\
			  -Wunused -Wuninitialized -Wfloat-equal -ansi -pedantic
PASFLAGS		= -XS -O2
# Flagi linkera
LDFLAGS			= -O2 -lm
# Lista rzeczy do zrobienia po wydaniu komendy `make all`
ALLOBJ			= avl_bst_splay_tree_mmk.cpp.o bst_bniemcz\
			  dict_mnowak priorityqueue_bniemcz rb_kgadek.cpp.o\
			  rb_kgadek_pas splay_ijurkowski.c.o trie_bniemcz\
			  trie_rlazarz rb_prettyprint avl_kgadek.cpp.o testerka
# CppUnit: lista modulow testerki
TESTOBJ			= avl_bst_splay_tree_mmk.cpp.o\
			  testy/avl_mmk_tc1.cpp.o\
			  common_kgadek.cpp.o avl_kgadek.cpp.o\
			  testy/avl_kgadek_tc1.cpp.o

# Regula clean
.PHONY: clean
clean:
	rm -f *.o *~ testy/*.o testy/*.~
	find . -mount -perm -111 -and -type f -exec rm {} \;
	find . -mount -name '*.o' -and -type f -exec rm {} \;

# Regula all
.PHONY: all
all: $(ALLOBJ)


################################################################################
#  Tester (CppUnit)                                                            #
################################################################################
testerka: testerka.cpp $(TESTOBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -lcppunit $? -o $@
################################################################################
#  Reguly ogolne                                                               #
################################################################################
%.c.o: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $? -o $@
%.cpp.o: %.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c $? -o $@
################################################################################
#  Obiekty wymagajace specjalnych regul                                        #
################################################################################
rb_kgadek_pas: rb_kgadek.pas
	$(CPAS) $(PASFLAGS) $?

