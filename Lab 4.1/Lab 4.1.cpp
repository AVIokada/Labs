#include <iostream>
#include <Windows.h>
using namespace std;


class Weapon {

public:
    string name;
    float damage;
    float weight;

    Weapon(string n, float d, float w) {
        name = n;
        damage = d;
        weight = w;
    }

    Weapon() : Weapon("Glock", 37, 0.9) {};
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");

    Weapon id_0001("Ak-47", 65, 5);
    Weapon id_0002;

    cout << id_0001.name << ": " << id_0001.damage << "/" << id_0001.weight << "кг" << endl;
    cout << id_0002.name << ": " << id_0002.damage << "/" << id_0002.weight << "кг" << endl;
}