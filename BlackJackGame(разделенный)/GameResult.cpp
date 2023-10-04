// GameResult.cpp
#include "GameResult.h"

void GameResult::determineWinner(const std::vector<std::unique_ptr<Player>>& players, ConsoleOutput& consoleOutput) {
    int playerSum = players[0]->calculateHandSum();
    int dealerSum = players[1]->calculateHandSum();

    consoleOutput.displayHands(players);

    if (isBlackjack(players[0]->getHand())) {
        consoleOutput.displaySplashScreen();
        consoleOutput.displayMessage("  =========================================================================================\n");
        consoleOutput.displayMessage("  =======                  У Вас BlackJack! Поздравляем с Победой!                  =======\n");
        consoleOutput.displayMessage("  =========================================================================================\n");
        system("pause");
        system("cls");
        consoleOutput.displaySplashScreen();
    }
    else if (playerSum > dealerSum && playerSum <= 21) {
        consoleOutput.displayWonScreen();
        consoleOutput.displayMessage("  =========================================================================================\n");
        consoleOutput.displayMessage("  =======   У Вас очков больше, чем у Дилера! Вы выиграли! Поздравляем с Победой!   =======\n");
        consoleOutput.displayMessage("  =========================================================================================\n");
        system("pause");
        system("cls");
        consoleOutput.displaySplashScreen();
    }
    else if (playerSum < dealerSum && playerSum <= 21 && dealerSum > 21) {
        consoleOutput.displayWonScreen();
        consoleOutput.displayMessage("  =========================================================================================\n");
        consoleOutput.displayMessage("  =======             У Дилера перебор! Вы выиграли! Поздравляем с Победой!         =======\n");
        consoleOutput.displayMessage("  =========================================================================================\n");
        system("pause");
        system("cls");
        consoleOutput.displaySplashScreen();
    }
    else if (playerSum == dealerSum) {
        consoleOutput.displayTieScreen();
        consoleOutput.displayMessage("  =========================================================================================\n");
        consoleOutput.displayMessage("  =======   У Вас одинаковое количество очков с Дилером! Ничья! Везение на равных   =======\n");
        consoleOutput.displayMessage("  =========================================================================================\n");
        system("pause");
        system("cls");
        consoleOutput.displaySplashScreen();
    }
    else if (playerSum < dealerSum && dealerSum <= 21) {
        consoleOutput.displayLostScreen();
        consoleOutput.displayMessage("  =========================================================================================\n");
        consoleOutput.displayMessage("  =======      У Дилера очков больше, чем у Вас! Вы проиграли! Не отчаивайтесь!     =======\n");
        consoleOutput.displayMessage("  =========================================================================================\n");
        system("pause");
        system("cls");
        consoleOutput.displaySplashScreen();
    }
    else {
        consoleOutput.displayLostScreen();
        consoleOutput.displayMessage("  =========================================================================================\n");
        consoleOutput.displayMessage("  =======                У Вас перебор! Вы проиграли! Не отчаивайтесь!              =======\n");
        consoleOutput.displayMessage("  =========================================================================================\n");
        system("pause");
        system("cls");
        consoleOutput.displaySplashScreen();
    }
}

bool GameResult::isBlackjack(const std::vector<Card>& hand) {
    return (hand.size() == 2 &&
        ((hand[0].getValue() == 11 && hand[1].getValue() == 10) ||
            (hand[1].getValue() == 11 && hand[0].getValue() == 10)));
}