#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL(), "ru");
    float a;
    float b;
    cout << "Введите число a: ";
    cin >> a;
    cout << "Введите число b: ";
    cin >> b;

    cout << "Среднее арифметическое двух чисел: " << (a+b)/2 << endl;

    cout << "Введите знак операции над числами a и b: ";

    char z;
    cin >> z;

    //if (z == "+") {cout << "Сумма чисел a и b = " << a + b;}
    //else if (z == "-") {cout << "Разность чисел a и b = " << a - b;}
    //else if (z == "*") {cout << "Произведение чисел a и b = " << a * b;}
    //else if (z == "/") {
    //    if (b == 0) {
    //      cout << "На 0 делить нельзя! БАН!";
    //    } else {
    //        { cout << "Деление числа a на b = " << a / b;}
    //    }
    //}
    //else {
    //    cout << endl <<"Ошибка - ввод данных некоректен. Начните сначала.";
    //}

    //9576
      //  9580
        //9572
            //9584

    switch (z) {
    case '+':
        cout << "Сумма чисел a и b = " << a + b;
        break;

    case '-':
        cout << "Разность чисел a и b = " << a - b;
        break;

    case '*':
        cout << "Произведение чисел a и b = " << a * b;
        break;

    case '/':
        if (b == 0) {
            cout << "На 0 делить нельзя! БАН!";
        } else {
            cout << "Деление числа a на b = " << a / b;
            }
        break;

    default:
        cout << endl << "Ошибка - ввод данных некоректен. Начните сначала.";
    }
}
