#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

class Weapon {
protected:
    std::string type;
    int damage;

public:
       
    Weapon() : type("AK-47"), damage(40) {}
    Weapon(const std::string& type, int damage) : type(type), damage(damage) {}

    const std::string& getType() const { return type; }
    const int& getDamage() const { return damage; }

    void setType(const std::string& type) { this->type = type; }
    void setDamage(int damage) { this->damage = damage; }
    
    std::string getType() {return type;}
    int getDamage() {return damage;}

    
    friend std::ostream& operator<<(std::ostream& os, const Weapon& w);
};
   
#endif // WEAPON_H
