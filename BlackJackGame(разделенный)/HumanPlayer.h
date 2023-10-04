// HumanPlayer.h
#pragma once

#include "Player.h"

//  ласс, представл€ющий человеческого игрока в игре в блэкджек
class HumanPlayer : public Player {
public:
    // –еализаци€ виртуальной функции из базового класса
    bool wantCard() const override;
};