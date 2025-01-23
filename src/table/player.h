#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

#include "../deck/pile.h"

using namespace std;

class Table;    // Forward dec.
class Player {
public:
    Player(string name, Table* table);
    ~Player();

    void giveCard(Card card);
    void discard();

    void report();

// Getters
public:
    string name() { return mName; }

private:
    int mPid;
    string mName;

    Pile mCards;
    Table* mTable;
};

#endif // PLAYER_H