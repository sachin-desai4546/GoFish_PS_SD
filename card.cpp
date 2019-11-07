//File Name: card.cpp
//
// This class represents a playing card, i.e., "ace of spades"
// a Card is constructed from a rank (int in range 1..13)
// and a suit (Card::spades, Card::hearts, Card::diamonds,
// Card::clubs)
//
// Cards should be created by a Deck (see deck.h), a Deck returns
// good cards
// The function toString() converts a card to a string, e.g., to print
//
// Accessor functions include
//
// int GetRank()      -- returns 1, 2, ..., 13 for ace, two, ..., king
//
// bool SameSuitAs(c) -- returns true if same suit as Card c
//
// string suitString() -- returns "s", "h", "d" or "c"
//
// Note that the Ace is represented by 1 and the King by 13
#include <iostream>
#include <string>
#include "card.h"
using namespace std;

// default, ace of spades
Card::Card(){
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}

// return string version e.g. Ac 4h Js
string Card::toString() const {
    return(suitString(mySuit) + rankString(myRank));
}

// true if suit same as c
bool Card::sameSuitAs(const Card& c) const {
    if (mySuit == c.mySuit){
        return true;
    }
    return false;
}

// return rank, 1..13
int Card::getRank() const {
    return(myRank);
}

// return "s", "h",...
string Card::suitString(Suit s) const {
    if (s == spades) {
        return ("s");
    } else if (s == hearts) {
        return ("h");
    } else if (s == diamonds) {
        return ("d");
    }
    return ("c");
}

// return "A", "2", ..."Q"
string Card::rankString(int r) const {
    if (r == 1) {
        return ("A");
    } else if (r == 2) {
        return ("2");
    } else if (r == 3) {
        return ("3");
    } else if (r == 4) {
        return ("4");
    } else if (r == 5) {
        return ("5");
    } else if (r == 6) {
        return ("6");
    } else if (r == 7) {
        return ("7");
    } else if (r == 8) {
        return ("8");
    } else if (r == 9) {
        return ("9");
    } else if (r == 10) {
        return ("10");
    } else if (r == 11) {
        return ("J");
    } else if (r == 12) {
        return ("Q");
    } else if (r == 13) {
        return ("K");
    }
    return ("0");
}
// overload operator functions listed below
bool Card::operator == (const Card& rhs) const{
    return(myRank == rhs.myRank);
}
bool Card::operator != (const Card& rhs) const{
    return(myRank != rhs.myRank);
}

void Card::operator = (const Card& rhs){
    myRank = rhs.myRank;
    mySuit = rhs.mySuit;
    return;
}
//ostream& operator << (ostream& out, const Card &c){
//    out << c.get
//}

Card::~Card();