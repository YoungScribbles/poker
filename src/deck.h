#ifndef DECK_H
#define DECK_H

#include <vector>
#include "card.h"

using namespace std;

const char SUITS[] = { 'c', 'd', 'h', 's' };
const int VALS[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };

const int DECK_SIZE = 52;

class Deck
{
public:
    Deck();
    ~Deck();

    void generateDeck();
    void shuffle();

    // Remove cards from deck
    Card drawTop();
    Card drawRandom();

    // Place cards on deck
    void placeTop(Card card);
    void placeTop(vector<Card> cards);

    // Debug
    void printDeck();

private:
    vector<Card> mCards;
};

#endif // DECK_H