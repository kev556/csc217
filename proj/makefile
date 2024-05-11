lab2: proj.o node.o
	gcc -Wall -pedantic proj.o node.o -o proj

proj.o: proj.c node.h
	gcc -c proj.c -o proj.o
node.o: node.c node.h
	gcc -c node.c -o node.o

clean:
	rm -f proj.o node.o