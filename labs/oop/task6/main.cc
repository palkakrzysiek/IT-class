#include "Cards.h"
#include <iostream>

int main(int argc, char const* argv[])
{
    using namespace std;
    DeckOfCards d;
    d.shuffle();
    while (d.moreCards()) {
        cout << d.dealCard().toString() << endl;
    }
    
    return 0;
}
