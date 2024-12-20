#include <gtest/gtest.h>
#include "Transformer.h"
#include "Bumblebee.h"
#include "Megatron.h"
#include "OptimusPrime.h"
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

// Тест метода move
TEST(TransformerTest, Move) {
    Transformer t;
    EXPECT_TRUE(t.move());
}


// Тест метода jump
TEST(TransformerTest, Jump) {
    Transformer t;
    EXPECT_TRUE(t.jump());
}

// Тест метода fire
TEST(TransformerTest, Fire) {
    Transformer t;
    t.setAmmo(3);
    EXPECT_TRUE(t.fire()); // Уменьшается боезапас
    EXPECT_EQ(t.getAmmo(), 2);
    EXPECT_TRUE(t.fire());
    EXPECT_EQ(t.getAmmo(), 1);
    EXPECT_TRUE(t.fire());
    EXPECT_EQ(t.getAmmo(), 0);
    EXPECT_FALSE(t.fire()); // Боезапас исчерпан
}

// Тест метода transform
TEST(TransformerTest, Transform) {
    Transformer t;
    EXPECT_TRUE(t.transform());
}

// Тест метода ultimate
TEST(TransformerTest, Ultimate) {
    Transformer t;
    EXPECT_TRUE(t.ultimate());
}

// Тест геттеров и сеттеров
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

// Тест геттеров и сеттеров для Weapon
TEST(TransformerTest, SetGetWeapon) {
    Transformer t;
    Weapon newWeapon("Laser Cannon", 50);
    t.setWeapon(newWeapon);

    EXPECT_EQ(t.getWeapon().getType(), "Laser Cannon");
    EXPECT_EQ(t.getWeapon().getDamage(), 50);
}

// Тест конструктора и деструктора (утечка памяти)
TEST(TransformerTest, DestructorSafety) {
    Transformer* t = new Transformer();
    Weapon newWeapon("Rocket Launcher", 75);
    t->setWeapon(newWeapon);

    EXPECT_EQ(t->getWeapon().getType(), "Rocket Launcher");
    EXPECT_EQ(t->getWeapon().getDamage(), 75);

    delete t; // Проверяем, что деструктор освобождает память
}
