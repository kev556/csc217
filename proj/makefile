proj: proj.o list.o str.o input.o
	gcc -Wall -pedantic -o proj -g proj.o list.o str.o input.o

proj.o: proj.c list.h input.h str.h
	gcc -c -g proj.c -o proj.o
list.o: list.c list.h str.h
	gcc -c -g list.c -o list.o
str.o: str.c str.h
	gcc -c -g str.c -o str.o
input.o: input.c input.h
	gcc -c -g input.c -o input.o

clean:
	rm -f proj.o list.o str.o input.o