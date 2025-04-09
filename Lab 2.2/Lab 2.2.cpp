#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL(), "ru");
    
    int a, s = 0;
    do {
        cout << "Введите целое положительное число: ";
        cin >> a;
    } while (a < 1);

    for (int i = 1; i <= a; i++) {
        s += i;
        cout << i;
        if (i != a) { cout << " + "; }
    }
    cout << " = " << s << endl;

    int arr[10] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
    cout << "Первое число: " << arr[0] << endl;
    cout << "Второе число: " << arr[1] << endl;
    cout << "Третье число: " << arr[2] << endl;
    cout << "Четвертое число: " << arr[3] << endl;
    cout << "Пятое число: " << arr[4] << endl;
    cout << "Шестое число: " << arr[5] << endl;
    cout << "Седьмое число: " << arr[6] << endl;
    cout << "Восьмое число: " << arr[7] << endl;
    cout << "Девятое число: " << arr[8] << endl;
    cout << "Десятое число: " << arr[9] << endl;

    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            cout << arr[i] << endl;
        }
    }

    s = 0;
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 1) {
            s += arr[i];
        }
    }
    cout << s;
}