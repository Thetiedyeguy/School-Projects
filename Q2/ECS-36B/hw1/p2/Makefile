# DO NOT MODIFY THIS FILE
CXX=g++
CXXFLAGS=-Wall
EXECS=testFraction
all: $(EXECS)
testFraction: testFraction.o Fraction.o
	$(CXX) -o $@ $^
clean:
	rm -f *.o $(EXECS)
