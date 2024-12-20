#include "Bumblebee.h"
#include <string>

Bumblebee::Bumblebee()
    : _camaroSpeed(150), _camaroColor("Yellow"), _intelligenceLevel(8) {}

unsigned int Bumblebee::getCamaroSpeed() const { return _camaroSpeed; }
void Bumblebee::setCamaroSpeed(unsigned int speed) { _camaroSpeed = speed; }

const std::string& Bumblebee::getCamaroColor() const { return _camaroColor; }
void Bumblebee::setCamaroColor(const std::string& color) { _camaroColor = color; }

