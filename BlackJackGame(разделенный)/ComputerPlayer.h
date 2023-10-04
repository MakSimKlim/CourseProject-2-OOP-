// ComputerPlayer.h
#pragma once

#include "Player.h"

class ComputerPlayer : public Player {
public:
    bool wantCard() const override;
};