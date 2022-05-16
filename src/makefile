CXX= g++
CXXFLAGS= -std=c++17 -g
SANITFLAGS= -fsanitize=address -fsanitize=leak -fsanitize=undefined
VALGRINDFLAGS= --tool=memcheck --track-origins=yes --leak-check=full

TARGET = main.x
FILES = Percolation.o WQUF.o Fill.o
TEST = PercolationTest
TEST_FILE = ../tests/$(TEST).cpp


all: main.x

sanitizers: mainStz.x

debug: main.x
	gdb -tui --args $^ 39 0.4 3

valgrind: main.x
	valgrind $(VALGRINDFLAGS) ./$(TARGET) 1 0.4 20

test: $(TEST).x
	./$<

$(TEST).x: $(TEST).o $(FILES)
	$(CXX) $^ -o $@


mainStz.x: main.o $(FILES)
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o $@
# necesita banderas -g?

main.x: main.o $(FILES)
	$(CXX) $^ -o $@

# We assume spack on path
$(TEST).o: $(TEST_FILE)
	$(CXX) $$(pkg-config --cflags catch2) -c $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -rf *.x a.out *.x.* *.o
