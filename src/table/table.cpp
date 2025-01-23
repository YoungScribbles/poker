#include "table.h"
#include "player.h"

Table::Table() {
}

Table::~Table() {
}

void Table::play(Card card) {
    mLive.placeTop(card);
}

void Table::play(vector<Card> cards) {
    mLive.placeTop(cards);
}

void Table::play(Pile cards) {
    while (!cards.empty()) {
        mLive.placeTop(cards.drawTop());
    }
}

void Table::muck(Card card) {
    mMuck.placeTop(card);
}

void Table::muck(vector<Card> cards) {
    mMuck.placeTop(cards);
}

void Table::muck(Pile cards) {
    while (!cards.empty()) {
        mMuck.placeTop(cards.drawTop());
    }
}

Pile Table::recycleCards() {
    Pile cards;

    while (!mMuck.empty()) {
        cards.placeTop(mMuck.drawTop());
    }
    while (!mLive.empty()) {
        cards.placeTop(mLive.drawTop());
    }
    return cards;
}

void Table::report() {
    printf("Table::report()\n");
    printf("\t\tLive Cards:\n");
    mLive.printCards();

    printf("\t\tDead Cards:\n");
    mMuck.printCards();
}