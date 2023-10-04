// Card.h
#pragma once

#include <string>

class Card {
public:
    enum Rank {
        Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace
    };

    enum Suit {
        Hearts = 3, Diamonds = 4, Clubs = 5, Spades = 6
    };

    Card(Rank rank, Suit suit);

    std::string getSymbol() const;

    std::string getSuitSymbol() const;

    int getValue() const;

    void display() const;

private:
    Rank rank;
    Suit suit;
};