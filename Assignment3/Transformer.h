#ifndef TRANSFORMER_H
#define TRANSFORMER_H


class Transformer {

private:
    unsigned int _level;
    unsigned int _strength;
    unsigned int _range;
    unsigned int _fuel;
    unsigned int _ammo;
    Weapon _weapon;
    Weapon* _newWeapon;
    
public:
    Transformer();
    ~Transformer();

    bool move();
    bool turn(Direction dir);
    bool jump();
    bool fire();
    bool ultimate();
    bool transform();
    
    
    
    
    void SetLevel(unsigned int level) {
        _level = level;
    }
    
    unsigned int GetLevel() { 
        return _level;
    }
    
    void SetFuel(unsigned int fuel) {
        _fuel = fuel;
    }
    
    unsigned int GetFuel() { 
        return _fuel;
    }
   
    void SetAmmo(unsigned int ammo) {
        _ammo = ammo;
    }
    
    unsigned int GetAmmo() { 
        return _ammo;
    }
    
    
    
    unsigned int GetStrength() { 
        return _strength;
    }
    
    unsigned int GetRange() { 
        return _range;
    }
    
    void SetNewWeapon(Weapon* weapon) {
        _newWeapon = weapon;
    }
    
    Weapon* GetNewWeapon() const {
        return _newWeapon;
    }
    
};

#endif


