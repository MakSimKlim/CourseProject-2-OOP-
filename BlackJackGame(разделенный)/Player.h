// Player.h
#pragma once

#include "Card.h"
#include <string>
#include <vector>

// Класс, представляющий игрока в игре в блэкджек
class Player 
{
public:
    // Конструктор по умолчанию
    Player();

    // Виртуальный деструктор для возможности наследования
    virtual ~Player();

    // Метод для добавления карты в руку игрока
    void addCard(const Card& card);

    // Метод для отображения карт в руке игрока
    void displayHand(const std::string& playerName) const;

    // Метод для вычисления суммы очков в руке игрока
    int calculateHandSum() const;

    // Метод для получения руки игрока
    const std::vector<Card>& getHand() const;

    // Виртуальный метод для определения желания игрока получить еще карту
    virtual bool wantCard() const = 0;

protected:
    // Вектор для хранения карт в руке игрока
    std::vector<Card> hand;
};