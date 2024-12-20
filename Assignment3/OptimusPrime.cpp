#include "OptimusPrime.h"

OptimusPrime::OptimusPrime() 
    : _truckSpeed(0), _armorStrength(0), _leadershipLevel(0) {}

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

