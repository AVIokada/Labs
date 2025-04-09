#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");

    string userInput;
    cout << "Введите строку: ";
    getline(cin, userInput);

    if (userInput.length() >= 4) {
        string substring = userInput.substr(1, 3);
        cout << "Подстрока от 2-го до 4-го символа: " << substring << endl;
    }
    else {
        cout << "Строка слишком короткая для извлечения подстроки." << endl;
    }

    size_t index = userInput.find('a');
    if (index != string::npos) {
        cout << "Индекс первого вхождения 'a': " << index << endl;
    }
    else {
        cout << "Символа 'a' не найдено." << endl;
    }

    return 0;
}