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
ALLOBJ			= rlazarz_skiplist bniemcz_queue bniemcz_list\
			  midz_skiplist mmk_list.cpp.o

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
#  Reguly ogolne                                                               #
################################################################################
%.c.o: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $? -o $@
%.cpp.o: %.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c $? -o $@

