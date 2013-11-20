#ifndef CARDS_H
#define CARDS_H

#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

const char FACES[13][10] = {
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "10",
    "Jack",
    "Queen",
    "King",
    "Ace"
};
const char SUITS[4][10] = {
    "hearts",
    "diamonds",
    "clubs",
    "spades"
};

class Card {
    public:
        Card(int f, int s) : face(f%13), suit(s%4) {}
        std::string toString();
    private:
        int face;
        int suit;
};

class DeckOfCards {
    public:
        DeckOfCards();
        void shuffle();
        Card dealCard();
        bool moreCards();

    private:
        std::vector<Card> deck;
        int currentCard;

};

#endif
