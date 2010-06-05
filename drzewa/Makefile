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
ALLOBJ			= bst_bniemcz dict_mnowak priorityqueue_bniemcz\
			  rb_kgadek_pas trie_bniemcz trie_rlazarz\
			  rb_prettyprint testerka testy/mktests.cpp
ALLMOD			= avl_bst_splay_tree_mmk.cpp.o rb_kgadek.cpp.o\
			  splay_ijurkowski.c.o avl_kgadek.cpp.o 
# CppUnit: lista modulow testerki
# Niestety, rygorystycznie dobrane flagi kompilatora powoduja wyrzucenie
# duzej ilosci warnow przy kompilacji testow... Trzeba przebolec...
TESTOBJ			= avl_bst_splay_tree_mmk.cpp.o\
			  testy/avl_mmk_tc1.cpp.o\
			  common_kgadek.cpp.o avl_kgadek.cpp.o\
			  testy/avl_kgadek_tc1.cpp.o
# Uwaga! Pliki *.cpp maja po 27MB a ich kompilacja trwa nawet 14min!
BIGTESTOBJ		= testy/avl_kgadek_tc2.cpp.o

# Regula clean
.PHONY: clean all testerka $(ALLOBJ)
clean:
	rm -f *.o *~ testy/*.o testy/*.~
	find . -mount -perm -111 -and -type f -exec rm {} \;
	find . -mount -name '*.o' -and -type f -exec rm {} \;

# Regula all
all: $(ALLMOD) $(ALLOBJ)


################################################################################
#  Tester (CppUnit)                                                            #
################################################################################
testerka: testerka.cpp $(TESTOBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -lcppunit $? -o $@
bigtests: prepare_bigtests $(BIGTESTOBJ) testerka
prepare_bigtests: testy/mktests.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) testy/mktests.cpp -o testy/mktests
	./testy/mktests > testy/avl_kgadek_tc2.cpp
	indent -kr testy/avl_kgadek_tc2.cpp
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

