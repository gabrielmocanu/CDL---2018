build: code.o
	gcc code.c -lm -Wall -o code

code.o: code.c
	gcc -c code.c

run: code
	./code

clean:
	rm *.o code
