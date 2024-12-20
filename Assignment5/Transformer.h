#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <string>
#include <iostream>
#include "Vehicle.h"
#include "Weapon.h"
#include <iostream>

class Transformer
{
protected:
    std::string name;
    unsigned health;
    unsigned level;

    unsigned strength;
    unsigned perception;

    Weapon weapon;
    Vehicle* vehicle;

public:
    Transformer();

    Transformer(const std::string& name, unsigned health, unsigned level, unsigned strength, unsigned perception, const Weapon& weapon);

    virtual ~Transformer();

    friend std::ostream& operator<<(std::ostream& os, const Transformer& t);

    bool operator>(const Transformer& other) const;

    bool operator<(const Transformer& other) const;

    const std::string& getName() const;
    void setName(const std::string& name);
    
    
    const unsigned& getHealth() const;
    void setHealth(unsigned health);
    
    
    const unsigned& getLevel() const;
    void setLevel(unsigned level);
    
    const unsigned& getStrength() const;
    void setStrength(unsigned strength);
    
    const unsigned& getPerception() const;
    void setPerception(unsigned perception);
    
    const Weapon& getWeapon() const;
    void setWeapon(const Weapon& weapon);
    
    const Vehicle* getVehicle() const;
    void assignVehicle(Vehicle* v);
    
    
    

    virtual void transform() const;
    virtual void openFire() const;
    virtual void ulta() const;

    bool attack();
};

#endif
