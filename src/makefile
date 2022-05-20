SHELL:= /bin/zsh
CXX= g++
CXXFLAGS= -std=c++17 -g
SANITFLAGS= -fsanitize=address -fsanitize=leak -fsanitize=undefined
VALGRINDFLAGS= --tool=memcheck --track-origins=yes --leak-check=full

TARGET = main.x
FILES = Percolation.o WQUF.o Fill.o
TEST1 = PercolationTest
TEST1_FILE = ../tests/$(TEST1).cpp
TEST2 = WQUFTest
TEST2_FILE = ../tests/$(TEST2).cpp


all: main.x

simul: Simul.x
	./$< 0 0.6 4

report: report.pdf

profile:

debug: main.x
	gdb -tui --args $^ 39 0.4 3


sanitizers: mainStz.x

valgrind: main.x
	valgrind $(VALGRINDFLAGS) ./$(TARGET) 1 0.4 20

test: $(TEST1).x $(TEST2).x
	./$<
	./$(TEST2).x

Simul.x: Simul.o $(FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(TEST1).x: $(TEST1).o $(FILES)
	$(CXX) $^ -o $@

$(TEST2).x: $(TEST2).o $(FILES)
	$(CXX) $^ -o $@

mainStz.x: main.o $(FILES)
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o $@
# necesita banderas -g?

main.x: main.o $(FILES)
	$(CXX) $^ -o $@

# We assume spack on path
$(TEST1).o: $(TEST1_FILE)
	$(CXX) $$(pkg-config --cflags catch2) -c $<

$(TEST2).o: $(TEST2_FILE)
	$(CXX) $$(pkg-config --cflags catch2) -c $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.x *.o *~ *.out
