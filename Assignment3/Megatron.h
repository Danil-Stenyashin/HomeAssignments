#ifndef MEGATRON_H
#define MEGATRON_H

#include "Transformer.h"

class Megatron : public Transformer {
public:
    Megatron();

    bool transformToTank();
    bool transformToRobot();

    unsigned int getDestructionPower() const;
    void setDestructionPower(unsigned int power);

    unsigned int getTankArmor() const;
    void setTankArmor(unsigned int armor);

private:
    unsigned int _destructionPower;
    unsigned int _tankArmor;
};

#endif // MEGATRON_H
