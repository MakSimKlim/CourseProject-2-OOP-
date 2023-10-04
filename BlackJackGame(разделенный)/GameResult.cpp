// GameResult.cpp
#include "GameResult.h"

// Реализация статического метода для определения победителя в игре
void GameResult::determineWinner(const std::vector<std::unique_ptr<Player>>& players, ConsoleOutput& consoleOutput) {
    // Получение суммы очков у игрока и дилера
    int playerSum = players[0]->calculateHandSum();
    int dealerSum = players[1]->calculateHandSum();

    // Отображение карт в руках всех игроков на экране
    consoleOutput.displayHands(players);

    // Проверка на блэкджек у игрока
    if (isBlackjack(players[0]->getHand())) 
    {   // Отображение экрана блэкджека и сообщения о победе
        consoleOutput.displaySplashScreen();
        consoleOutput.displayMessage("  =========================================================================================\n");
        consoleOutput.displayMessage("  =======                  У Вас BlackJack! Поздравляем с Победой!                  =======\n");
        consoleOutput.displayMessage("  =========================================================================================\n");
        system("pause");
        system("cls");
        consoleOutput.displaySplashScreen();
    }
    // Проверка условий победы игрока
    else if (playerSum > dealerSum && playerSum <= 21) 
    {
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
// Реализация статического метода для проверки блэкджека
bool GameResult::isBlackjack(const std::vector<Card>& hand) 
{
    // Возвращает true, если в руке 2 карты и их комбинация - блэкджек
    return (hand.size() == 2 &&
        ((hand[0].getValue() == 11 && hand[1].getValue() == 10) ||
            (hand[1].getValue() == 11 && hand[0].getValue() == 10)));
}