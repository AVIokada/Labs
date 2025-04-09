#include <iostream>
using namespace std;

int main()

{
    setlocale(LC_ALL(), "ru");
    int a = 150;
    float b = 15.933f;
    short c = 250;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    int d = 20, g = 2006;
    string m = " октября ";
    cout << "Моя дата рождения " << d << m << g << " года" << endl;

    const float p = 2.3f;
    const string q = " WINDOWS";
    cout << p << q;
}