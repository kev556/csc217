lab2: proj.o node.o
	gcc -Wall -pedantic -o proj -g proj.o node.o

proj.o: proj.c node.h
	gcc -c -g proj.c -o proj.o
node.o: node.c node.h
	gcc -c -g node.c -o node.o

clean:
	rm -f proj.o node.o