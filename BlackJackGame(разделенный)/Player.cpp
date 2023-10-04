// Player.cpp
#include "Player.h"
#include <iostream>

using namespace std;

// Конструктор по умолчанию
Player::Player() {}

// Деструктор
Player::~Player() {}

// Метод для добавления карты в руку игрока
void Player::addCard(const Card& card) 
{
    hand.push_back(card);
}

// Метод для отображения карт в руке игрока
void Player::displayHand(const string& playerName) const 
{
    cout << "Карты в руке " << playerName << ": ";
    for (const auto& card : hand) 
    {
        card.display();
    }
    cout << " (Сумма: " << calculateHandSum() << ")" << endl;
}

// Метод для вычисления суммы очков в руке игрока
int Player::calculateHandSum() const 
{
    int sum = 0;
    int numAces = 0;

    for (const auto& card : hand) 
    {
        sum += card.getValue();

        if (card.getValue() == 11) // Туз
        { 
            numAces++;
        }
    }

    // Уменьшение значения тузов, если их сумма превышает 21
    while (numAces > 0 && sum > 21) 
    {
        sum -= 10;
        numAces--;
    }

    return sum;
}

// Метод для получения вектора карт в руке игрока
const vector<Card>& Player::getHand() const 
{
    return hand;
}