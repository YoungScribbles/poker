
#include <iostream>
#include "deck.h"

using namespace std;

int main() {
    Deck d;

    for (int i = 0; i < 5; ++i) {
        d.shuffle();
        d.printDeck();
    }

    return 0;
}