project1.x: main.o dfa.o
	g++ -ggdb -o project1.x main.o dfa.o -ltermcap

main.o main.cpp
	g++ -std=c++17 -ggdb main.cpp -o main.o -c

dfa.o: DFA.cpp DFA.hpp
	g++ -std=c++17 -ggdb DFA.cpp -o dfa.o

clean:
	/bin/rm -f project1.x main.o *~