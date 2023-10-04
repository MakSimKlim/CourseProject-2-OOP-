// HumanPlayer.h
#pragma once

#include "Player.h"

class HumanPlayer : public Player {
public:
    bool wantCard() const override;
};