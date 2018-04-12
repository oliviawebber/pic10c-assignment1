objects = siete-y-medio.o cards.o hand.o player.o
flags = -Wall -std=c++11

siete-y-medio: $(objects)
	g++ -o siete-y-medio.out $(objects)

siete-y-medio.o: siete-y-medio.cpp cards.h
	g++ $(flags) -c siete-y-medio.cpp

cards.o: cards.cpp cards.h
	g++ $(flags) -c cards.cpp

hand.o: hand.cpp cards.h
	g++ $(flags) -c hand.cpp

player.o: player.cpp cards.h
	g++ $(flags) -c player.cpp
