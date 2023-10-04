// BlackjackGame.h
#pragma once

#include <vector>
#include <memory>
#include "Player.h"
#include "DeckManager.h"
#include "GameResult.h"
#include "ConsoleOutput.h"

class BlackjackGame {
public:
    BlackjackGame();

    void playGame();

private:
    std::vector<Card> deck;
    std::vector<std::unique_ptr<Player>> players;
    ConsoleOutput consoleOutput;

    void initializeDeck();

    void shuffleDeck();

    void dealCard(Player& player);

    void dealInitialCards();
};