// BlackjackGame.h
#pragma once

#include <vector>
#include <memory>
#include "Player.h"
#include "DeckManager.h"
#include "GameResult.h"
#include "ConsoleOutput.h"

// Класс BlackjackGame, представляющий игру в Блэкджек
class BlackjackGame 
{
public:
    // Конструктор по умолчанию
    BlackjackGame();
    // Метод для запуска игры
    void playGame();

private:
    // Вектор карт в колоде
    std::vector<Card> deck;
    // Вектор умных указателей на игроков
    std::vector<std::unique_ptr<Player>> players;
    // Объект для вывода информации в консоль
    ConsoleOutput consoleOutput;

    // Метод для инициализации колоды
    void initializeDeck();

    // Метод для перемешивания колоды
    void shuffleDeck();

    // Метод для раздачи карты игроку
    void dealCard(Player& player);

    // Метод для раздачи начальных карт
    void dealInitialCards();
};