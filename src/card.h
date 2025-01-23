#ifndef CARD_H
#define CARD_H

#include <string>

class Card
{
public:
    Card(char s, int v);
    ~Card();

    void debug();

private:
    std::string suit();
    std::string val();

private:
    char mSuit;
    int mValue;
};




#endif // CARD_H