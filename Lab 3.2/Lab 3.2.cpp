#include <iostream>
#include <Windows.h>
using namespace std;


int s(int* begin, int* end) {
    int c = 0;
    for (int* i = begin; i < end; i++) {
        c += *i;
    }
    return c;
}


int add(int a, int b) {
    return a + b;
}


int minu(int a, int b) {
    return a - b;
}


int (*znak(char z))(int, int) {
    if (z == '+') { return add; }
    else { return minu; }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");

    int k[5] = {5, 4, 3, 2, 1};
    cout << s(begin(k), end(k)) << endl;
    
    int (*operation) (int, int);
    operation = znak('+');

    //auto operation = znak('+');

    int x = operation(4, 5);
    cout << x << " ";

    operation = znak('-');
    int y = operation(11, 4);
    cout << y << endl;

    float n = 12.34;
    float* m = new float(n);
    cout << *m << " = " << m << endl;
    delete m;
}