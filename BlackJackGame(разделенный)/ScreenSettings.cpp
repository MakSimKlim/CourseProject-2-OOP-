#include "ScreenSettings.h"
#include <iostream>
#include <cstdlib>

void ScreenSettings::consoleSettings() {
    setlocale(LC_ALL, "Rus");

    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);

    system("mode con cols=93 lines=25");                            //задание размеров окна консоли
    system("title Курсовой проект - Игра BlackjackGame! V0.1");      //задание описания окна консоли
    system("color 20");                                              //задание Атрибутов цвета консоли ("1-задний фон А-передний фон")
}