# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 

final: 	GoFishDriver.o Player.o Deck.o Card.o
	g++ -otest GoFishDriver.o Player.o Deck.o Card.o
driver: GoFishDriver.cpp Player.h Deck.h Card.h
	g++ -c -std=c++11 GoFishDriver.cpp
Player.o: Player.cpp Player.h Deck.h Card.h
	  g++ -c -std=c++0x Player.cpp
Deck.o: Deck.cpp Deck.h Card.h
    	g++ -c -std=c++0x Deck.cpp
Card.o: Card.cpp Card.h
    	g++ -c -std=c++0x Card.cpp