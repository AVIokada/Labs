#pragma once
#include <string>
#include <iostream>

class Weapon {
public:
    std::string name;
    float damage;
    float weight;

    Weapon(std::string n, float d, float w);
    Weapon();
    bool max_limit(float m_l);
    float sum_weight(float w);
    float sum_weight(const Weapon& gun);
    ~Weapon();
};