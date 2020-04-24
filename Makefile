CXXFLAGS= -c -g -std=c++11 -iquote inc -Wall -pedantic

__start__: ./test_wektora
	./test_wektora

obj:
	mkdir -p obj

./test_wektora: obj obj/main.o  obj/WS.o
	g++ -o ./test_wektora obj/main.o obj/WS.o

obj/main.o: src/main.cpp inc/SWektor.hh inc/LZespolona.hh inc/rozmiar.h
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/WS.o: src/SWektor.cpp src/WS.cpp src/LZespolona.cpp inc/SWektor.hh inc/LZespolona.hh
		g++ -c ${CXXFLAGS} -o obj/WS.o src/WS.cpp 

