
CC = gcc
CCX = g++
CFLAGS = `gcc -march=native -E -v - </dev/null 2>&1 | sed -n 's/.* -v - //p'` -O2 -pipe

crap : main.o Int.o String.o Double.o
	 $(CCX) $(CFLAGS) -o crap main.o Int.o String.o

math.so : math.c math.h
	$(CC) $(CFLAGS) -o math.so -Wl,-soname,math.so -shared math.c -fPIC -Wall -ansi -pedantic

main.o : main.cpp std.h
	$(CCX) $(CFLAGS) -c main.cpp -Wall -pedantic

Int.o : Int.cpp std.h
	$(CCX) $(CFLAGS) -c Int.cpp -Wall -pedantic

String.o : String.cpp std.h
	$(CCX) $(CFLAGS) -c String.cpp -Wall -pedantic

Double.o : Double.cpp std.h
	$(CCX) $(CFLAGS) -c Double.cpp -Wall -pedantic

clean :
	-rm *\.o
	-rm *\.so
	-rm crap

install:
	make clean
	make
	make math.so
	
