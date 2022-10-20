Project2: main.o fraction.o dictionary.o
			g++ -o Project2 main.o fraction.o dictionary.o
dictionary.o: dictionary.cpp dictionary.h
			g++ -c dictionary.cpp
fraction.o: fraction.h fraction.cpp
			g++ -c fraction.cpp
main.o:		main.cpp dictionary.h stack.h
			g++ -c main.cpp
