main: main.o Rational.o
	g++ -pedantic main.o Rational.o -o main
main.o: main.cpp  Rational.o
	g++ -Wall -pedantic main.cpp -c
Rational.o: Rational.cpp Rational.h
	g++ -Wall -pedantic Rational.cpp -c