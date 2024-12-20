#ifndef DECEPTICON_H
#define DECEPTICON_H

#include <string>
#include <iostream>
#include "Transformer.h"


class Decepticon : public Transformer
{
private:
    std::string rank;
    std::string role;

public:
    Decepticon();

    Decepticon(const std::string& name, unsigned health, unsigned level, unsigned strength, unsigned perception, const Weapon& weapon, const std::string& rank, const std::string& role);

    

    void setRank(const std::string& rank);
    const std::string& getRank() const;
    
    void setRole(const std::string& role);
    const std::string& getRole() const;

    
    
    friend std::ostream& operator<<(std::ostream& os, const Decepticon& t);
    void transform() const override;
    void openFire() const override;
    void ulta() const override;

    bool defend();
    bool heal();
};


#endif
