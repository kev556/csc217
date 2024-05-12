proj: proj.o list.o str.o
	gcc -Wall -pedantic -o proj -g proj.o list.o str.o

proj.o: proj.c list.h
	gcc -c -g proj.c -o proj.o
list.o: list.c list.h
	gcc -c -g list.c -o list.o
str.o: str.c str.h
	gcc -c -g str.c -o str.o

clean:
	rm -f proj.o list.o