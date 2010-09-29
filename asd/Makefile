# Kompilator C, C++ i Pascala
CC			= gcc
CXX			= g++
CPAS			= ppc386
# Opcje kompilacji C ANSI pedantic, C++ i Pascala
CFLAGS		= -ansi -pedantic -Wall -W -Wconversion -Wshadow\
			  -Wcast-qual -Wwrite-strings
CXXFLAGS	= -W -Wall -Wshadow -Weffc++ -Wformat -Wsequence-point\
			  -Wunused -Wuninitialized -Wfloat-equal -ansi -pedantic
PASFLAGS		= -XS -O2
# Flagi linkera
LDFLAGS		= -O2 -lm
# CppUnit: lista modulow testerki
TESTOBJ		= testy/LAS_kgadek_tc1.cpp.o testy/MSP_kgadek_tc1.cpp.o\
			  testy/lider_kgadek_tc1.cpp.o
# Lista rzeczy do zrobienia po wydaniu komendy `make all`
ALLOBJ		= testerka LCA_kgadek
# Lista plikow zrodlowych generowanych automatycznie
GENSOURCE	= LCA_kgadek.cpp
################################################################################

.PHONY: clean all LCA_kgadek cwebclean cwebhardclean
all: $(ALLOBJ)
cwebclean:
	rm -f *.idx *.log *.scn *.tex *.toc
cwebhardclean: cwebclean
	rm -f *.pdf *.dvi
	rm -f $(GENSOURCE)
clean: cwebclean
	rm -f *.o *~ testy/*.o testy/*.~
	find . -mount -perm -111 -and -type f -exec rm {} \;
	find . -mount -name '*.o' -and -type f -exec rm {} \;

LCA_kgadek: LCA_kgadek.w
	cweave $@.w && pdftex $@.tex
	ctangle $@.w - $@.cpp && $(CXX) $(CXXFLAGS) $(LDFLAGS) $@.cpp -o $@

################################################################################
#  Tester (CppUnit)                                                            #
################################################################################
testerka: $(TESTOBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -lcppunit testerka.cpp $? -o $@
################################################################################
#  Reguly ogolne                                                               #
################################################################################
%.c.o: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $? -o $@
%.cpp.o: %.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c $? -o $@

