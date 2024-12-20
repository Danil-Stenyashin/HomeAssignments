#ifndef BUMBLEBEE_H
#define BUMBLEBEE_H 

#include <string>
#include "Transformer.h"

class Bumblebee : public Transformer {
public:
    Bumblebee();

    unsigned int getCamaroSpeed() const;
    void setCamaroSpeed(unsigned int speed);

    const std::string& getCamaroColor() const;
    void setCamaroColor(const std::string& color);

private:
    unsigned int _camaroSpeed;
    std::string _camaroColor;
};

#endif

