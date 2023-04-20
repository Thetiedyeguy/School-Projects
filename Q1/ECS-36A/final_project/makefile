paint.out: main.o canvas.o command.o draw.o
	gcc -g -Wall -Werror -o paint.out main.o canvas.o draw.o command.o

main.o: main.c canvas.h command.h draw.h
	gcc -g -Wall -Werror -c main.c

canvas.o: canvas.c canvas.h
	gcc -g -Wall -Werror -c canvas.c

draw.o: draw.c draw.h
	gcc -g -Wall -Werror -c draw.c

command.o: command.c command.h draw.h
	gcc -g -Wall -Werror -c command.c


clean:
	rm -fr *.o *.out
