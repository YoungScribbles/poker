#include "table.h"

Table::Table() {
    mDealerPos = 0;
}

Table::~Table() {
}

void Table::deal(Deck* d) {
    int dealing = mPlayers.size() * 2;
    int cardsDealt = 0;
    int pos = mDealerPos + 1;

    // TODO: Prevent a player from leaving mid deal
    while (cardsDealt < dealing) {
        if (pos >= mPlayers.size()) {
            pos = 0;
        }

        mPlayers[pos].giveCard(d->drawTop());
    }
}

void Table::muck(vector<Card> cards) {
    mMuck.placeTop(cards);
}

void Table::muck(Pile cards) {
    while (!cards.empty()) {
        mMuck.placeTop(cards.drawTop());
    }
}

void Table::addPlayer(Player* p) {

}

void Table::removePlayer(Player* p) {

}

void Table::removePlayer(int pos) {
    if (mPlayers.size() > pos) {
        mPlayers.erase(mPlayers.begin() + pos);
    }
    else {
        printf("Error: Cannot remove player at position %d\n", pos);
    }
}