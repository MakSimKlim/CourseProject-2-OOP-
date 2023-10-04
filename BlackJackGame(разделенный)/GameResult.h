// GameResult.h
#pragma once

#include <vector>
#include <memory>
#include "Player.h"
#include "ConsoleOutput.h"

// Класс GameResult, предназначенный для определения результата игры
class GameResult 
{
public:
    // Статический метод для определения победителя в игре
    /*
    Статический метод класса для определения победителя в игре. Принимает вектор умных указателей на объекты 
    типа Player и объект ConsoleOutput для отображения результатов.
    */
    static void determineWinner(const std::vector<std::unique_ptr<Player>>& players, ConsoleOutput& consoleOutput);

private:
    // Статический метод для определения, является ли комбинация карт блэкджеком
    /*
    Статический метод класса для определения, 
    является ли комбинация карт блэкджеком. 
    Принимает вектор карт hand и возвращает true, 
    если это блэкджек, и false в противном случае.
        */
    static bool isBlackjack(const std::vector<Card>& hand);
};