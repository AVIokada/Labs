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
protected:
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
    virtual float get_damage() const = 0;
    float get_weight() const;
    WeaponType get_type() const;
    bool max_limit(float m_l);
    float sum_weight(float w);
    float sum_weight(const Weapon& gun);

    virtual void Attack() = 0;

    bool operator>(const Weapon& other) const;
    bool operator<(const Weapon& other) const;

    //virtual ~Weapon();
};

template <typename T1, typename T2>
class DualWeapons {
private:
    T1 leftHand;
    T2 rightHand;

public:
    DualWeapons(T1 left, T2 right) : leftHand(left), rightHand(right) {}

    T1 get_left() const { return leftHand; }
    T2 get_right() const { return rightHand; }

    void set_left(T1 weapon) { leftHand = weapon; }
    void set_right(T2 weapon) { rightHand = weapon; }
};