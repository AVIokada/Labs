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

struct Player {
    int id;
    string login;
    string password;

    void print() const {
        cout << "ID: " << id << endl
            << "Логин: " << login << endl
            << "Пароль: " << password << endl;
    }
};

class MagicWeapon : public Weapon {
private:
    float extraDamage;

public:
    MagicWeapon(string n, float d, float w, WeaponType t, float ed)
        : Weapon(n, d, w, t), extraDamage(ed) {}

    MagicWeapon() : MagicWeapon("Staff", 25, 1.5f, TWOHANDED, 15) {}

    float get_extra_damage() const { return extraDamage; }

    float get_damage() const override {
        return Weapon::get_damage() + extraDamage;
    }
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");


    Weapon* weapons[2];
    weapons[0] = new Weapon("Sword", 50, 3, ONEHANDED);
    weapons[1] = new MagicWeapon("Fire Staff", 35, 2, TWOHANDED, 25);

    cout << "Обычное оружие: " << weapons[0]->get_damage() << endl;
    cout << "Магическое оружие: " << weapons[1]->get_damage() << endl;

    if (*weapons[0] > *weapons[1]) {
        cout << weapons[0]->get_name() << " сильнее" << endl;
    }
    else {
        cout << weapons[1]->get_name() << " сильнее" << endl;
    }

    for (auto w : weapons) {
        delete w;
    }
}