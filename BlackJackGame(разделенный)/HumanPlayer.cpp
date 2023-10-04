// HumanPlayer.cpp
#include "HumanPlayer.h"
#include <iostream>
#include <limits>

using namespace std;

// ���������� ����������� ������� wantCard �� �������� ������
bool HumanPlayer::wantCard() const 
{
    int choice;

    do {
        // ����������� ���� � ���� ������ � ������ �� ������ ��� �����
        displayHand("� ���");
        cout << "������ ����� ��� �����? (1 - ��, 2 - ���): ";

        // ��������� ������ �� ������������
        cin >> choice;

        // ��������� ������������� ����� (���� ������� �� �����)
        if (cin.fail()) 
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������������ ����. ����������, ������� �����." << endl;
        }
        // ��������� �����, �� ����������� 1 ��� 2
        else if (choice != 1 && choice != 2) 
        {
            cout << "������������ ����. �������� 1 ��� 2." << endl;
        }

    } while (choice != 1 && choice != 2);

    // ������� true, ���� ����� ����� ����� �����, � false � ��������� ������
    return (choice == 1);
}