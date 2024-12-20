#include <gtest/gtest.h>
#include "Transformer.h"
#include "Weapon.h"
#include <sstream>

TEST(TransformerTest, DefaultConstructor) {
    Transformer t;
    EXPECT_EQ(t.getLevel(), 1);
    EXPECT_EQ(t.getStrength(), 100);
    EXPECT_EQ(t.getRange(), 5);
    EXPECT_EQ(t.getFuel(), 100);
    EXPECT_EQ(t.getAmmo(), 100);
    EXPECT_EQ(t.getWeapon().getType(), "Default Weapon");
    EXPECT_EQ(t.getWeapon().getDamage(), 10);
}

TEST(TransformerTest, Move) {
    Transformer t;
    EXPECT_TRUE(t.move());
}

TEST(TransformerTest, Jump) {
    Transformer t;
    EXPECT_TRUE(t.jump());
}

TEST(TransformerTest, Fire) {
    Transformer t;
    t.setAmmo(3);
    EXPECT_TRUE(t.fire()); 
    EXPECT_EQ(t.getAmmo(), 2);
    EXPECT_TRUE(t.fire());
    EXPECT_EQ(t.getAmmo(), 1);
    EXPECT_TRUE(t.fire());
    EXPECT_EQ(t.getAmmo(), 0);
    EXPECT_FALSE(t.fire()); 
}

TEST(TransformerTest, Transform) {
    Transformer t;
    EXPECT_TRUE(t.transform());
}

TEST(TransformerTest, Ultimate) {
    Transformer t;
    EXPECT_TRUE(t.ultimate());
}

TEST(TransformerTest, SetGetAttributes) {
    Transformer t;
    t.setLevel(5);
    EXPECT_EQ(t.getLevel(), 5);

    t.setStrength(150);
    EXPECT_EQ(t.getStrength(), 150);

    t.setRange(10);
    EXPECT_EQ(t.getRange(), 10);

    t.setFuel(80);
    EXPECT_EQ(t.getFuel(), 80);

    t.setAmmo(50);
    EXPECT_EQ(t.getAmmo(), 50);
}

TEST(TransformerTest, SetGetWeapon) {
    Transformer t;
    Weapon newWeapon("Laser Cannon", 50);
    t.setWeapon(newWeapon);

    EXPECT_EQ(t.getWeapon().getType(), "Laser Cannon");
    EXPECT_EQ(t.getWeapon().getDamage(), 50);
}

TEST(TransformerTest, DestructorSafety) {
    Transformer* t = new Transformer();
    Weapon newWeapon("Rocket Launcher", 75);
    t->setWeapon(newWeapon);

    EXPECT_EQ(t->getWeapon().getType(), "Rocket Launcher");
    EXPECT_EQ(t->getWeapon().getDamage(), 75);

    delete t;
}

TEST(TransformerTest, PrimarySecondaryWeapon) {
    Transformer t;

    Weapon primary("Plasma Gun", 50);
    Weapon secondary("Shield", 20);

    t.setPrimaryWeapon(primary);
    t.setSecondaryWeapon(secondary);

    EXPECT_EQ(t.getPrimaryWeapon().getType(), "Plasma Gun");
    EXPECT_EQ(t.getPrimaryWeapon().getDamage(), 50);
    EXPECT_EQ(t.getSecondaryWeapon().getType(), "Shield");
    EXPECT_EQ(t.getSecondaryWeapon().getDamage(), 20);
}

