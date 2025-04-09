#include "Weapon.h"

Weapon::Weapon(std::string n, float d, float w)
    : name(n), damage(d), weight(w) {}

Weapon::Weapon() : Weapon("Glock", 37, 0.9f) {}

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