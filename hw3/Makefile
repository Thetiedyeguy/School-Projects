CXX=g++
CXXFLAGS=-Wall
all: mum nextMutation

mum: mum.o Sequence.o
	$(CXX) -o $@ $^
nextMutation: nextMutation.o Sequence.o
	$(CXX) -o $@ $^

clean:
	rm -f mum nextMutation *.o
