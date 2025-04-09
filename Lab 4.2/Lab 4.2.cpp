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

    bool max_limit(float m_l) {
        if (m_l >= weight) { return true; }
        else { return false; }
    }

    float sum_weight(float w) {
        return w + this->weight;
    }


    float sum_weight(const Weapon& gun) {
        return sum_weight(gun.weight);
    }

    ~Weapon() {
        cout << endl << "Удаление следующего оружия:" << endl;
        cout << name << "/" << damage << "/" << weight << "кг" << endl;
    }
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

    Weapon* id_0003 = new Weapon("Deagle", 75, 2);

    cout << id_0003->name << ": " << id_0003->damage << "/" << id_0003->weight << "кг" << endl;

    cout << "Вес калаша и дигла равна " << id_0001.sum_weight(*id_0003) << "кг" << endl;
    cout << "Котелок массой 3 кг и глок весят " << id_0002.sum_weight(3) << "кг" << endl;

    delete id_0003;
}