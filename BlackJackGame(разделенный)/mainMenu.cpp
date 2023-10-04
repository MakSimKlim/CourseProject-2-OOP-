#include "mainMenu.h"
#include <iostream>

int MainMenu::displayMenu() const {
    int choice;

    do {
        std::cout << "\t\t\t* � � � � � � �  � � � � � � �  � � � � *\n\n";
        std::cout << "\t\t\t  1. ������ ����� ����\n";
        std::cout << "\t\t\t  2. ������� ����\n";
        std::cout << "\t\t\t  3. About\n";
        std::cout << "\t\t\t  4. �����\n\n";
        std::cout << "\t\t\t  �������� ����� ������ ���� > ";

        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
            system("cls");
            std::cout << "������������ ����. �������� 1, 2, 3 ��� 4." << std::endl;
        }

    } while (choice != 1 && choice != 2 && choice != 3 && choice != 4);

    return choice;
}