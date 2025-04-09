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

    float get_total_damage() const {
        return get_damage() + extraDamage;
    }
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");


    Weapon sword("Sword", 50, 3, ONEHANDED);
    cout << sword.get_name() << " - ";

    if (sword.get_type() == ONEHANDED) {
        cout << "Одноручное";
    }
    else if (sword.get_type() == TWOHANDED) {
        cout << "Двуручное";
    }
    else if (sword.get_type() == BOW) {
        cout << "Лук";
    }
    else if (sword.get_type() == CROSSBOW) {
        cout << "Арбалет";
    }
    cout << " оружие" << endl;

    Player player;
    player.id = 1;
    player.login = "warrior123";
    player.password = "securePass";
    player.print();

    MagicWeapon mw1;
    MagicWeapon mw2("Fire Staff", 35, 2, TWOHANDED, 25);

    cout << "1. " << mw1.get_name()
        << " (Урон: " << mw1.get_total_damage()
        << ", Доп. урон: " << mw1.get_extra_damage() << ")" << endl;

    cout << "2. " << mw2.get_name()
        << " (Урон: " << mw2.get_total_damage()
        << ", Доп. урон: " << mw2.get_extra_damage() << ")" << endl;

 
    cout << "Вес mw1: " << mw1.get_weight() << "кг" << endl;
    cout << "Тип mw2: ";
    if (mw2.get_type() == TWOHANDED) cout << "Двуручное" << endl;

    mw1.set_damage(30);
    cout << "Новый урон mw1: " << mw1.get_damage() << endl;
}