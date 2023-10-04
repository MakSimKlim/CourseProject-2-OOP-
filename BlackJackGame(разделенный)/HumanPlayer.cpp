// HumanPlayer.cpp
#include "HumanPlayer.h"
#include <iostream>
#include <limits>

using namespace std;

// Реализация виртуальной функции wantCard из базового класса
bool HumanPlayer::wantCard() const 
{
    int choice;

    do {
        // Отображение карт в руке игрока и запрос на взятие еще карты
        displayHand("у Вас");
        cout << "Хотите взять еще карту? (1 - Да, 2 - Нет): ";

        // Получение выбора от пользователя
        cin >> choice;

        // Обработка некорректного ввода (если введено не число)
        if (cin.fail()) 
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Некорректный ввод. Пожалуйста, введите число." << endl;
        }
        // Обработка ввода, не являющегося 1 или 2
        else if (choice != 1 && choice != 2) 
        {
            cout << "Некорректный ввод. Выберите 1 или 2." << endl;
        }

    } while (choice != 1 && choice != 2);

    // Возврат true, если игрок хочет взять карту, и false в противном случае
    return (choice == 1);
}