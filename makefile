CXX      := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra

LIB_OBJS := matrix.o matrix_ops.o messages.o
APP_OBJS := commands.o main.o

all: matrix_calc

libmatrix.a: $(LIB_OBJS)
	ar rcs $@ $^

matrix_calc: $(APP_OBJS) libmatrix.a
	$(CXX) $(CXXFLAGS) $(APP_OBJS) -L. -lmatrix -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o libmatrix.a matrix_calc

.PHONY: all clean