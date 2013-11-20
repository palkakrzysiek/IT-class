#include "Cards.h"

std::string Card::toString() {
    std::string temp;
    temp = FACES[face];
    temp += " of ";
    temp += SUITS[suit];
    return temp;
}

DeckOfCards::DeckOfCards() {
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            deck.push_back(Card(i, j));
        }
    }
    currentCard = 52;
}

void DeckOfCards::shuffle() {
    srand(time(0));

    int size = deck.size();
    for (int i = 0; i < size; i++) {
        std::swap(deck[i], deck[rand() % size]);
    }
}

Card DeckOfCards::dealCard() {
    return deck[--currentCard];
}

bool DeckOfCards::moreCards() {
    return currentCard != 0;
}
