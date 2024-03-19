#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> firstPlayer, secondPlayer;
    for (int i = 0; i < 5; ++i) {
        int card;
        cin >> card;
        firstPlayer.push(card);
    }
    for (int i = 0; i < 5; ++i) {
        int card;
        cin >> card;
        secondPlayer.push(card);
    }

    int moves = 0;
    while (!firstPlayer.empty() && !secondPlayer.empty() && moves < 1000000) {
        int cardFirst = firstPlayer.front();
        firstPlayer.pop();
        int cardSecond = secondPlayer.front();
        secondPlayer.pop();

        if ((cardFirst > cardSecond && !(cardFirst == 9 && cardSecond == 0)) || (cardFirst == 0 && cardSecond == 9)) {
            firstPlayer.push(cardFirst);
            firstPlayer.push(cardSecond);
        } else {
            secondPlayer.push(cardFirst);
            secondPlayer.push(cardSecond);
        }

        ++moves;
    }

    if (moves >= 1000000) {
        cout << "botva" << endl;
    } else if (firstPlayer.empty()) {
        cout << "second " << moves << endl;
    } else {
        cout << "first " << moves << endl;
    }

    return 0;
}