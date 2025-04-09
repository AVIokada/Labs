#include "Weapon.h"

Weapon::Weapon(std::string n, float d, float w, WeaponType t)
    : name(n), damage(d), weight(w), type(t) {}

Weapon::Weapon() : Weapon("Glock", 37, 0.9f, ONEHANDED) {}

std::string Weapon::get_name() const { return name; }

void Weapon::set_damage(float d) {
    if (d >= 0) {
        this->damage = d;
    }
    else {
        this->damage = 0;
        std::cout << "Урон не может быть меньше 0!" << std::endl;
    }

}

float Weapon::get_weight() const { return weight; }
WeaponType Weapon::get_type() const { return type; }
bool Weapon::max_limit(float m_l) { return m_l >= weight; }
float Weapon::sum_weight(float w) { return w + weight; }
float Weapon::sum_weight(const Weapon& gun) { return weight + gun.weight; }

bool Weapon::operator>(const Weapon& other) const {
    return this->get_damage() > other.get_damage();
}

bool Weapon::operator<(const Weapon& other) const {
    return this->get_damage() < other.get_damage();
}

//Weapon::~Weapon() {
//    std::cout << "\nУдаление оружия: " << name 
//              << "/" << damage << "/" << weight << "кг" << std::endl;
//}