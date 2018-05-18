
CXX_FLAG = -Wall -Wextra

PROGS = test_eventfd.out test_eventfd2.out

all: test_eventfd.out test_eventfd2.out test_eventfd3.out

test_eventfd.out: test_eventfd.cpp
	g++ $(CXX_FLAG) test_eventfd.cpp -o test_eventfd.out

test_eventfd2.out: test_eventfd2.cpp
	g++ $(CXX_FLAG) test_eventfd2.cpp -o test_eventfd2.out

test_eventfd3.out: test_eventfd3.cpp
	g++ $(CXX_FLAG) test_eventfd3.cpp -lpthread -o test_eventfd3.out

clean:
	rm -f *.out *.o core.*
