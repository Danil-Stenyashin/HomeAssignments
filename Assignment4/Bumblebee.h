#ifndef BUMBLEBEE_H
#define BUMBLEBEE_H 

#include <string>
#include "Transformer.h"

class Bumblebee : public Transformer {
public:
    Bumblebee();
    Bumblebee(unsigned int speed, std::string color);
    
    friend std::ostream& operator<<(std::ostream& os, const Bumblebee& t);

    unsigned int getCamaroSpeed() const;
    void setCamaroSpeed(unsigned int speed);

    const std::string& getCamaroColor() const;
    void setCamaroColor(const std::string& color);

private:
    unsigned int _camaroSpeed;
    std::string _camaroColor;
};

#endif

