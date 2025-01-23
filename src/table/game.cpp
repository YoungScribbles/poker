#include "game.h"

Game::Game() {
    mDeck.generateDeck();

    // Sanity
    mPlayers.clear();
    mDealerPos = 0;
}

Game::~Game() {
}

void Game::addPlayer(Player* p) {
    mPlayers.push_back(p);
    // printf("There are %ld players\n", mPlayers.size());
}

void Game::start() {
    // Make sure tabled cards are added back into the deck
    mDeck.placeTop(mTable.recycleCards());
    mDeck.shuffle();
    dealHands();

    for (auto p : mPlayers) {
        p->report();
    }
    printf("\n");

    dealFlop();
    dealTurn();
    dealRiver();

    mTable.report();
}

void Game::dealHands() {
    printf("Game::dealHands()\n");
    // int dealing = mPlayers.size() * 2;
    int dealing = mPlayers.size() * 2;
    int cardsDealt = 0;
    int pos = mDealerPos + 1;

    // TODO: Prevent a player from leaving mid deal
    while (cardsDealt < dealing) {
        if (pos >= mPlayers.size()) {
            pos = 0;
        }

        printf("Dealing to: %s\n", mPlayers[pos]->name().c_str());
        mPlayers[pos]->giveCard(mDeck.drawTop());
        cardsDealt++;
        pos++;
    }
}

void Game::dealFlop() {
    mTable.muck(mDeck.drawTop());
    for (int i = 0; i < 3; ++i) {
        mTable.play(mDeck.drawTop());
    }
}

void Game::dealTurn() {
    mTable.muck(mDeck.drawTop());
    mTable.play(mDeck.drawTop());
}

void Game::dealRiver() {
    mTable.muck(mDeck.drawTop());
    mTable.play(mDeck.drawTop());
}