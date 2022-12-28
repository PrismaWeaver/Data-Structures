ao1: AssignOpt01.o HashTable.o
	g++ AssignOpt01.o HashTable.o -o ao1
AssignOpt01.o: AssignOpt01.cpp HashTable.h
	g++ -Wall -ansi -pedantic -std=c++11 -c AssignOpt01.cpp
HashTable.o: HashTable.cpp HashTable.h
	g++ -Wall -ansi -pedantic -std=c++11 -c HashTable.cpp

clean:
	@rm -rf AssignOpt01.o HashTable.o

cleanall:
	@rm -rf AssignOpt01.o HashTable.o ao1
