lab2: lab2.o mystrlen.o cli.o user.o 
	gcc lab2.o mystrlen.o cli.o user.o -o lab2

lab2.o: csc217lab2_KevinLi.c cli.h user.h
	gcc -c csc217lab2_KevinLi.c -o lab2.o
mystrlen.o: mystrlen.c mystrlen.h
	gcc -c mystrlen.c -o mystrlen.o
cli.o: cli.c cli.h mystrlen.h
	gcc -c cli.c -o cli.o
user.o: user.c mystrlen.o user.h mystrlen.h
	gcc -c user.c -o user.o

clean:
	rm -f lab2.o mystrlen.o cli.o user.o