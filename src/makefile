CXX=g++
CXXFLAGS=-std=c++17 -g
SANITFLAGS=-fsanitize=address -fsanitize=leak -fsanitize=undefined
VALGRINDFLAGS= --tool=memcheck --track-origins=yes --leak-check=full

all: main.cpp percolation.cpp WeightedQuickUnionUF.cpp Fill.cpp
	$(CXX) $(CXXFLAGS) main.cpp percolation.cpp WeightedQuickUnionUF.cpp Fill.cpp

sanitizers: main.cpp percolation.cpp WeightedQuickUnionUF.cpp Fill.cpp
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) main.cpp percolation.cpp WeightedQuickUnionUF.cpp Fill.cpp

debug:all
	$(CXX) -g -ggdb main.cpp percolation.cpp WeightedQuickUnionUF.cpp Fill.cpp
	gdb -tui --args ./a.out 1 0.5 20

valgrid:all
	valgrind $(VALGRINDFLAGS) ./a.out 1 0.5 20

test:Fill.cpp percolation.cpp WeightedQuickUnionUF.cpp percolation_test.cpp
	g++ -c Fill.cpp percolation.cpp WeightedQuickUnionUF.cpp
	g++ $$(pkg-config --cflags catch2) -c percolation_test.cpp
	g++ WeightedQuickUnionUF.o percolation.o Fill.o percolation_test.o -o percolation_test.x
	./percolation_test.x
clean:
	rm -rf *.x a.out *.x.*
