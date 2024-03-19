#include <iostream>
#include <deque>
#include <sstream>

// Функция для чтения колоды из строки
std::deque<int> readDeck(const std::string& line) {
    std::deque<int> deck;
    std::istringstream iss(line);
    int card;
    while (iss >> card) {
        deck.push_back(card);
    }
    return deck;
}

// Функция для сравнения карт
bool isFirstCardWins(int card1, int card2) {
    if (card1 == 0 && card2 == 9) return true;
    if (card1 == 9 && card2 == 0) return false;
    return card1 > card2;
}

int main() {
    std::string line1, line2;
    std::getline(std::cin, line1);
    std::getline(std::cin, line2);

    auto deck1 = readDeck(line1);
    auto deck2 = readDeck(line2);

    int steps = 0;
    while (!deck1.empty() && !deck2.empty() && steps < 106) {
        int card1 = deck1.front();
        deck1.pop_front();
        int card2 = deck2.front();
        deck2.pop_front();

        if (isFirstCardWins(card1, card2)) {
            deck1.push_back(card1);
            deck1.push_back(card2);
        } else {
            deck2.push_back(card1);
            deck2.push_back(card2);
        }

        steps++;
    }

    if (steps >= 106) {
        std::cout << "botva";
    } else if (deck1.empty()) {
        std::cout << "second " << steps;
    } else {
        std::cout << "first " << steps;
    }

    return 0;
}