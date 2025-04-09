#pragma once
#include <string>
#include <iostream>

enum WeaponType {
    ONEHANDED,
    TWOHANDED,
    BOW,
    CROSSBOW
};

class Weapon {
private:
    std::string name;
    float damage;
    float weight;
    WeaponType type;

public:
    friend class Characteristic;
    Weapon(std::string n, float d, float w, WeaponType t);
    Weapon();
    std::string get_name() const;
    void set_damage(float d);
    virtual float get_damage() const;
    float get_weight() const;
    WeaponType get_type() const;
    bool max_limit(float m_l);
    float sum_weight(float w);
    float sum_weight(const Weapon& gun);

    bool operator>(const Weapon& other) const;
    bool operator<(const Weapon& other) const;

    ~Weapon();
};