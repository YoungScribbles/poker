#include "player.h"

Player::Player(string name, Table* table) {
    mName = name;
    mTable = table;
    printf("Created player: %s\n", mName);
}

Player::~Player() {
    printf("Destroyed player: %s\n", mName);
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