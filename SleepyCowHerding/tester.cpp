#include <gtest/gtest.h>
// clang++ -std=c++17  main.cpp -lgtest -lgtest_main -pthread -o tester
#include <iostream>
#define TESTING
#include "main.cpp"
TEST(tester, test1){

}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}