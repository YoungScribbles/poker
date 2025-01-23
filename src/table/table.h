#ifndef TABLE_H
#define TABLE_H

#include <vector>

#include "player.h"
#include "../deck/deck.h"

using namespace std;

class Table
{
public:
    Table();
    ~Table();

    void deal(Deck* d);

    void muck(vector<Card> cards);
    void muck(Pile cards);

    void addPlayer(Player* p);
    void removePlayer(Player* p);
    void removePlayer(int pos);

private:
    vector<Player> mPlayers;
    int mDealerPos;

    Pile mLive;
    Pile mMuck;
}

#endif // TABLE_H