
#include <iostream>
#include "table/game.h"

using namespace std;

int main() {
    Player p1("Bruce", nullptr);
    Player p2("Ayylmao", nullptr);
    Player p3("Cool Dad", nullptr);
    Player p4("Snoop Dogg", nullptr);
    Player p5("Cliffy", nullptr);
    Player p6("Young Scribs", nullptr);

    Game game;

    game.addPlayer(&p1);
    game.addPlayer(&p2);
    game.addPlayer(&p3);
    game.addPlayer(&p4);
    game.addPlayer(&p5);
    game.addPlayer(&p6);
    game.start();

    return 0;
}