#ifndef TABLE_H
#define TABLE_H

#include <vector>

#include "../deck/deck.h"

using namespace std;

class Table
{
    friend class Game;

public:
    Table();
    ~Table();

    void play(Card card);
    void play(vector<Card> cards);
    void play(Pile cards);

    void muck(Card card);
    void muck(vector<Card> cards);
    void muck(Pile cards);

// Getter
    Pile cards() { return mLive; }

private:
    Pile dead() { return mMuck; }   // DEBUG: dead cards should probably be obscured
    Pile recycleCards();
    void report(); // DEBUG: dead cards should probably be obscured

private:
    Pile mLive;
    Pile mMuck;
};

#endif // TABLE_H