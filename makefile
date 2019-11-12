# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 

final: 	go_fish.o player.o deck.o card.o
	g++ -otest go_fish.o player.o deck.o card.o
driver: go_fish.cpp player.h deck.h card.h
	g++ -c -std=c++11 go_fish.cpp
player.o: player.cpp player.h deck.h card.h
	  g++ -c -std=c++0x player.cpp
deck.o: deck.cpp deck.h card.h
    	g++ -c -std=c++0x deck.cpp
card.o: card.cpp card.h
    	g++ -c -std=c++0x card.cpp