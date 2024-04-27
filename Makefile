all: arcfour test

test: test.o
	gcc arcfour.o test.o -o test -Wall -O2

test.o: test.c
	gcc -c -O2 -Wall test.c


arcfour: arcfour.o
	gcc arcfour.o -o arcfour.so -O2 -Wall -fPIC -shared -ldl -D_GNU_SOURCE


arcfour.o: arcfour.c
	gcc -c -O2 -Wall arcfour.c


run:
	./test

clean:
	rm -f *.o *.so test && clear