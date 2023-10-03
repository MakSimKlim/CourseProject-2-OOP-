// Блэк Джэк 3
#include <iostream>
#include <vector>
#include <memory>
#include <ctime>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>  
#include <ctime>
#include <iomanip>
#define NOMINMAX
#include <windows.h>


using namespace std;


class Card {
public:
    enum Rank {
        Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace
    };

    enum Suit {
        Hearts = 3, Diamonds = 4, Clubs = 5, Spades = 6
    };

    Card(Rank rank, Suit suit) : rank(rank), suit(suit) {}

    string getSymbol() const {
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

    string getSuitSymbol() const {
        switch (suit) {
        //case Hearts: return "♥"; // ♥
        //case Diamonds: return "♦"; // ♦
        //case Clubs: return "♣"; // ♣
        //case Spades: return "♠"; // ♠
        //default: return "Invalid";
        
        //case Hearts: return "'H'";
        //case Diamonds: return "'D'";
        //case Clubs: return "'C'";
        //case Spades: return "'S'";
        //default: return "'?'";

        //case Hearts: return "\xE2\x99\xA5"; // ♥
        //case Diamonds: return "\xE2\x99\xA6"; // ♦
        //case Clubs: return "\xE2\x99\xA3"; // ♣
        //case Spades: return "\xE2\x99\xA0"; // ♠
        //default: return "?";

        //case Hearts: return "\u2665";
        //case Diamonds: return "\u2666";
        //case Clubs: return "\u2663";
        //case Spades: return "\u2660";
        //default: return "'?'";

        case Hearts: return "'Червы'";
        case Diamonds: return "'Бубны'";
        case Clubs: return "'Крести'";
        case Spades: return "'Пики'";
        default: return "'?'";


        }
    }

    int getValue() const {
        if (rank >= Ten && rank != Ace) {
            // Валет (J), Дама (Q), Король (K) имеют значение 10.
            return 10;
        }
        else if (rank == Ace) {
            // Туз (A) соответствует значению 11.
            return 11;
        }
        return static_cast<int>(rank);
    }

    void display() const {
        cout << getSymbol() << getSuitSymbol() << " ";
    }

private:
    Rank rank;
    Suit suit;
};

class Player {
public:
    Player() {}

    virtual ~Player() {}

    void addCard(const Card& card) {
        hand.push_back(card);
    }

    void displayHand(const string& playerName) const {
        cout << "Карты в руке " << playerName << ": ";
        for (const auto& card : hand) {
            card.display();
        }
        cout << " (Сумма: " << calculateHandSum() << ")" << endl;
    }

    int calculateHandSum() const {
        int sum = 0;
        int numAces = 0;

        for (const auto& card : hand) {
            sum += card.getValue();

            if (card.getValue() == 11) { // Туз
                numAces++;
            }
        }

        while (numAces > 0 && sum > 21) {
            sum -= 10;
            numAces--;
        }

        return sum;
    }

    const std::vector<Card>& getHand() const {
        return hand;
    }

    virtual bool wantCard() const = 0;

protected:
    vector<Card> hand;
};

class DeckManager {
public:
    static vector<Card> initializeDeck() {
        vector<Card> deck;
        for (int suit = Card::Hearts; suit <= Card::Spades; ++suit) {
            for (int rank = Card::Two; rank <= Card::Ace; ++rank) {
                deck.push_back(Card(static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit)));
            }
        }
        return deck;
    }

    static void shuffleDeck(vector<Card>& deck) {
        srand(static_cast<unsigned int>(time(0)));
        random_shuffle(deck.begin(), deck.end());
    }
};

class HumanPlayer : public Player
{
public:
    bool wantCard() const override
    {
        int choice;

        do
        {
            displayHand("у Вас");
            cout << "Хотите взять еще карту? (1 - Да, 2 - Нет): ";

            cin >> choice;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Некорректный ввод. Пожалуйста, введите число." << endl;
            }
            else if (choice != 1 && choice != 2)
            {
                cout << "Некорректный ввод. Выберите 1 или 2." << endl;
            }
        } while (choice != 1 && choice != 2);

        return (choice == 1);
    }
};

class ComputerPlayer : public Player
{
public:
    bool wantCard() const override
    {
        return (calculateHandSum() < 17);
    }
};

class ConsoleOutput
{
public:

    void displayHands(const vector<unique_ptr<Player>>& players) const
    {
        system("cls");
        for (size_t i = 0; i < players.size(); ++i)
        {
            players[i]->displayHand((i == 0) ? "у Вас" : "у Дилера");
        }
    }

    void displayMessage(const string& message) const
    {
        cout << message << endl;
    }

    void displayException(const exception& ex) const
    {
        cerr << "Исключение: " << ex.what() << endl;
    }
};

class GameResult
{
public:
    static void determineWinner(const vector<unique_ptr<Player>>& players, ConsoleOutput& consoleOutput)
    {
        int playerSum = players[0]->calculateHandSum();
        int dealerSum = players[1]->calculateHandSum();

        consoleOutput.displayHands(players);

        if (isBlackjack(players[0]->getHand()))
        {
            consoleOutput.displayMessage("\nУ Вас BlackJack! Вы выиграли! Поздравляем Вас :)\n");
        }
        else if (playerSum > dealerSum && playerSum <= 21)
        {
            consoleOutput.displayMessage("\nУ Вас очков больше, чем у Дилера! Вы выиграли! Поздравляем Вас :)\n");
            system("pause");
            system("cls");
        }
        else if (playerSum < dealerSum && playerSum <= 21 && dealerSum > 21)
        {
            consoleOutput.displayMessage("\nУ Дилера перебор! Вы выиграли! Поздравляем Вас :)\n");
            system("pause");
            system("cls");
        }
        else if (playerSum == dealerSum)
        {
            consoleOutput.displayMessage("\nУ Вас одинаковое количество очков с Дилером! Ничья! Везение на равных\n");
            system("pause");
            system("cls");
        }
        else if (playerSum < dealerSum && dealerSum <= 21)
        {
            consoleOutput.displayMessage("\nУ Дилера очков больше, чем у Вас! Вы проиграли! Не переживайте :(\n");
            system("pause");
            system("cls");
        }
        else
        {
            consoleOutput.displayMessage("\nУ Вас перебор! Вы проиграли! Не переживайте :(\n");
            system("pause");
            system("cls");
        }
    }
private:
    static bool isBlackjack(const std::vector<Card>& hand) {
        return (hand.size() == 2 &&
            ((hand[0].getValue() == 11 && hand[1].getValue() == 10) ||
                (hand[1].getValue() == 11 && hand[0].getValue() == 10)));
    }

};

class BlackjackGame
{
public:
    BlackjackGame()
    {
        initializeDeck();
    }

    void playGame()
    {
        players.push_back(make_unique<HumanPlayer>());
        players.push_back(make_unique<ComputerPlayer>());

        dealInitialCards();

        for (auto& player : players)
        {
            try
            {
                while (player->wantCard())
                {
                    dealCard(*player);
                    if (player->calculateHandSum() == 21)
                    {
                        GameResult::determineWinner(players, consoleOutput);
                        return;
                    }
                    else if (player->calculateHandSum() > 21)
                    {
                        GameResult::determineWinner(players, consoleOutput);
                        return;
                    }
                }
            }
            catch (const exception& ex)
            {
                consoleOutput.displayException(ex);
            }
        }

        try
        {
            while (players[1]->wantCard())
            {
                dealCard(*players[1]);
            }
        }
        catch (const exception& ex)
        {
            consoleOutput.displayException(ex);
        }
        
        GameResult::determineWinner(players, consoleOutput);
    }

private:
    vector<Card> deck;
    vector<unique_ptr<Player>> players;
    ConsoleOutput consoleOutput; 

    void initializeDeck()
    {
        deck = DeckManager::initializeDeck();
        DeckManager::shuffleDeck(deck);
    }

    void shuffleDeck()
    {
        DeckManager::shuffleDeck(deck);
    }

    void dealCard(Player& player)
    {
        if (deck.empty())
        {
            throw out_of_range("Колода пуста!");
        }

        Card card = deck.back();
        deck.pop_back();
        player.addCard(card);
    }

    void dealInitialCards()
    {
        for (int i = 0; i < 2; ++i)
        {
            for (auto& player : players)
            {
                try
                {
                    dealCard(*player);
                }
                catch (const exception& ex)
                {
                    consoleOutput.displayException(ex);
                }
            }
        }
    }
};

class mainMenu
{
public:
    int displayMenu() const
    {
        int choice;

        do
        {
            cout << "1. Начать новую игру в BlackjackGame!\n";
            cout << "2. Показать правила\n";
            cout << "3. Выйти\n";
            cout << "> ";

            cin >> choice;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (choice != 1 && choice != 2 && choice != 3) 
            {
                system("cls");
                std::cout << "Некорректный ввод. Выберите 1, 2 или 3." << std::endl;
            }

        } while (choice != 1 && choice != 2 && choice != 3);

        return choice;
    }
};

class BlackjackRules {
public:
    static void displayRules() {
    cout << R"(Правила игры в Блэкджек:

1. Цель игры - набрать карты так, чтобы сумма их номиналов была как можно ближе к 21, 
   но не превышала этого значения.
2. Номиналы карт:
   - Карты от 2 до 10 имеют номинал, равный их числовому значению.
   - Валет (J), Дама (Q), Король (K) имеют номинал 10.
   - Туз (A) может иметь значение 1 или 11, в зависимости от ситуации.
3. Игрок и дилер получают по две карты. 
4. Игрок может взять дополнительные карты ('взять еще') или отказаться ('достаточно').
5. Дилер берет дополнительные карты, пока сумма его карт не достигнет или превысит 17.
6. Побеждает игрок, чья сумма ближе к 21 и не превышает 21. В случае равенства - ничья.
7. Блэкджек - набор 21 очка с двумя картами (туз и карта номиналом 10).

)";
    }
};


int main()
{
    setlocale(LC_ALL, "Rus");
   
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);

    system("mode con cols=100 lines=20");                            //задание размеров окна консоли
    system("title Курсовой проект - Игра BlackjackGame! V0.1");      //задание описания окна консоли
    system("color 20");                                              //задание Атрибутов цвета консоли ("1-задний фон А-передний фон")

    cout << "'__________________________________________________________'" << endl;
    cout << "'|       ____  _            _     _            _          |'" << endl;
    cout << "'|      | __ )| | __ _  ___| | __(_) __ _  ___| | __      |'" << endl;
    cout << "'|      | |  \| |/ _` |/ __| |/ /| |/ _` |/ __| |/ /      |'" << endl;
    cout << "'|      | |_) | | (_| | (__|   < | | (_| | (__|   <       |'" << endl;
    cout << "'|      |____/|_|\__,_|\___|_|\_\/ |\__,_|\___|_|\_\      |'" << endl;
    cout << "'|                             |__/                       |'" << endl;
    cout << "'----------------------------------------------------------'" << endl;



    int answer;
    mainMenu menu;

    do
    {
        answer = menu.displayMenu();

        if (answer == 1)
        {
            system("cls");
            cout << "\nДобро пожаловать в игру BlackjackGame!\n" << endl;
            BlackjackGame game;
            game.playGame();
        }
    
        else if (answer == 2) 
        {
            system("cls");
             BlackjackRules::displayRules();
        }

} while (answer != 3);

    return 0;
}