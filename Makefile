CFLAGS = -O
CC = g++

HATStest: main.o  HATS.o
	$(CC) $(CFLAGS) -o HATStest main.o HATS.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

HATS.o: HATS.cpp
	$(CC) $(CFLAGS) -c HATS.cpp

clean:
	rm -f core *.o
