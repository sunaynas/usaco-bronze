#include <gtest/gtest.h>
// clang++ -std=c++17  testFileName.cpp -lgtest -lgtest_main -pthread -o
// testername
#include <iostream>
#define TESTING
#include "main.cpp"

TEST(flipTester, test1) {}
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}