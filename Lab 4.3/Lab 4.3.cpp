#include <iostream>
#include <Windows.h>
using namespace std;

#include "Weapon.h"




int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");

    Weapon id_0001("Ak-47", 65, 5);
    cout << id_0001.sum_weight(15) << endl;
    Weapon id_0002;
    cout << id_0002.sum_weight(id_0001) << endl;

    cout << id_0001.max_limit(4) << endl;

    Weapon* id_0003 = new Weapon("Deagle", 75, 2);

    cout << id_0003->name << ": " << id_0003->damage << "/" << id_0003->weight << "кг" << endl;

    cout << "Вес калаша и дигла равна " << id_0001.sum_weight(*id_0003) << "кг" << endl;
    cout << "Котелок массой 3 кг и глок весят " << id_0002.sum_weight(3) << "кг" << endl;

    delete id_0003;
}