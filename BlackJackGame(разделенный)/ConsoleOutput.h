// ConsoleOutput.h
#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "Player.h"

// Класс ConsoleOutput, предназначенный для вывода информации в консоль
class ConsoleOutput 
{
public:
    // Метод для отображения рук всех игроков
    void displayHands(const std::vector<std::unique_ptr<Player>>& players) const;
    // Метод для отображения текстового сообщения
    void displayMessage(const std::string& message) const;
    // Метод для отображения исключения (ошибки)
    void displayException(const std::exception& ex) const;
    // Метод для отображения заставки
    void displaySplashScreen();
    // Метод для отображения экрана приветствия
    void displayWelcomeScreen();
    // Метод для отображения экрана победы
    void displayWonScreen();
    // Метод для отображения экрана поражения
    void displayLostScreen();
    // Метод для отображения экрана ничьей
    void displayTieScreen();
};