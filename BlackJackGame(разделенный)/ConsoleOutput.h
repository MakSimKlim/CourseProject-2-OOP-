// ConsoleOutput.h
#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "Player.h"

class ConsoleOutput {
public:
    void displayHands(const std::vector<std::unique_ptr<Player>>& players) const;
    void displayMessage(const std::string& message) const;
    void displayException(const std::exception& ex) const;
    void displaySplashScreen();
    void displayWelcomeScreen();
    void displayWonScreen();
    void displayLostScreen();
    void displayTieScreen();
};