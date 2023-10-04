// GameResult.h
#pragma once

#include <vector>
#include <memory>
#include "Player.h"
#include "ConsoleOutput.h"

// ����� GameResult, ��������������� ��� ����������� ���������� ����
class GameResult 
{
public:
    // ����������� ����� ��� ����������� ���������� � ����
    /*
    ����������� ����� ������ ��� ����������� ���������� � ����. ��������� ������ ����� ���������� �� ������� 
    ���� Player � ������ ConsoleOutput ��� ����������� �����������.
    */
    static void determineWinner(const std::vector<std::unique_ptr<Player>>& players, ConsoleOutput& consoleOutput);

private:
    // ����������� ����� ��� �����������, �������� �� ���������� ���� ����������
    /*
    ����������� ����� ������ ��� �����������, 
    �������� �� ���������� ���� ����������. 
    ��������� ������ ���� hand � ���������� true, 
    ���� ��� ��������, � false � ��������� ������.
        */
    static bool isBlackjack(const std::vector<Card>& hand);
};