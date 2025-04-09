#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");

    double radius;
    cout << "Введите радиус окружности: ";
    cin >> radius;

    double circumference = 2 * 3.1415 * radius;

    cout << "Длина окружности: " << fixed << setprecision(3) << circumference << endl;


    ofstream outFile("output.txt", ios::app);
    if (!outFile) {
        cerr << "Ошибка открытия файла!" << endl;
        return 1;
    }

    string userInput;
    while (true) {
        cout << "Введите произвольную строку (или 'read', 'erase', 'exit' для специальных команд): ";
        cin.ignore();
        getline(cin, userInput);

        if (userInput == "read") {
            ifstream inFile("output.txt");
            if (inFile) {
                string line;
                cout << "Содержимое файла:" << endl;
                while (getline(inFile, line)) {
                    cout << line << endl;
                }
                inFile.close();
            }
            else {
                cout << "Ошибка открытия файла для чтения!" << endl;
            }
            continue;
        }

        if (userInput == "erase") {
            outFile.close(); 
            ofstream clearFile("output.txt", ios::trunc);
            clearFile.close();
            cout << "Файл очищен." << endl;
            outFile.open("output.txt", ios::app);
            continue;
        }

        if (userInput == "exit") {
            break;
        }

        outFile << userInput << endl;
    }

    outFile.close();
    cout << "Выход из программы." << endl;

    return 0;
}