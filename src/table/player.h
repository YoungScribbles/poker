#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

#include "table.h"
#include "../deck/pile.h"

using namespace std;

class Player {
public:
    Player(string name, Table* table);
    ~Player();

    void giveCard(Card card);
    void discard();

// Getters
public:
    string name() { return mName; }

private:
    int mPid;
    string mName;

    Pile mCards;
    Table* mTable;
}

#endif // PLAYER_H