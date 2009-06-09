# Regel 1
projekt.exe: rational.o main.o
	g++ -o projekt.exe rational.o main.o

# Regel 2
rational.o: rational.cpp  rational.h
	g++ -c rational.cpp

# Regel 3
main.o: main.cpp  rational.h
	g++ -c main.cpp

# Regel 4
clean:
	rm -f rational.o main.o

