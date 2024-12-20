#include "Megatron.h"

Megatron::Megatron() 
    : _destructionPower(300), _tankArmor(250) {}

Megatron::Megatron(unsigned int power, unsigned int armor) 
    : _destructionPower(power), _tankArmor(armor) {}
    
std::ostream& operator<<(std::ostream& os, const Megatron& t)
{
    os << "Megatron: level: " << t.getLevel() << "\n"
       << "strength: " << t.getStrength() << "\n"
       << "range: " << t.getRange() << "\n"
       << "fuel: " << t.getFuel() << "\n"
       << "ammo: " << t.getAmmo() << "\n"
       << "weapon: " << t.getWeapon() << "\n"
       << "Power: " << t.getDestructionPower() << "\n"
       << "Armor: " << t.getTankArmor() << "\n";
    return os;
}

bool Megatron::transformToTank() {
    return true;
}

bool Megatron::transformToRobot() {
    return true;
}

unsigned int Megatron::getDestructionPower() const {
    return _destructionPower;
}

void Megatron::setDestructionPower(unsigned int power) {
    _destructionPower = power;
}

unsigned int Megatron::getTankArmor() const {
    return _tankArmor;
}

void Megatron::setTankArmor(unsigned int armor) {
    _tankArmor = armor;
}

