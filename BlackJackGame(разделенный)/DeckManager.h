// DeckManager.h
#pragma once

#include "Card.h"
#include <vector>

class DeckManager {
public:
    static std::vector<Card> initializeDeck();

    static void shuffleDeck(std::vector<Card>& deck);
};