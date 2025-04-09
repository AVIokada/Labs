#include "Weapon.h"
#include <string>

Weapon::Weapon(std::string n, float d, float w)
    : name(n), damage(d), weight(w) {}

Weapon::Weapon() : Weapon("Glock", 37, 0.9f) {}


std::string Weapon::get_name() const {
    return name;
}

float Weapon::get_damage() const {
    return damage;
}

void Weapon::set_damage(float d) {
    if (d >= 0) {
        this->damage = d;
    }
    else {
        this->damage = 0;
        std::cout << "Урон не может быть меньше 0!" << std::endl;
    }

}

float Weapon::get_weight() const {
    return weight;
}

bool Weapon::max_limit(float m_l) {
    return m_l >= weight;
}

float Weapon::sum_weight(float w) {
    return w + weight;
}

float Weapon::sum_weight(const Weapon& gun) {
    return weight + gun.weight;
}

Weapon::~Weapon() {
    std::cout << "\nУдаление следующего оружия:" << std::endl;
    std::cout << name << "/" << damage << "/" << weight << "кг" << std::endl;
}