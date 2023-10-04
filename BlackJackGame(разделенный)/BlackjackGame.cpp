// BlackjackGame.cpp
#include "BlackjackGame.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

BlackjackGame::BlackjackGame() {
    initializeDeck();
}

void BlackjackGame::playGame() {
    players.push_back(std::make_unique<HumanPlayer>());
    players.push_back(std::make_unique<ComputerPlayer>());

    dealInitialCards();

    for (auto& player : players) {
        try {
            while (player->wantCard()) {
                dealCard(*player);
                if (player->calculateHandSum() == 21) {
                    GameResult::determineWinner(players, consoleOutput);
                    return;
                }
                else if (player->calculateHandSum() > 21) {
                    GameResult::determineWinner(players, consoleOutput);
                    return;
                }
            }
        }
        catch (const std::exception& ex) {
            consoleOutput.displayException(ex);
        }
    }

    try {
        while (players[1]->wantCard()) {
            dealCard(*players[1]);
        }
    }
    catch (const std::exception& ex) {
        consoleOutput.displayException(ex);
    }

    GameResult::determineWinner(players, consoleOutput);
    system("pause");
    system("cls");
    ConsoleOutput splashScreen;
    splashScreen.displaySplashScreen();
}

void BlackjackGame::initializeDeck() {
    deck = DeckManager::initializeDeck();
    shuffleDeck();
}

void BlackjackGame::shuffleDeck() {
    DeckManager::shuffleDeck(deck);
}

void BlackjackGame::dealCard(Player& player) {
    if (deck.empty()) {
        throw std::out_of_range("Колода пуста!");
    }

    Card card = deck.back();
    deck.pop_back();
    player.addCard(card);
}

void BlackjackGame::dealInitialCards() {
    for (int i = 0; i < 2; ++i) {
        for (auto& player : players) {
            try {
                dealCard(*player);
            }
            catch (const std::exception& ex) {
                consoleOutput.displayException(ex);
            }
        }
    }
}