
#include <iostream>
#include <time.h>

#include "deck.h"
#include "card.h"

Deck::Deck(){
    srand(time(0));
    generateDeck();
}

Deck::~Deck(){
}

void Deck::generateDeck() {
    if (!mCards.empty()) {
        mCards.clear();
    }

    for (auto s : SUITS) {
        for (auto v : VALS) {
            Card c = Card(s, v);
            mCards.push_back(c);
        }
    }
}

void Deck::shuffle() {
    printf("Deck::shuffle()\n");

    // TODO: Take this check somewhere else so we can apply it to other games
    if (mCards.size() != DECK_SIZE) {
        printf("Error: Deck has %ld cards!\n", mCards.size());
        exit(1);
    }

    std::vector<Card> cards;
    while (!mCards.empty()) {
        cards.push_back(drawRandom());
    }

    mCards = cards;
}