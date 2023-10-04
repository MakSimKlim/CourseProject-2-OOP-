// BlackjackGame.cpp
#include "BlackjackGame.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

// Реализация конструктора класса BlackjackGame
BlackjackGame::BlackjackGame() 
{
    initializeDeck();
}

// Реализация метода для запуска игры
void BlackjackGame::playGame() 
{
    // Добавление вектора умных указателей на объекты HumanPlayer и ComputerPlayer
    players.push_back(std::make_unique<HumanPlayer>());
    players.push_back(std::make_unique<ComputerPlayer>());

    // Раздача начальных карт игрокам
    dealInitialCards();

    // Цикл обработки хода каждого игрока
    /*
    try и catch - это блоки в языке программирования C++, 
    используемые для обработки исключений, которые могут возникнуть во время 
    выполнения программы. 
    В этом цикле try используется для обработки исключений, 
    которые могут возникнуть во время выполнения кода внутри блока try. 
    Если в блоке try возникает исключение (например, из-за попытки доступа к 
    несуществующему элементу вектора), управление передается блоку catch, 
    где происходит вывод сообщения об ошибке в консоль.
    */
    for (auto& player : players) 
    /*
    В контексте C++, ключевое слово auto используется для автоматического 
    вывода типа данных переменной на основе её инициализатора. 
    Вместо явного указания типа данных переменной, компилятор самостоятельно 
    определяет этот тип на основе значения, которым переменная инициализируется.
    */
    {
        try 
        {
            // Цикл, пока игрок хочет взять карту
            while (player->wantCard()) 
            {
                dealCard(*player);
                // Проверка на блэкджек или перебор у игрока
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
        catch (const std::exception& ex) 
        {
            // Вывод исключения в консоль
            consoleOutput.displayException(ex);
        }
    }

    // Цикл обработки хода дилера
    try 
    {
        while (players[1]->wantCard()) 
        {
            dealCard(*players[1]);
        }
    }
    catch (const std::exception& ex) 
    {
        // Вывод исключения в консоль
        consoleOutput.displayException(ex);
    }

    // Определение победителя и вывод результатов
    GameResult::determineWinner(players, consoleOutput);

    // Пауза и очистка консоли перед возвращением к начальному экрану
    system("pause");
    system("cls");
    ConsoleOutput splashScreen;
    splashScreen.displaySplashScreen();
}

// Реализация метода для инициализации колоды
void BlackjackGame::initializeDeck() 
{
    deck = DeckManager::initializeDeck();
    shuffleDeck();
}

// Реализация метода для перемешивания колоды
void BlackjackGame::shuffleDeck() 
{
    DeckManager::shuffleDeck(deck);
}

// Реализация метода для раздачи карты игроку
void BlackjackGame::dealCard(Player& player) 
{
    // Проверка наличия карт в колоде
    if (deck.empty()) 
    {
        throw std::out_of_range("Колода пуста!");
    }

    // Извлечение карты из вершины колоды и добавление её игроку
    Card card = deck.back();
    deck.pop_back();
    player.addCard(card);
}

// Реализация метода для раздачи начальных карт
void BlackjackGame::dealInitialCards() 
{
    // Два круга раздачи по две карты каждому игроку
    for (int i = 0; i < 2; ++i) 
    {
        for (auto& player : players) 
        {
            try 
            {
                dealCard(*player);
            }
            catch (const std::exception& ex) 
            {
                // Вывод исключения в консоль
                consoleOutput.displayException(ex);
            }
        }
    }
}