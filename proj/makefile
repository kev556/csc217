proj: proj.o fileinput.o list.o str.o readargs.o
	gcc -Wall -pedantic -o proj -g proj.o fileinput.o list.o str.o readargs.o

proj.o: proj.c list.h fileinput.h str.h
	gcc -c -g proj.c -o proj.o
fileinput.o: fileinput.c list.h fileinput.h
	gcc -c -g fileinput.c -o fileinput.o
list.o: list.c list.h str.h
	gcc -c -g list.c -o list.o
str.o: str.c str.h
	gcc -c -g str.c -o str.o
readargs.o: readargs.c readargs.h
	gcc -c -g readargs.c -o readargs.o

clean:
	rm -f proj.o list.o str.o fileinput.o readargs.o