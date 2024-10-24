#include "Transformer.h"

class Bumblebee : public Transformer {
public:
    Bumblebee();

    bool transformToCamaro();
    bool transformToRobot();

    unsigned int getCamaroSpeed() const;
    void setCamaroSpeed(unsigned int speed);
private:
    unsigned int _camaroSpeed;
};
