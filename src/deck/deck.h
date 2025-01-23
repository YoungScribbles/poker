#ifndef DECK_H
#define DECK_H

#include <vector>
#include "pile.h"

const char SUITS[] = { 'c', 'd', 'h', 's' };
const int VALS[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };

const int DECK_SIZE = 52;

class Deck : public Pile
{
public:
    Deck();
    ~Deck();

    void generateDeck();
    void shuffle();
};

#endif // DECK_H