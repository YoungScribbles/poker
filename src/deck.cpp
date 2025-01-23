
#include <iostream>
#include <time.h>

#include "deck.h"
#include "card.h"

Deck::Deck()
{
    srand(time(0));
    generateDeck();
}

Deck::~Deck()
{
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

Card Deck::drawTop() {
    if (mCards.empty()) {
        throw;
    }

    // Remove the top card from the deck and return it
    Card ret = mCards.back();
    mCards.pop_back();
    return ret;
}

Card Deck::drawRandom() {
    if (mCards.empty()) {
        throw;
    }

    // Remove a random card from the deck and return it
    int index = rand() % mCards.size();
    Card ret = mCards[index];
    mCards.erase(mCards.begin() + index);
    return ret;
}

void Deck::shuffle() {
    printf("Deck::shuffle()\n");
    if (mCards.size() != DECK_SIZE) {
        printf("Error: Deck has %d cards!\n", mCards.size());
        exit(1);
    }

    std::vector<Card> cards;
    while (!mCards.empty()) {
        cards.push_back(drawRandom());
    }

    mCards = cards;
}

void Deck::placeTop(Card card) {
    mCards.push_back(card);
}

void Deck::placeTop(vector<Card> cards) {
    for (auto card : cards) {
        mCards.push_back(card);
    }
}

void Deck::printDeck() {
    // Print the remaining cards in the deck
    for (auto it = mCards.begin(); it != mCards.end(); ++it) {
        (*it).debug();
    }
}