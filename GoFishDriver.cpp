{\rtf1\ansi\ansicpg1252\cocoartf1671\cocoasubrtf600
{\fonttbl\f0\fmodern\fcharset0 Courier;}
{\colortbl;\red255\green255\blue255;\red0\green0\blue0;}
{\*\expandedcolortbl;;\cssrgb\c0\c0\c0;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\sl280\partightenfactor0

\f0\fs24 \cf2 \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 // FILE: card_demo.cpp\
// This is a small demonstration program showing how the Card and Deck classes are used.\
#include <iostream>    // Provides cout and cin\
#include <cstdlib>     // Provides EXIT_SUCCESS\
#include "card.h"\
#include "player.h"\
#include "deck.h"\
\
using namespace std;\
\
\
// PROTOTYPES for functions used by this demonstration program:\
void dealHand(Deck &d, Player &p, int numCards);\
\
\
\
\
int main( )\
\{\
    int numCards = 5;\
    \
    Player p1("Joe");\
    Player p2("Jane");\
    \
    Deck d;  //create a deck of cards\
    d.shuffle();\
    \
    dealHand(d, p1, numCards);\
    dealHand(d, p2, numCards);\
       \
    cout << p1.getName() <<" has : " << p1.showHand() << endl;\
    cout << p2.getName() <<" has : " << p2.showHand() << endl;\
    \
    return EXIT_SUCCESS;  \
\}\
\
\
\
void dealHand(Deck &d, Player &p, int numCards)\
\{\
   for (int i=0; i < numCards; i++)\
      p.addCard(d.dealCard());\
\}\
   \
\
\
}