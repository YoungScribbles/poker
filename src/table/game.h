#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "table.h"
#include "../deck/deck.h"

using namespace std;

class Game
{
public:
    enum GameState { Preflop, Flop, Turn, River };

public:
    Game();
    ~Game();

    void addPlayer(Player* p);
    void start();
    void dealHands();

    // TODO: Think about changing these
    void dealFlop();
    void dealTurn();
    void dealRiver();

private:
    Deck mDeck;
    Table mTable;
    vector<Player*> mPlayers;

    int mDealerPos;
};

#endif // GAME_H