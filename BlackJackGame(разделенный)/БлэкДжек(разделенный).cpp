﻿// БлэкДжек(разделенный)

#include <iostream>
#include <cstdlib>  // Для использования функции system
#include "ScreenSettings.h"
#include "ConsoleOutput.h"
#include "mainMenu.h"
#include "BlackjackRules.h"
#include "AboutProgram.h"
#include "BlackjackGame.h"

int main() {
    ScreenSettings consoleSet;
    consoleSet.consoleSettings();

    ConsoleOutput splashScreen;
    splashScreen.displaySplashScreen();

    int answer;
    MainMenu menu;

    do {
        answer = menu.displayMenu();

        if (answer == 1) {
            system("cls");
            ConsoleOutput welcomeScreen;
            welcomeScreen.displayWelcomeScreen();
            BlackjackGame game;
            game.playGame();
        }
        else if (answer == 2) {
            system("cls");
            BlackjackRules::displayRules();
            system("pause");
            system("cls");
            ConsoleOutput splashScreen;
            splashScreen.displaySplashScreen();
        }
        else if (answer == 3) {
            system("cls");
            AboutProgram::displayAbout();
            system("pause");
            system("cls");
            ConsoleOutput splashScreen;
            splashScreen.displaySplashScreen();
        }

    } while (answer != 4);

    return 0;
}





