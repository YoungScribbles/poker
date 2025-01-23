
#include <vector>

#include "player.h"
#include "../deck/card.h"

using namespace std;

class Hand
{
public:
    static Player determineWinner(vector<Hand> hands);

public:
    enum HandRank { NoRank, HighCard, Pair, TwoPair, Set, Straight, Flush, FullHouse, StraighFlush };

public:
    Hand();
    ~Hand();

    void addCards(Card card);
    void addCards(vector<Card> cards);

    void evaluateHand();

    void purge();
    HandRank rank();

private:
    vector<Card> mCards;
    vector<Card> bestHand;
    HandRank mRank;
};