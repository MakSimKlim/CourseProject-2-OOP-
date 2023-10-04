// GameResult.h
#pragma once

#include <vector>
#include <memory>
#include "Player.h"
#include "ConsoleOutput.h"

class GameResult {
public:
    static void determineWinner(const std::vector<std::unique_ptr<Player>>& players, ConsoleOutput& consoleOutput);

private:
    static bool isBlackjack(const std::vector<Card>& hand);
};