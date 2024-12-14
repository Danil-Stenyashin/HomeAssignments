#include "Bumblebee.h"

Bumblebee::Bumblebee() : _camaroSpeed(150) {}

bool Bumblebee::transformToCamaro() { return true; }

bool Bumblebee::transformToRobot() { return true; }

unsigned int Bumblebee::getCamaroSpeed() const { return _camaroSpeed; }

void Bumblebee::setCamaroSpeed(unsigned int speed) { _camaroSpeed = speed; }
