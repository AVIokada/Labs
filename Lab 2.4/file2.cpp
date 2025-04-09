#include <iostream>
using namespace std;


namespace Space {


    void f(int a)
    {
        static int b = 0;
        cout << a + b << endl;
        b = a;
    }
}