
CXX_FLAG = -Wall -Wextra -std=c++11

all: main.out

%.o: %.cpp
	g++ $(CXX_FLAG) -c $< -o $@

main.out: main.o singleton.o
	g++ main.o singleton.o -o main.out

clean:
	rm -f *.out *.o core.*
