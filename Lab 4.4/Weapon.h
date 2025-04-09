#pragma once
#include <string>
#include <iostream>

class Weapon {
private:
    std::string name;
    float damage;
    float weight;

public:
    friend class Characteristic;
    Weapon(std::string n, float d, float w);
    Weapon();
    std::string get_name() const;
    void set_damage(float d);
    float get_damage() const;
    float get_weight() const;
    bool max_limit(float m_l);
    float sum_weight(float w);
    float sum_weight(const Weapon& gun);
    ~Weapon();
};