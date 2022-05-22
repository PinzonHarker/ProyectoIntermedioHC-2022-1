SHELL:= /bin/zsh
CXX= g++
CXXFLAGS= -std=c++17 -g
SANITFLAGS= -fsanitize=address -fsanitize=leak -fsanitize=undefined
VALGRINDFLAGS= --tool=memcheck --track-origins=yes --leak-check=full

TARGET = main.x
FILES = Percolation.o WQUF.o Fill.o
TESTPERCOLATION = PercolationTest
TESTWQUF = WQUFTest
TEST_FILE_PERCOLATION = ../tests/$(TESTPERCOLATION).cpp
TEST_FILE_WQUF = ../tests/$(TESTWQUF).cpp

all: main.x

sanitizers: mainStz.x

debug: main.x
	gdb -tui --args $^ 2 0.5 7

valgrind: main.x
	valgrind $(VALGRINDFLAGS) ./$(TARGET) 1 0.4 20

test: $(TESTWQUF).x ./$(TESTPERCOLATION).x
	./$(TESTPERCOLATION).x
	./$(TESTWQUF).x

$(TESTWQUF).x $(TESTPERCOLATION).x: $(TESTPERCOLATION).o $(TESTWQUF).o $(FILES)
	$(CXX) $(TESTPERCOLATION).o $(FILES) -o $(TESTPERCOLATION).x
	$(CXX) $(TESTWQUF).o $(FILES) -o $(TESTWQUF).x

mainStz.x: main.o $(FILES)
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o $@
# necesita banderas -g?

main.x: main.o $(FILES)
	$(CXX) $^ -o $@

# We assume spack on path

$(TESTPERCOLATION).o: $(TEST_FILE_PERCOLATION)
	$(CXX) $$(pkg-config --cflags catch2) -c $<

$(TESTWQUF).o: $(TEST_FILE_WQUF)
	$(CXX) $$(pkg-config --cflags catch2) -c $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -rf *.x *.o

cleanall:
	rm -rf *.x *.out *.o
