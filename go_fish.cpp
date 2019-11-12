// FILE: GoFishDriver.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( )
{
    ofstream oFile;
    oFile.open("gofish_results.txt");
    Card output;
    int win = 1;
    int numCards = 7;

    Player p1("Philip");
    Player p2("Sachin");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    Card x;
    Card y;

    while (p1.getBookSize() + p2.getBookSize() < 26) {

        oFile << p1.getName() << "'s hand : " << p1.showHand() << endl;
        oFile << p2.getName() << "'s hand : " << p2.showHand() << endl;

        while(p1.checkHandForBook(x, y)){
            if(p1.checkHandForBook(x, y)){
                p1.bookCards(x, y);
            }
        }
        while(p2.checkHandForBook(x, y)){
            if(p2.checkHandForBook(x, y)){
                p2.bookCards(x, y);
            }
        }
        oFile << "-------------------" << endl;
        oFile << p1.getName() << "'s books : " << p1.showBooks() << endl;
        oFile << p2.getName() << "'s books : " << p2.showBooks() << endl;
        win = 1;
        while(win == 1){
            if(p1.getHandSize() != 0){
                Card phil = p1.chooseCardFromHand();
                oFile << "-------------------" << endl;
                oFile << "Phil: Do you have any : " << phil.rankString(phil.getRank()) << "'s" << endl;

                if(p2.cardInHand(phil)) {
                    oFile << "Sachin: Yes" << endl;
                    p1.addCard(p2.removeCardFromHand(phil));
                    p2.removeCardFromHand(phil);
                    oFile << p1.getName() << "'s hand : " << p1.showHand() << endl;
                    oFile << p2.getName() << "'s hand : " << p2.showHand() << endl;
                } else {
                    oFile << "Sachin: Go Fish!" << endl;
                    win = 0;
                    output = d.dealCard();
                    p1.addCard(output);
                    oFile << "Phil draws " << output << endl;
                    oFile << p1.getName() << "'s hand : " << p1.showHand() << endl;
                }

                if(p1.checkHandForBook(x, y)){
                    p1.bookCards(x, y);
                    oFile << p1.getName() << "'s books : " << p1.showBooks() << endl;
                }

            } else {
                if(d.size() != 0){
                    oFile << "Phil: My hand is empty, I'll draw one" << endl;
                    p1.addCard(d.dealCard());
                    win = 0;
                } else {
                    oFile << "Phil: There's no cards left to draw!" << endl;
                    oFile << p1.getName() << "'s books : " << p1.showBooks() << endl;
                    oFile << p2.getName() << "'s books : " << p2.showBooks() << endl;
                    if( p1.getBookSize() > p2.getBookSize()){
                        oFile << "Philip Wins!" << endl;
                    } else if(p1.getBookSize() == p2.getBookSize()) {
                        oFile << "It's a Tie!" << endl;
                    } else {
                        oFile << "Sachin Wins!" << endl;
                    }
                    return 0;
                }
            }
        }

        win = 1;
        while(win == 1){
            if(p2.getHandSize() != 0){
                Card such = p2.chooseCardFromHand();
                oFile << "-------------------" << endl;
                oFile << "Sachin: Do you have any : " << such.rankString(such.getRank()) << "'s" << endl;

                if(p1.cardInHand(such)) {
                    oFile << "Phil: Yes" << endl;
                    p2.addCard(p1.removeCardFromHand(such));
                    p1.removeCardFromHand(such);
                    oFile << p1.getName() << "'s hand : " << p1.showHand() << endl;
                    oFile << p2.getName() << "'s hand : " << p2.showHand() << endl;
                }
                else {
                    oFile << "Phil: Go Fish!" << endl;
                    win = 0;
                    output = d.dealCard();
                    p2.addCard(output);
                    oFile << "Sachin draws " << output << endl;
                }

                if(p2.checkHandForBook(x, y)){
                    p2.bookCards(x, y);
                    oFile << p2.getName() << "'s books : " << p2.showBooks() << endl;
                }

            } else{
                if(d.size() != 0) {
                    oFile << "Sachin: My hand is empty, I'll draw one" << endl;
                    p2.addCard(d.dealCard());
                    win = 0;
                } else {
                    oFile << "Sachin: There's no cards left to draw!" << endl;
                    oFile << p1.getName() << "'s books : " << p1.showBooks() << endl;
                    oFile << p2.getName() << "'s books : " << p2.showBooks() << endl;
                    if( p1.getBookSize() > p2.getBookSize()){
                        oFile << "Philip Wins!" << endl;
                    } else if(p1.getBookSize() == p2.getBookSize()) {
                        oFile << "It's a Tie!" << endl;
                    } else {
                        oFile << "Sachin Wins!" << endl;
                    }
                    return 0;
                }

            }
        }


    }
    oFile << p1.getName() << "'s books : " << p1.showBooks() << endl;
    oFile << p2.getName() << "'s books : " << p2.showBooks() << endl;
    if( p1.getBookSize() > p2.getBookSize()){
        oFile << "Philip Wins!" << endl;
    } else if(p1.getBookSize() == p2.getBookSize()) {
        oFile << "It's a Tie!" << endl;
    } else {
        oFile << "Sachin Wins!" << endl;
    }
    oFile.close();
    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}



