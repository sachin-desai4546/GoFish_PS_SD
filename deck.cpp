// FILE: deck.h
// written by Owen Astrachan and Roger Priebe
// this class respresents a deck of cards
// When a Deck is constructed, it contains 52 cards
// in a "regular" order (aces, twos, threes, ... , kings)
//
// Shuffling a deck makes it consist of 52 cards in a random order
//
// dealCard() returns a card from the deck and decreases the
// number of cards in the deck (returned by size())
// The idea is that after shuffling, calling dealCard() 52 times
// returns each card in the deck after shuffling.
//
// Calling shuffle again replenishes the deck with 52 cards.

#include "card.h"
#include "deck.h"
#include <cstdlib>
#include <ctime>

// pristine, sorted deck
Deck::Deck(){
    srand(time(0));
    myIndex = 0;
    for (int i = 0; i < 4; i++) {
        Card::Suit x;
        if(i == 0){
            x = Card::spades;
        }
        if(i == 1){
            x = Card::hearts;
        }
        if(i == 2){
            x = Card::diamonds;
        }
        if(i == 3){
            x = Card::clubs;
        }
        for (int j = i*13; j < (((i+1)*13)); j++){
            if((j+1)%13 == 0){
                myCards[j] = Card(13, x);
            } else {
                myCards[j] = Card(((j+1)%13), x);
            }
        }
    }
}

// shuffle the deck, all 52 cards present
void Deck::shuffle(){
    int count = 52;
    for(int i = 0; i < (count*5); i++){
        int randNum1 = (rand() % count);
        int randNum2 = (rand() % count);
        Card temp = myCards[randNum1];
        myCards[randNum1] = myCards[randNum2];
        myCards[randNum2] = temp;
    }
}

// get a card, after 52 are dealt, fail
Card Deck::dealCard(){
    Card temp;
    temp = myCards[myIndex];
    if(myIndex < 52){
        myIndex++;
        return temp;
    } else {
        Card fail = Card(14, Card::spades);
        return fail;
    }
}

// # cards left in the deck
int Deck::size() const {
    return (52 - myIndex);
}
