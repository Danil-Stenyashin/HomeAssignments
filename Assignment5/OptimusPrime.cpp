#include "OptimusPrime.h"
#include <iostream>  // Для оператора <<

OptimusPrime::OptimusPrime() : _truckSpeed(100) {}

OptimusPrime::OptimusPrime(unsigned int level, unsigned int strength, unsigned int range, unsigned int fuel, unsigned int ammo, unsigned int truckSpeed)
    : Transformer(level, strength, range, fuel, ammo, Weapon("Truck Weapon", 30)), _truckSpeed(truckSpeed) {}

bool OptimusPrime::transformToTruck() { return true; }

bool OptimusPrime::transformToRobot() { return true; }

unsigned int OptimusPrime::getTruckSpeed() const { return _truckSpeed; }

void OptimusPrime::setTruckSpeed(unsigned int speed) { _truckSpeed = speed; }

std::ostream& operator<<(std::ostream& os, const OptimusPrime& op) {
    os << static_cast<const Transformer&>(op);  // Выводим общие данные
    os << "Truck Speed: " << op.getTruckSpeed() << "\n";
    return os;
}

