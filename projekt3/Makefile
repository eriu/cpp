
FLAGS   := -O2 -DNDEBUG -ftree-vectorize -Wall
OBJECTS := Projekt3_1.o problem.o

a.out: $(OBJECTS)
	g++ $(FLAGS) $(OBJECTS) -o a.out

Projekt3_1.o: Projekt3_1.cpp
	g++ $(FLAGS) -c Projekt3_1.cpp

problem.o: problem.cpp
	g++ $(FLAGS) -c problem.cpp

clean:
	rm -rf *o a.out
