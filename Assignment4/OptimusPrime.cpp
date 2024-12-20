#include "OptimusPrime.h"

OptimusPrime::OptimusPrime() : _truckSpeed(0), _armorStrength(0), _leadershipLevel(0) {}

OptimusPrime::OptimusPrime(unsigned int truckSpeed, unsigned int armorStrength, unsigned int leadershipLevel) : _truckSpeed(truckSpeed), _armorStrength(armorStrength), _leadershipLevel(leadershipLevel) {}

std::ostream& operator<<(std::ostream& os, const OptimusPrime& t)
{
    os << "OptimusPrime: level: " << t.getLevel() << "\n"
       << "strength: " << t.getStrength() << "\n"
       << "range: " << t.getRange() << "\n"
       << "fuel: " << t.getFuel() << "\n"
       << "ammo: " << t.getAmmo() << "\n"
       << "weapon: " << t.getWeapon() << "\n"
       << "Truck Speed: " << t.getTruckSpeed() << "\n"
       << "Armor Strength: " << t.getArmorStrength() << "\n"
       << "Leadership Level: " << t.getLeadershipLevel() << "\n";
    return os;
}

bool OptimusPrime::transformToTruck() {
    return true;
}

bool OptimusPrime::transformToRobot() {
    return true;
}

unsigned int OptimusPrime::getTruckSpeed() const {
    return _truckSpeed;
}

void OptimusPrime::setTruckSpeed(unsigned int speed) {
    _truckSpeed = speed;
}

unsigned int OptimusPrime::getArmorStrength() const {
    return _armorStrength;
}

void OptimusPrime::setArmorStrength(unsigned int strength) {
    _armorStrength = strength;
}

unsigned int OptimusPrime::getLeadershipLevel() const {
    return _leadershipLevel;
}

void OptimusPrime::setLeadershipLevel(unsigned int level) {
    _leadershipLevel = level;
}

