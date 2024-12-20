#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <string>
#include "Weapon.h"
#include "Vehicle.h"


class Transformer {
private:
    unsigned int _level;
    unsigned int _strength;
    unsigned int _range;
    unsigned int _fuel;
    unsigned int _ammo;

    Weapon _weapon;
    Vehicle* _vehicle;
    
public:
    Transformer();
    ~Transformer();

    bool move();
    bool jump();

    unsigned int getLevel() const;
    void setLevel(unsigned int level);

    unsigned int getStrength() const;
    void setStrength(unsigned int strength);

    unsigned int getRange() const;
    void setRange(unsigned int range);

    unsigned int getFuel() const;
    void setFuel(unsigned int fuel);

    unsigned int getAmmo() const;
    void setAmmo(unsigned int ammo);

    const Weapon& getWeapon() const;
    void setWeapon(const Weapon& weapon);
    
    const Vehicle* getVehicle() const;
    void assignVehicle(Vehicle* v);
};

#endif 

