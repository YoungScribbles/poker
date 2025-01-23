#include "player.h"
#include "table.h"

Player::Player(string name, Table* table) {
    mName = name;
    mTable = table;
}

Player::~Player() {
}

void Player::giveCard(Card card) {
    mCards.placeTop(card);
}

void Player::discard() {
    if (mTable != nullptr) {
        mTable->muck(mCards);
    }
    else {
        printf("mTable is NULL");
    }
}

void Player::report() {
    printf("\t --- %s has:\n", mName.c_str());
    mCards.printCards();
}