all:
	@g++ -std=c++11 kwic.cpp -o kwic.o && ./kwic.o
run:
	@./kwic.o
