#include "hand.h"

Hand::Hand() {
    mRank = NoRank;
}

Hand::~Hand() {
}

void Hand::addCards(Card card) {
    mCards.push_back(card);
}

void Hand::addCards(vector<Card> cards) {
    for (auto card : cards) {
        addCards(card);
    }
}

void Hand::purge() {
    mCards.clear();
    mRank = NoRank;
}