// DeckManager.cpp
#include "DeckManager.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

// Метод для инициализации и возвращения новой колоды карт
std::vector<Card> DeckManager::initializeDeck() 
{
    // Создание вектора карт и заполнение его всей колодой
    std::vector<Card> deck;
    for (int suit = Card::Hearts; suit <= Card::Spades; ++suit) {
        for (int rank = Card::Two; rank <= Card::Ace; ++rank) {
            deck.push_back(Card(static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit)));
        }
    }
    return deck;
}

// Метод для перемешивания колоды карт
void DeckManager::shuffleDeck(std::vector<Card>& deck) 
{
    // Инициализация генератора случайных чисел и перемешивание колоды
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(deck.begin(), deck.end());
}