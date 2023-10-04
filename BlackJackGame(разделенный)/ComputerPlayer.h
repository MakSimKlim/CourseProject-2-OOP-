// ComputerPlayer.h
#pragma once

#include "Player.h"

//  ласс, представл€ющий компьютерного игрока в игре в блэкджек
class ComputerPlayer : public Player 
{
public:
    // –еализаци€ виртуальной функции из базового класса
    bool wantCard() const override;
};