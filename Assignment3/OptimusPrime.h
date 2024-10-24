#include "Transformer.h"

class OptimusPrime : public Transformer {
public:
    OptimusPrime();

    bool transformToTruck();
    bool transformToRobot();

    unsigned int getTruckSpeed() const;
    void setTruckSpeed(uint speed);
private:
    unsigned int _truckSpeed;
};
