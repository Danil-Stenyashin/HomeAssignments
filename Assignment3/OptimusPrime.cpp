#include "OptimusPrime.h"

OptimusPrime::OptimusPrime() : _truckSpeed(100) {}

bool OptimusPrime::transformToTruck() { return true; }

bool OptimusPrime::transformToRobot() { return true; }

unsigned int OptimusPrime::getTruckSpeed() const { return _truckSpeed; }

void OptimusPrime::setTruckSpeed(unsigned int speed) { _truckSpeed = speed; }
