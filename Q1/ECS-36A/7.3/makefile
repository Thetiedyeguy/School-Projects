find_determinant.out: main.o find_determinant.o
	gcc -g -Wall -Werror -o find_determinant.out main.o find_determinant.o

main.o: main.c find_determinant.h
	gcc -g -Wall -Werror -c main.c

find_determinant.o: find_determinant.c find_determinant.h
	gcc -g -Wall -Werror -c find_determinant.c

clean:
	rm -fr *.o *.out
