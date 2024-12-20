#include "Megatron.h"

Megatron::Megatron() 
    : _destructionPower(300), _tankArmor(250) {}

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

