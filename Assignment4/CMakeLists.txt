   cmake_minimum_required(VERSION 3.10)
   project(Transformers)

   add_executable(transformer main.cpp Transformer.cpp OptimusPrime.cpp Bumblebee.cpp Megatron.cpp Weapon.cpp)
   add_executable(transformer_tests test/transformer_test.cpp)
   target_link_libraries(transformer_tests gtest gtest_main)

   include_directories(test)
   include_directories(include)

   find_package(GTest REQUIRED)
   
