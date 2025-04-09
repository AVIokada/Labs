#include <iostream>
#include <Windows.h>
#include "Weapon.h"

using namespace std;

class Characteristic {
private:
    float power;

public:
    Characteristic() : power(1) {}
    Characteristic(float n) : power(n > 1 ? n : 1) {}

    float get_power() const { return power; }
    void set_power(float n) { power = n > 1 ? n : 1; }
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
        return Weapon::damage + extraDamage;
    }

    void Attack() override {
        cout << "Атакуем магическим оружием" << endl;
    }
};

class DisposableWeapon : public Weapon {
private:
    bool used;

public:
    DisposableWeapon(string n, float d, float w, WeaponType t)
        : Weapon(n, d, w, t), used(false) {}

    float get_damage() const override {
        if (used) {
            return 0;
        }
        else {
            return Weapon::damage;
        }
    }

    void Attack() override {
        if (used) {
            cout << "Оружие уже было использовано" << endl;
            cout << "Нанесено " << 0 << " урона" << endl;
        }
        else {
            cout << "Атакуем одноразовым оружием" << endl;
            cout << "Нанесено " << damage << " урона" << endl;
            used = true;
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");

    MagicWeapon mw;
    mw.Attack();
    mw.Attack();
    cout << "Урон: " << mw.get_damage() << endl;
    cout << endl;

    DisposableWeapon dw("Кинжал", 40, 0.5f, ONEHANDED);
    dw.Attack();
    dw.Attack();
    cout << endl;

    DualWeapons<MagicWeapon, int> dual1(mw, 123);
    cout << "Левая рука: " << dual1.get_left().get_name() << endl;
    cout << "Правая рука (ID): " << dual1.get_right() << endl;

    DualWeapons<DisposableWeapon, DisposableWeapon> dual2(
        DisposableWeapon("Нож", 20, 0.3f, ONEHANDED),
        DisposableWeapon("Кинжал", 30, 0.4f, ONEHANDED)
    );
    cout << "Оружие в левой руке: " << dual2.get_left().get_name() << endl;
    cout << "Оружие в правой руке: " << dual2.get_right().get_name() << endl;

}