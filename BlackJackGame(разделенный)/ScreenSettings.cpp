#include "ScreenSettings.h"
#include <iostream>
#include <cstdlib>

void ScreenSettings::consoleSettings() {
    setlocale(LC_ALL, "Rus");

    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);

    system("mode con cols=93 lines=25");                            //������� �������� ���� �������
    system("title �������� ������ - ���� BlackjackGame! V0.1");      //������� �������� ���� �������
    system("color 20");                                              //������� ��������� ����� ������� ("1-������ ��� �-�������� ���")
}