program: genome.o main.o population.o
	g++ -o program genome.o main.o population.o
 
population.o: population.h population.cpp
	g++ -c -g population.cpp
 
genome.o: genome.h genome.cpp
	g++ -c -g genome.cpp
 
main.o: main.cpp
	g++ -c -g main.cpp
 
clean:
	rm -f *.o program