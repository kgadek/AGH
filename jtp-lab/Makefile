CC	= gcc
CFLAGS	= -ansi -pedantic -Wall -W -Wconversion -Wshadow -Wcast-qual -Wwrite-strings
LDFLAGS	= -O2 -lm
OUTPUT	= 1.2_Igor 1.3_Radek 2.4_Igor

clean:
	rm -f *.o *~ $(OUTPUT)

%: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) $? -o $@
