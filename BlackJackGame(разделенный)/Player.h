// Player.h
#pragma once

#include "Card.h"
#include <string>
#include <vector>

class Player {
public:
    Player();

    virtual ~Player();

    void addCard(const Card& card);

    void displayHand(const std::string& playerName) const;

    int calculateHandSum() const;

    const std::vector<Card>& getHand() const;

    virtual bool wantCard() const = 0;

protected:
    std::vector<Card> hand;
};