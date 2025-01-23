#ifndef PILE_H
#define PILE_H

#include <vector>
#include "card.h"

using namespace std;

class Pile 
{
public:
    Pile();
    ~Pile();

    // Remove cards from deck
    Card drawTop();
    Card drawRandom();

    // Place cards on deck
    void placeTop(Card card);
    void placeTop(vector<Card> cards);
    void placeTop(Pile pile);

    bool empty() { return mCards.empty(); }

    // Debug
    void printCards();

protected:
    vector<Card> mCards;
};

#endif // PILE_H