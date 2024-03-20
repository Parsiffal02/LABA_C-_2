#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    unordered_set<string> set;
    char operation;
    string word;

    while (cin >> operation && operation != '#') {
        cin >> word;
        switch (operation) {
            case '+':
                // Добавление слова в множество
                set.insert(word);
                break;
            case '-':
                // Удаление слова из множества
                set.erase(word);
                break;
            case '?':
                // Проверка наличия слова в множестве
                cout << (set.find(word) != set.end() ? "YES" : "NO") << endl;
                break;
            default:
                // Непредвиденная операция, игнорируем
                break;
        }
    }

    return 0;
}

