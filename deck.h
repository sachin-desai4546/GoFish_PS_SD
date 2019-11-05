{\rtf1\ansi\ansicpg1252\cocoartf1671\cocoasubrtf600
{\fonttbl\f0\fmodern\fcharset0 Courier;}
{\colortbl;\red255\green255\blue255;\red0\green0\blue0;}
{\*\expandedcolortbl;;\cssrgb\c0\c0\c0;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\sl280\partightenfactor0

\f0\fs24 \cf2 \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 // FILE: deck.h\
// written by Owen Astrachan and Roger Priebe\
// this class respresents a deck of cards\
// When a Deck is constructed, it contains 52 cards\
// in a "regular" order (aces, twos, threes, ... , kings)\
//\
// Shuffling a deck makes it consist of 52 cards in a random order\
//\
// dealCard() returns a card from the deck and decreases the\
// number of cards in the deck (returned by size())\
// The idea is that after shuffling, calling dealCard() 52 times\
// returns each card in the deck after shuffling.\
//\
// Calling shuffle again replenishes the deck with 52 cards.\
\
#ifndef _DECK_H\
#define _DECK_H\
\
#include "card.h"\
\
\
class Deck\
\{\
  static const int SIZE = 52;\
  \
  public:\
    \
    \
    Deck();           // pristine, sorted deck\
\
    void shuffle();   // shuffle the deck, all 52 cards present\
    Card dealCard();   // get a card, after 52 are dealt, fail \
\
    int  size() const; // # cards left in the deck\
\
  private:\
\
    Card myCards[SIZE];\
    int myIndex;  // current card to deal\
\};\
\
#endif\
}