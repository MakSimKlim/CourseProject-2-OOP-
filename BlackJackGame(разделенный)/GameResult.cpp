// GameResult.cpp
#include "GameResult.h"

// ���������� ������������ ������ ��� ����������� ���������� � ����
void GameResult::determineWinner(const std::vector<std::unique_ptr<Player>>& players, ConsoleOutput& consoleOutput) {
    // ��������� ����� ����� � ������ � ������
    int playerSum = players[0]->calculateHandSum();
    int dealerSum = players[1]->calculateHandSum();

    // ����������� ���� � ����� ���� ������� �� ������
    consoleOutput.displayHands(players);

    // �������� �� �������� � ������
    if (isBlackjack(players[0]->getHand())) 
    {   // ����������� ������ ��������� � ��������� � ������
        consoleOutput.displaySplashScreen();
        consoleOutput.displayMessage("  =========================================================================================\n");
        consoleOutput.displayMessage("  =======                  � ��� BlackJack! ����������� � �������!                  =======\n");
        consoleOutput.displayMessage("  =========================================================================================\n");
        system("pause");
        system("cls");
        consoleOutput.displaySplashScreen();
    }
    // �������� ������� ������ ������
    else if (playerSum > dealerSum && playerSum <= 21) 
    {
        consoleOutput.displayWonScreen();
        consoleOutput.displayMessage("  =========================================================================================\n");
        consoleOutput.displayMessage("  =======   � ��� ����� ������, ��� � ������! �� ��������! ����������� � �������!   =======\n");
        consoleOutput.displayMessage("  =========================================================================================\n");
        system("pause");
        system("cls");
        consoleOutput.displaySplashScreen();
    }
    else if (playerSum < dealerSum && playerSum <= 21 && dealerSum > 21) {
        consoleOutput.displayWonScreen();
        consoleOutput.displayMessage("  =========================================================================================\n");
        consoleOutput.displayMessage("  =======             � ������ �������! �� ��������! ����������� � �������!         =======\n");
        consoleOutput.displayMessage("  =========================================================================================\n");
        system("pause");
        system("cls");
        consoleOutput.displaySplashScreen();
    }
    else if (playerSum == dealerSum) {
        consoleOutput.displayTieScreen();
        consoleOutput.displayMessage("  =========================================================================================\n");
        consoleOutput.displayMessage("  =======   � ��� ���������� ���������� ����� � �������! �����! ������� �� ������   =======\n");
        consoleOutput.displayMessage("  =========================================================================================\n");
        system("pause");
        system("cls");
        consoleOutput.displaySplashScreen();
    }
    else if (playerSum < dealerSum && dealerSum <= 21) {
        consoleOutput.displayLostScreen();
        consoleOutput.displayMessage("  =========================================================================================\n");
        consoleOutput.displayMessage("  =======      � ������ ����� ������, ��� � ���! �� ���������! �� ������������!     =======\n");
        consoleOutput.displayMessage("  =========================================================================================\n");
        system("pause");
        system("cls");
        consoleOutput.displaySplashScreen();
    }
    else {
        consoleOutput.displayLostScreen();
        consoleOutput.displayMessage("  =========================================================================================\n");
        consoleOutput.displayMessage("  =======                � ��� �������! �� ���������! �� ������������!              =======\n");
        consoleOutput.displayMessage("  =========================================================================================\n");
        system("pause");
        system("cls");
        consoleOutput.displaySplashScreen();
    }
}
// ���������� ������������ ������ ��� �������� ���������
bool GameResult::isBlackjack(const std::vector<Card>& hand) 
{
    // ���������� true, ���� � ���� 2 ����� � �� ���������� - ��������
    return (hand.size() == 2 &&
        ((hand[0].getValue() == 11 && hand[1].getValue() == 10) ||
            (hand[1].getValue() == 11 && hand[0].getValue() == 10)));
}