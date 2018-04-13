COMP = g++
OBJ = siete-y-medio.o cards.o hand.o player.o
FLAGS = -Wall -std=c++11
DEPS = cards.h

%.o: %.cpp $(DEPS)
	$(COMP) $(FLAGS) -c $<

siete-y-medio: $(OBJ)
	$(COMP) -o siete-y-medio.out $(OBJ)
