#ifndef BUMBLEBEE_H
#define BUMBLEBEE_H


class Bumblebee : public Transformer {
public:
    Bumblebee();

    bool transformToCamaro();
    bool transformToRobot();

    unsigned int getCamaroSpeed() const;
    void setCamaroSpeed(unsigned int speed);

    const std::string& getCamaroColor() const;
    void setCamaroColor(const std::string& color);

    unsigned int getIntelligenceLevel() const;
    void setIntelligenceLevel(unsigned int level);

private:
    unsigned int _camaroSpeed;
    std::string _camaroColor;
    unsigned int _intelligenceLevel;
};
#endif
