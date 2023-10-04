// Card.h
#pragma once

#include <string>

// Класс, представляющий игральную карту
class Card {
public:
    // Перечисление для рангов карт
    enum Rank {
        Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace
    };

    // Перечисление для мастей карт
    enum Suit {
        Hearts = 3, Diamonds = 4, Clubs = 5, Spades = 6
    };

    // Конструктор класса Card, инициализирующий ранг и масть карты
    Card(Rank rank, Suit suit);

    // Метод, возвращающий символьное представление ранга карты
    std::string getSymbol() const;

    // Метод, возвращающий символьное представление масти карты
    std::string getSuitSymbol() const;

    // Метод, возвращающий значение карты в очках при игре в блэкджек
    int getValue() const;

    // Метод, выводящий карту в консоль (символьное представление ранга и масти)
    void display() const;

private:
    // Переменные для хранения ранга и масти карты
    Rank rank;
    Suit suit;
};