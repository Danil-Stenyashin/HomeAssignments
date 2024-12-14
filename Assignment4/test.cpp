#include <gtest/gtest.h>
#include "Transformer.h"
#include "Bumblebee.h"
#include "head.h"
#include "Megatron.h"
#include "OptimusPrime.h"
#include "Weapon.h"
#include <sstream>


TEST(TransformerTest, OutputOperator) {
    Transformer t(10, 200, 10, 100, 50, Weapon("Laser", 50));
    std::ostringstream oss;
    oss << t;
    std::string expected_output = "Level: 10\nStrength: 200\nRange: 10\nFuel: 100\nAmmo: 50\nWeapon: Laser (Damage: 50)\n";
    EXPECT_EQ(oss.str(), expected_output);
}

// Тест для оператора сравнения
TEST(TransformerTest, ComparisonOperator) {
    Transformer t1(10, 200, 10, 100, 50, Weapon("Laser", 50));
    Transformer t2(10, 150, 10, 100, 50, Weapon("Laser", 50));

    EXPECT_TRUE(t1 > t2);
    EXPECT_FALSE(t1 < t2);
}


TEST(WeaponTest, PrintInfo) {
    // Создаем объект Weapon с заданными параметрами
    Weapon w("Laser Cannon", 75);

    // Перенаправляем стандартный вывод в строковый поток
    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());

    // Вызываем метод printInfo
    w.printInfo();

    // Возвращаем стандартный вывод к исходному состоянию
    std::cout.rdbuf(oldCoutBuf);

    // Проверяем содержимое потока
    std::string expectedOutput = 
        "Type: Laser Cannon\n"
        "Damage: 75\n";

    EXPECT_EQ(output.str(), expectedOutput);
}

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
