// ComputerPlayer.cpp
#include "ComputerPlayer.h"

// �����, ������� ���������� true, 
// ���� ����� ����� � ���� ������������� ������ ������ 17.
bool ComputerPlayer::wantCard() const 
{
    return (calculateHandSum() < 17);
}