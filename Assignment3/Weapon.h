// Weapon.h
#include <string>

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

    void printInfo() const;
};
   

