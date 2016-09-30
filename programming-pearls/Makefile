.PHONY: clean
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror -O2

column1: col1.o
	g++ -o column1 col1.o

col1.o: bitvector.hpp random.hpp measure.hpp

clean:
	find . -name "*.o*" -exec rm {} \;
	rm column*
