// FILE:  player.h
// written by Roger Priebe
// 1/22/08 (revised 9/2/08)
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>

#include "card.h"
#include "player.h"
using namespace std;

Player::Player(){
    string myName = "";
    vector<Card> myHand;
    vector<Card> myBook;
    srand(time(0));
}

//adds a card to the hand
void Player::addCard(Card c){
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2){
    myBook.push_back(c1);
    myBook.push_back(c2);
    removeCardFromHand(c1);
    removeCardFromHand(c2);
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards that make the pair.

bool Player::checkHandForBook(Card &c1, Card &c2) {
    for (int i = 0; i < getHandSize(); i++) {
        for (int j = 0; j < getHandSize(); j++) {
            if ((myHand[i] == myHand[j]) && (i != j)){
                c1 = myHand[i];
                c2 = myHand[j];
                return true;
            }
        }
    }
    return false;
}

//OPTIONAL
// comment out if you decide to not use it
// Does the player have a card with the same rank as c in her hand?
bool Player::rankInHand(Card c) const{

}

//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand(){
    int randNum = (rand() % getHandSize());
    return myHand[randNum];

}

bool Player::cardInHand(Card c) const{
    if(getHandSize() == 0){
        return false;
    }
    for (int i = 0; i < getHandSize(); i++) {
        if (c == myHand[i]){
            return true;
        }
    }
    return false;
}

//Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c){
    if (cardInHand(c)){
        for (int i = 0; i < getHandSize(); i++) {
            if (c == myHand[i]){
                Card temp = myHand[i];
                myHand.erase(myHand.begin() + i);
                return (temp);
            }
        }
    }
}

string Player::showHand() const{
    string total = "";
    for (int i=0; i<myHand.size(); i++) {
        total = total + myHand.at(i).toString() + ' ';
    }
    return(total);
}
string Player::showBooks() const{
    string total = "";
    for (int i=0; i<myBook.size(); i++) {
        total = total + myBook.at(i).toString() + ' ';
    }
    return(total);
}

int Player::getHandSize() const{
    return(myHand.size());
}
int Player::getBookSize() const{
    return(myBook.size()/2);
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
// If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

//bool Player::checkHandForPair(Card &c1, Card &c2){

//}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
//e.g. will return true if the player has a 7d and the parameter is 7c

bool Player::sameRankInHand(Card c) const{

}

