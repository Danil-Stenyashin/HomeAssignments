#ifndef AUTOBOT_H
#define AUTOBOT_H

#include "Transformer.h"

class Autobot : public Transformer {
public:
    void transform() const override {
        std::cout << "Transform method called from Autobot" << std::endl;
    }

    void openFire() const override {
        std::cout << "OpenFire method called from Autobot" << std::endl;
    }

    void ultimate() const override {
        std::cout << "Ultimate method called from Autobot" << std::endl;
    }
};

#endif // AUTOBOT_H
