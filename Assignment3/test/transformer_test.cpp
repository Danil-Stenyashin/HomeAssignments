#include "gtest/gtest.h"
#include "Transformer.h"
#include "OptimusPrime.h"
#include "Bumblebee.h"
#include "Megatron.h"

TEST(TransformerTest, BasicTransformer) {
  Transformer transformer;
  ASSERT_EQ(transformer.getLevel(), 1);
  ASSERT_EQ(transformer.getStrength(), 100);
  ASSERT_EQ(transformer.getRange(), 5);
  ASSERT_EQ(transformer.getFuel(), 100);
  ASSERT_EQ(transformer.getAmmo(), 100);
  ASSERT_EQ(transformer.getWeapon().getType(), "Default Weapon");
  ASSERT_EQ(transformer.getWeapon().getDamage(), 10);
}

TEST(OptimusPrimeTest, TruckSpeed) {
  OptimusPrime optimusPrime;
  ASSERT_EQ(optimusPrime.getTruckSpeed(), 100);
  optimusPrime.setTruckSpeed(150);
  ASSERT_EQ(optimusPrime.getTruckSpeed(), 150);
}

TEST(BumblebeeTest, CamaroSpeed) {
  Bumblebee bumblebee;
  ASSERT_EQ(bumblebee.getCamaroSpeed(), 150);
  bumblebee.setCamaroSpeed(200);
  ASSERT_EQ(bumblebee.getCamaroSpeed(), 200);
}

TEST(TransformerTest, Fire) {
  Transformer transformer;
  ASSERT_EQ(transformer.getAmmo(), 100);
  ASSERT_TRUE(transformer.fire());
  ASSERT_EQ(transformer.getAmmo(), 99);
  ASSERT_FALSE(transformer.fire() == 0); 
}
