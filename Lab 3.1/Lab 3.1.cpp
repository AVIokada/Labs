#include <iostream>
#include <Windows.h>
using namespace std;


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL(), "ru");

    int a = 11;
    int* b = &a;
    cout << "a = " << a << endl;
    cout << "указатель а = " << b << endl;
    
    *b = 15;
    cout << "a = " << a << endl;
    cout << "указатель а = " << b << endl;

    int arr[3] = { 101, 102, 103 };
    int* m = arr;
    cout << "Значения массива: ";
    for (int i = 0; i < 3; i++) 
    {
        cout << *(m+i) << " ";
    }
    cout << endl;

    int x = 5;
    int* const y = &x;
    cout << x << " = " << y << endl;
    //y++;
    *y = x++;
    cout << x << " = " << y << endl;
}