// HumanPlayer.cpp
#include "HumanPlayer.h"
#include <iostream>
#include <limits>

using namespace std;

bool HumanPlayer::wantCard() const {
    int choice;

    do {
        displayHand("у Вас");
        cout << "Хотите взять еще карту? (1 - Да, 2 - Нет): ";

        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Некорректный ввод. Пожалуйста, введите число." << endl;
        }
        else if (choice != 1 && choice != 2) {
            cout << "Некорректный ввод. Выберите 1 или 2." << endl;
        }
    } while (choice != 1 && choice != 2);

    return (choice == 1);
}