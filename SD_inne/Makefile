# Kompilator C, C++ i Pascala
CC			= gcc
CXX			= g++
# Opcje kompilacji C ANSI pedantic, C++ i Pascala
CFLAGS			= -ansi -pedantic -Wall -W -Wconversion -Wshadow\
			  -Wcast-qual -Wwrite-strings
CXXFLAGS		= -W -Wall -Wshadow -Weffc++ -Wformat -Wsequence-point\
			  -Wunused -Wuninitialized -Wfloat-equal -ansi -pedantic
# Flagi linkera
LDFLAGS			= -O2 -lm -g

# Regula clean
.PHONY: clean all testerka
clean:
	rm -f *.o *~ testy/*.o testy/*.~
	rm -rf doc
	find . -mount -perm -111 -and -type f -exec rm {} \;
	find . -mount -name '*.o' -and -type f -exec rm {} \;

# Regula all
all: $(ALLMOD) $(ALLOBJ)
	doxygen

################################################################################
#  Reguly ogolne                                                               #
################################################################################
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c $? -o $@

