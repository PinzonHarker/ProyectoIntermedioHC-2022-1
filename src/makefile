CXX= g++
CXXFLAGS= -std=c++17 -g
SANITFLAGS= -fsanitize=address -fsanitize=leak -fsanitize=undefined
VALGRINDFLAGS= --tool=memcheck --track-origins=yes --leak-check=full

TARGET = main.x
FILES = percolation.o WeightedQuickUnionUF.o Fill.o
TEST = percolation_test
TEST_FILE = ../tests/$(TEST).cpp


all: main.x

sanitizers: mainStz.x

debug: all
	$(CXX) $(CXXFLAGS) -ggdb $(FILES)
	gdb -tui --args ./a.out 39 0.4 3

valgrid: all
	valgrind $(VALGRINDFLAGS) ./a.out 1 0.4 20

# test:Fill.cpp percolation.cpp WeightedQuickUnionUF.cpp percolation_test.cpp
# 	$(CXX) -c Fill.cpp percolation.cpp WeightedQuickUnionUF.cpp
# 	$(CXX) $$(pkg-config --cflags catch2) -c percolation_test.cpp
# 	$(CXX) WeightedQuickUnionUF.o percolation.o Fill.o percolation_test.o -o percolation_test.x
# 	./percolation_test.x

test: percolation_test.x
	./$<

percolation_test.x: percolation_test.o $(FILES)
	$(CXX) $^ -o $@


mainStz.x: main.o $(FILES)
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o $@
# necesita banderas -g?

main.x: main.o $(FILES)
	$(CXX) $^ -o $@

percolation_test.o: $(TEST_FILE)
	$(CXX) $$(pkg-config --cflags catch2) -c $<

%.o: %.cpp
	$(CXX) -c $<

clean:
	rm -rf *.x a.out *.x.* *.o
