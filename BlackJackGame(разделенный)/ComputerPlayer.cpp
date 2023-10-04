// ComputerPlayer.cpp
#include "ComputerPlayer.h"

bool ComputerPlayer::wantCard() const {
    return (calculateHandSum() < 17);
}