#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> class9, class10, class11;
    int grade;
    std::string surname;

    // Чтение данных
    while (std::cin >> grade >> surname) {
        switch (grade) {
            case 9:
                class9.push_back(surname);
                break;
            case 10:
                class10.push_back(surname);
                break;
            case 11:
                class11.push_back(surname);
                break;
            default:
                // Некорректный номер класса, можно добавить обработку ошибки
                break;
        }
    }

    // Вывод результатов
    for (const auto& name : class9) {
        std::cout << "9 " << name << std::endl;
    }
    for (const auto& name : class10) {
        std::cout << "10 " << name << std::endl;
    }
    for (const auto& name : class11) {
        std::cout << "11 " << name << std::endl;
    }

    return 0;
}