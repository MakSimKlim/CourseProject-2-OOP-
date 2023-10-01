// Блэк Джэк
//
//
#include <iostream>
#include <vector>
#include <memory>
#include <ctime>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>  // Для shuffle
#include <random>     // Для random_device и mt19937
using namespace std;

class Card {
public:
    Card(int value) : value(value) {}

    int getValue() const {
        return value;
    }

    void display() const {
        cout << value << " ";
    }

private:
    int value;
};

class Player {
public:
    Player() {}

    virtual ~Player() {}

    void addCard(const Card& card) {
        hand.push_back(card);
    }

    void displayHand() const {
        cout << "Карты в руке: ";
        for (const auto& card : hand) {
            card.display();
        }
        cout << endl;
    }

    int calculateHandSum() const {
        int sum = 0;
        int numAces = 0;

        for (const auto& card : hand) {
            sum += card.getValue();

            if (card.getValue() == 11) {
                numAces++;
            }
        }

        while (numAces > 0 && sum > 21) {
            sum -= 10;
            numAces--;
        }

        return sum;
    }

    virtual bool wantCard() const = 0;

protected:
    vector<Card> hand;
};

class HumanPlayer : public Player {
public:
    bool wantCard() const override {
        displayHand();
        cout << "Хотите взять еще карту? (1 - Да, 2 - Нет): ";
        int choice;
        cin >> choice;

        // Обработка ошибок через ExceptionManager
        try {
            if (choice != 1 && choice != 2) {
                throw invalid_argument("Некорректный выбор!");
            }
        }
        catch (const exception& ex) {
            cerr << "Исключение: " << ex.what() << endl;
            return false; // завершаем ход
        }

        return (choice == 1);
    }
};

class ComputerPlayer : public Player {
public:
    bool wantCard() const override {
        return (calculateHandSum() < 17);
    }
};

class ConsoleOutput {
public:
    static void displayWinner() {
        cout << "Поздравляем! Вы выиграли!" << endl;
    }

    static void displayLooser() {
        cout << "Увы! Вы проиграли." << endl;
    }

    static void displayHands(const vector<unique_ptr<Player>>& players) {
        for (const auto& player : players) {
            player->displayHand();
        }
    }

    static void displayMessage(const string& message) {
        cout << message << endl;
    }

    static void displayException(const exception& ex) {
        cerr << "Исключение: " << ex.what() << endl;
    }
};

class ExceptionManager {
public:
    template<typename Func>
    static void tryCatch(const Func& func) {
        try {
            func();
        }
        catch (const exception& ex) {
            ConsoleOutput::displayException(ex);
            throw; // перебрасываем исключение для обработки в других частях кода
        }
    }
};

class BlackjackGame {
public:
    BlackjackGame() {
        srand(static_cast<unsigned int>(time(0)));
        initializeDeck();
    }

    void playGame() {
        players.push_back(make_unique<HumanPlayer>());
        players.push_back(make_unique<ComputerPlayer>());

        dealInitialCards();

        for (auto& player : players) {
            ExceptionManager::tryCatch([&] {
                while (player->wantCard()) {
                    dealCard(*player);
                    if (player->calculateHandSum() == 21) {
                        ConsoleOutput::displayWinner();
                        return;
                    }
                    else if (player->calculateHandSum() > 21) {
                        ConsoleOutput::displayLooser();
                        return;
                    }
                }
                });
        }

        ExceptionManager::tryCatch([&] {
            while (players[1]->wantCard()) {
                dealCard(*players[1]);
            }
            });

        determineWinner();
    }

private:
    vector<Card> deck;
    vector<unique_ptr<Player>> players;

    void initializeDeck() {
        for (int i = 2; i <= 11; ++i) {
            deck.push_back(Card(i));
        }

        // Перемешиваем колоду
        shuffleDeck();
    }

    void shuffleDeck() {
        mt19937 gen(random_device{}());
        shuffle(deck.begin(), deck.end(), gen);
    }


    void dealCard(Player& player) {
        ExceptionManager::tryCatch([&] {
            if (deck.empty()) {
                throw out_of_range("Колода пуста!");
            }

            Card card = deck.back();
            deck.pop_back();
            player.addCard(card);
            });
    }

    void dealInitialCards() {
        for (int i = 0; i < 2; ++i) {
            for (auto& player : players) {
                ExceptionManager::tryCatch([&] {
                    dealCard(*player);
                    });
            }
        }
    }

    void determineWinner() const {
        int playerSum = players[0]->calculateHandSum();
        int dealerSum = players[1]->calculateHandSum();

        ConsoleOutput::displayHands(players);

        if (playerSum > dealerSum && playerSum <= 21) {
            ConsoleOutput::displayMessage("Вы выиграли!");
        }
        else if (dealerSum > 21) {
            ConsoleOutput::displayMessage("Дилер проиграл! Вы выиграли!");
        }
        else if (playerSum == dealerSum) {
            ConsoleOutput::displayMessage("Ничья!");
        }
        else {
            ConsoleOutput::displayMessage("Вы проиграли.");
        }
    }
};

// Класс, представляющий меню
class Menu {
public:
    // Метод для отображения меню и получения выбора пользователя
    static int displayMenu() {
        std::cout << "\n1. Начать новую игру в Блэкджек\n";
        std::cout << "2. Выйти\n";
        std::cout << "> ";

        int choice;
        std::cin >> choice;
        return choice;
    }
};


int main() {
    setlocale(LC_ALL, "Russian");


    int answer;
    do {
        answer = Menu::displayMenu();
        if (answer == 1) {
            // Создаем объект игры в Блэкджек
            BlackjackGame game;
            game.playGame();
        }
    } while (answer != 2);

    return 0;
}