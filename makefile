.PHONY:clean
calculator:functions.o Simple_Calculator.o
	g++ -o calculator functions.o Simple_Calculator.o
functions.o:functions.cpp functions.h struct.h
	g++ -c functions.cpp -o functions.o
Simple_Calculator.o:  Simple_Calculator.cpp
	g++ -c Simple_Calculator.cpp -o Simple_Calculator.o
clean:
		-rm -f *.o
