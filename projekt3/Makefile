
FLAGS   := -O2 -DNDEBUG -ftree-vectorize -Wall
OBJECTS := projekt3.o problem.o heuristik.o

a.out: $(OBJECTS)
	g++ $(FLAGS) $(OBJECTS) -o a.out

projekt3.o: projekt3.cpp
	g++ $(FLAGS) -c projekt3.cpp

problem.o: problem.cpp
	g++ $(FLAGS) -c problem.cpp

heuristik.o: heuristik.cpp
	g++ $(FLAGS) -c heuristik.cpp

clean:
	rm -rf *o a.out
