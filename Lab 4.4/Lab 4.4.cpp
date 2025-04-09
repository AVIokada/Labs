#include <iostream>
#include <Windows.h>
using namespace std;

#include "Weapon.h"

class Characteristic {
private:
    float power;

public:
    Characteristic() {
        power = 1;
    }

    Characteristic(float n) {
        power = n;
    }

    float get_power() {
        return power;
    }

    float GetDamage(const Weapon& w) {
        return power + w.get_damage();
    }

    void set_power(float n) {
        if (n > 1) {
            power = n;
        }
        else {
            power = 1;
        }
    }

    friend class Weapon;
};


class MyMath {
private:
    static int callCount;

public:
    static float Add(float a, float b) {
        callCount++;
        return a + b;
    }

    static float Sub(float a, float b) {
        callCount++;
        return a - b;
    }

    static float Mult(float a, float b) {
        callCount++;
        return a * b;
    }

    static float Div(float a, float b) {
        callCount++;
        if (b == 0) {
            cout << "Ошибка: деление на ноль!" << endl;
            return 0;
        }
        return a / b;
    }

    static int GetCallCount() {
        return callCount;
    }
};

int MyMath::callCount = 0;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");

    Weapon id_0001;
    cout << id_0001.get_name() << ": " << id_0001.get_damage() << "/" << id_0001.get_weight() << endl;
    id_0001.set_damage(-2);
    id_0001.set_damage(30);
    cout << id_0001.get_name() << ": " << id_0001.get_damage() << "/" << id_0001.get_weight() << endl;

    Characteristic wizard(50);
    cout << "Сила мага равна: " << wizard.GetDamage(id_0001) << endl;

    cout << "10 + 5 = " << MyMath::Add(10, 5) << endl;
    cout << "20 - 7 = " << MyMath::Sub(20, 7) << endl;
    cout << "6 * 8 = " << MyMath::Mult(6, 8) << endl;
    cout << "15 / 4 = " << MyMath::Div(15, 4) << endl;
    cout << "10 / 0 = " << MyMath::Div(10, 0) << endl;

    cout << "Всего вызовов методов MyMath: " << MyMath::GetCallCount() << endl;
}