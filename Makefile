crap : main.o Int.o String.o
	g++ -o crap main.o Int.o String.o -lmath

math.so : math.h math.c
	gcc -o math.so -Wl,-soname,math.so -shared math.c -fPIC -Wall -ansi -pedantic

main.o : main.cpp
	g++ -o main.o main.cpp -Wall -pedantic

Int.o : Int.cpp
	g++ -o Int.o Int.cpp -Wall -pedantic

String.o : String.cpp
	g++ -o String.o String.cpp -Wall -pedantic

clean :
	rm *\.o
