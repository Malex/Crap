math.so : math.h math.c
	gcc -o math.so -Wl,-soname,math.so -shared math.c -fPIC -Wall -ansi -pedantic
