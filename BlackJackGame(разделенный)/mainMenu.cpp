#include "mainMenu.h"
#include <iostream>

int MainMenu::displayMenu() const {
    int choice;

    do {
        std::cout << "\t\t\t* Г Л А В Н О Е  И Г Р О В О Е  М Е Н Ю *\n\n";
        std::cout << "\t\t\t  1. Начать новую игру\n";
        std::cout << "\t\t\t  2. Правила игры\n";
        std::cout << "\t\t\t  3. About\n";
        std::cout << "\t\t\t  4. Выход\n\n";
        std::cout << "\t\t\t  Выберите номер пункта меню > ";

        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
            system("cls");
            std::cout << "Некорректный ввод. Выберите 1, 2, 3 или 4." << std::endl;
        }

    } while (choice != 1 && choice != 2 && choice != 3 && choice != 4);

    return choice;
}