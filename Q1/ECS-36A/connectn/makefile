connectn.out: main.o connectn.o
	gcc -g -Wall -Werror -o connectn.out main.o connectn.o

main.o: main.c connectn.h
	gcc -g -Wall -Werror -c main.c

connectn.o: connectn.c connectn.h
	gcc -g -Wall -Werror -c connectn.c

clean:
	rm -fr *.o *.out