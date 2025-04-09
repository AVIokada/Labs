#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");

    string name;
    cout << "Введите ваше имя: ";
    getline(cin, name);

    regex namePattern(R"(^[A-ZА-Я][a-zA-Zа-яА-Я]{1,31}$)");
    if (regex_match(name, namePattern)) {
        cout << "Имя введено корректно." << endl;
    }
    else {
        cout << "Имя должно быть от 2 до 32 символов и начинаться с заглавной буквы." << endl;
        return 1;
    }

    string text = "Вы можете связаться со мной по email: example1@mail.com, example2@mail.com и example3@mail.co.uk.";

    regex emailPattern(R"((\w+@\w+\.\w+(\.\w+)?))");
    vector<string> emails;
    auto words_begin = sregex_iterator(text.begin(), text.end(), emailPattern);
    auto words_end = sregex_iterator();

    for (sregex_iterator i = words_begin; i != words_end; ++i) {
        emails.push_back(i->str());
    }

    cout << "Найденные email адреса:" << endl;
    for (const string& email : emails) {
        cout << email << endl;
    }

    return 0;
}