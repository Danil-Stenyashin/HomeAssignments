#include <gtest/gtest.h>
#include "Weapon.h"
#include "Transformer.h"
#include <sstream>


TEST(WeaponTest, OutputOperator) {
    Weapon w("Laser Gun", 50);
    std::ostringstream oss;
    oss << w;
    EXPECT_EQ(oss.str(), "Weapon: Laser Gun, Damage: 50");
}

TEST(WeaponTest, ComparisonOperators) {
    Weapon w1("Laser Gun", 50);
    Weapon w2("Rocket Launcher", 75);
    Weapon w3("Laser Gun", 50);

    EXPECT_TRUE(w1 < w2);
    EXPECT_TRUE(w2 > w1);
    EXPECT_TRUE(w1 == w3);
}

TEST(TransformerTest, OutputOperator) {
    Weapon w("Laser Gun", 50);
    Transformer t(10, 200, 10, 100, 100, w);
    std::ostringstream oss;
    oss << t;
    EXPECT_EQ(oss.str(), "Transformer Level: 10\nStrength: 200, Range: 10\nFuel: 100, Ammo: 100\nWeapon: Weapon: Laser Gun, Damage: 50");
}

TEST(TransformerTest, ComparisonOperators) {
    Transformer t1(10, 200, 10, 100, 100);
    Transformer t2(5, 150, 10, 100, 50);
    Transformer t3(10, 200, 10, 100, 100);

    EXPECT_TRUE(t1 > t2);
    EXPECT_TRUE(t2 < t1);
    EXPECT_TRUE(t1 == t3);
}

TEST(TransformerTest, CompareTransformers) {
    Transformer t1;
    t1.setLevel(5);
    t1.setStrength(150);

    Transformer t2;
    t2.setLevel(5);
    t2.setStrength(150);

    EXPECT_TRUE(t1 == t2);  

    t2.setStrength(200);
    EXPECT_TRUE(t1 != t2);  
}

TEST(OptimusPrimeTest, SetGetAttributes) {
    OptimusPrime optimus;
    optimus.setTruckSpeed(120);
    optimus.setArmorStrength(80);
    optimus.setLeadershipLevel(10);

    EXPECT_EQ(optimus.getTruckSpeed(), 120);
    EXPECT_EQ(optimus.getArmorStrength(), 80);
    EXPECT_EQ(optimus.getLeadershipLevel(), 10);
}

TEST(BumblebeeTest, SetGetAttributes) {
    Bumblebee bumblebee;
    bumblebee.setCamaroSpeed(160);
    bumblebee.setCamaroColor("Black");

    EXPECT_EQ(bumblebee.getCamaroSpeed(), 160);
    EXPECT_EQ(bumblebee.getCamaroColor(), "Black");
}

