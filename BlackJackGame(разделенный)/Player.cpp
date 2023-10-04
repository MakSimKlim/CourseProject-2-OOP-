// Player.cpp
#include "Player.h"
#include <iostream>

using namespace std;

Player::Player() {}

Player::~Player() {}

void Player::addCard(const Card& card) {
    hand.push_back(card);
}

void Player::displayHand(const string& playerName) const {
    cout << "Карты в руке " << playerName << ": ";
    for (const auto& card : hand) {
        card.display();
    }
    cout << " (Сумма: " << calculateHandSum() << ")" << endl;
}

int Player::calculateHandSum() const {
    int sum = 0;
    int numAces = 0;

    for (const auto& card : hand) {
        sum += card.getValue();

        if (card.getValue() == 11) { // Туз
            numAces++;
        }
    }

    while (numAces > 0 && sum > 21) {
        sum -= 10;
        numAces--;
    }

    return sum;
}

const vector<Card>& Player::getHand() const {
    return hand;
}