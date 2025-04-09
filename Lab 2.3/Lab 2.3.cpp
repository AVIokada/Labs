#include <iostream>
#include <Windows.h>
using namespace std;

int summa(int n = 1) {
    if (n < 1) {
        return 0;
    }
    int s = 0;
    for (int i = 1; i <= n; i++) { s += i; }
    return s;
}


void f(int a, int b, int& x, int& y) {
    x = a + b;
    y = a * b;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL(), "ru");

    int arr[2][3] = { {4,5,6},  {6,5,4} };
    int s = arr[0][0] + arr[0][1] + arr[0][2] + arr[1][0] + arr[1][1] + arr[1][2];
    cout << s << endl;

    int arr_s[3];
    arr_s[0] = arr[0][0] + arr[1][0];
    arr_s[1] = arr[0][1] + arr[1][1];
    arr_s[2] = arr[0][2] + arr[1][2];
    cout << arr_s[0] << " " << arr_s[1] << " " << arr_s[2] << endl;

    float c = 20.84;
    float& a = c;
    float& b = c;
    a = 3.14; //ssilka
    cout << a << " " << b << " " << c << endl;

    cout << summa(-5) << endl;
    cout << summa() << endl;
    cout << summa(3) << endl;

    int x = 100, y = 101;
    f(5, 7, x, y);
    cout << x << " " << y << endl;

    string my = "MAGIC";
    cout << my << endl;
    
    for (int j = 1; j <= 3; j++) {
        cout << arr[0][0] << endl;
        int gg = 121;
        cout << gg << endl;
    }
    //cout << gg;
}