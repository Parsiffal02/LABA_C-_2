#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<stack<int>> stacks(N);

    // Заполнение стопок
    for (int i = 0; i < N; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int type;
            cin >> type;
            stacks[i].push(type);
        }
    }

    // Проверка исходного условия
    bool alreadySorted = true;
    for (int i = 0; i < N; ++i) {
        stack<int> tempStack = stacks[i];
        while (!tempStack.empty()) {
            if (tempStack.top() != i + 1) {
                alreadySorted = false;
                break;
            }
            tempStack.pop();
        }
        if (!alreadySorted) break;
    }
    if (alreadySorted) return 0;

    // Перемещение контейнеров
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            stack<int> &currentStack = stacks[j];
            vector<int> buffer;
            while (!currentStack.empty() && currentStack.top() != i + 1) {
                buffer.push_back(currentStack.top());
                currentStack.pop();
            }
            if (!currentStack.empty()) {
                cout << j + 1 << " " << i + 1 << endl;
                currentStack.pop(); // Перемещаем контейнер
                for (auto it = buffer.rbegin(); it != buffer.rend(); ++it) {
                    currentStack.push(*it); // Возвращаем остальные контейнеры обратно
                }
            }
        }
    }

    return 0;
}
