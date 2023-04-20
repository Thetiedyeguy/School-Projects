# Makefile

CC	= gcc
CFLAG   = -g -c -Wall 
OBJ 	=  main.o scan_fraction.o \
	get_operator.o add_fractions.o multiply_fractions.o \
	find_gcd.o reduce_fraction.o

fractions:  $(OBJ) 
	$(CC) -o fractions $(OBJ)

main.o: main.c 
	$(CC) $(CFLAG) main.c

scan_fraction.o: scan_fraction.c
	$(CC) $(CFLAG) scan_fraction.c 

get_operator.o: get_operator.c 
	$(CC) $(CFLAG) get_operator.c

add_fractions.o: add_fractions.c
	$(CC) $(CFLAG) add_fractions.c

multiply_fractions.o:  multiply_fractions.c 
	$(CC) $(CFLAG) multiply_fractions.c 

find_gcd.o: find_gcd.c 	 
	$(CC) $(CFLAG) find_gcd.c 

reduce_fraction.o: reduce_fraction.c
	$(CC) $(CFLAG) reduce_fraction.c

clean: 
	rm -f *.o fractions

# end of Makefile
