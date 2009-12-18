crap : main.o Int.o String.o
	g++ -o crap main.o Int.o String.o -lmath

math.so : math.h math.c
	gcc -o math.so -Wl,-soname,math.so -shared math.c -fPIC -Wall -ansi -pedantic

main.o : main.cpp
	g++ -c main.cpp -Wall -pedantic

Int.o : Int.cpp
	g++ -c Int.cpp -Wall -pedantic

String.o : String.cpp
	g++ -c String.cpp -Wall -pedantic

clean :
	rm *\.o
