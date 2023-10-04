// ComputerPlayer.cpp
#include "ComputerPlayer.h"

// метод, который возвращает true, 
// если сумма очков в руке компьютерного игрока меньше 17.
bool ComputerPlayer::wantCard() const 
{
    return (calculateHandSum() < 17);
}