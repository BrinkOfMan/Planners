test: Date.o Event.o Test.o
	g++ -g -Wall -std=c++11 -o test Date.o Event.o Test.o

Test.o: Test.cpp
	g++ -g -Wall -std=c++11 -c Test.cpp

Date.o: Date.cpp Date.h
	g++ -g -Wall -std=c++11 -c Date.cpp

Event.o: Event.cpp Event.h
	g++ -g -Wall -std=c++11 -c Event.cpp