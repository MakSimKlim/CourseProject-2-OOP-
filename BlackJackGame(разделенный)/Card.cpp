// Card.cpp
#include "Card.h"
#include <iostream>

using namespace std;

// ����������� ������ Card, ���������������� ���� � ����� �����
Card::Card(Rank rank, Suit suit) : rank(rank), suit(suit) {}

// �����, ������������ ���������� ������������� ����� �����
string Card::getSymbol() const {
    switch (rank) {
    case Two: return "2";
    case Three: return "3";
    case Four: return "4";
    case Five: return "5";
    case Six: return "6";
    case Seven: return "7";
    case Eight: return "8";
    case Nine: return "9";
    case Ten: return "10";
    case Jack: return "J";
    case Queen: return "Q";
    case King: return "K";
    case Ace: return "A";
    default: return "Invalid";
    }
}

// �����, ������������ ���������� ������������� ����� �����
string Card::getSuitSymbol() const {
    switch (suit) {
    case Hearts: return "'�����'";
    case Diamonds: return "'�����'";
    case Clubs: return "'������'";
    case Spades: return "'����'";
    default: return "'?'";
    }
}

// �����, ������������ �������� ����� � ����� ��� ���� � ��������
int Card::getValue() const {
    if (rank >= Ten && rank != Ace) {
        return 10;
    }
    else if (rank == Ace) {
        return 11;
    }
    return static_cast<int>(rank);
}

// �����, ��������� ����� � ������� (���������� ������������� ����� � �����)
void Card::display() const {
    cout << getSymbol() << getSuitSymbol() << " ";
}