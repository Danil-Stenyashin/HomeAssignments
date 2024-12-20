#include "Bumblebee.h"

Bumblebee::Bumblebee() 
    : _camaroSpeed(150), _camaroColor("Yellow"), _intelligenceLevel(8) {}

bool Bumblebee::transformToCamaro() { return true; }

bool Bumblebee::transformToRobot() { return true; }

unsigned int Bumblebee::getCamaroSpeed() const { return _camaroSpeed; }
void Bumblebee::setCamaroSpeed(unsigned int speed) { _camaroSpeed = speed; }

const std::string& Bumblebee::getCamaroColor() const { return _camaroColor; }
void Bumblebee::setCamaroColor(const std::string& color) { _camaroColor = color; }

unsigned int Bumblebee::getIntelligenceLevel() const { return _intelligenceLevel; }
void Bumblebee::setIntelligenceLevel(unsigned int level) { _intelligenceLevel = level; }

