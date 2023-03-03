#include <gtest/gtest.h>
// clang++ -std=c++17  testFileName.cpp -lgtest -lgtest_main -pthread -o
// testername
#include <iostream>
#define TESTING
#include "oddphotos.cpp"

TEST(testConvertertest, test1) {
  vector<int> ids{1, 3, 5, 7, 9, 11, 13};
  pair<int, int> evenOdd{0, 7};
  EXPECT_EQ(testConverter(ids), evenOdd);
}

TEST(testConvertertest, test2) {
  vector<int> ids{11, 2, 17, 13, 1, 15, 3};
  pair<int, int> evenOdd{1, 6};
  EXPECT_EQ(testConverter(ids), evenOdd);
}

TEST(testConvertertest, test3) {
  vector<int> ids{1, 4, 8, 312, 7, 12, 78, 136, 67, 89, 43, 12, 9};
  pair<int, int> evenOdd{7, 6};
  EXPECT_EQ(testConverter(ids), evenOdd);
}

TEST(solve, sample1) {
  vector<int> ids{1, 3, 5, 7, 9, 11, 13};
  EXPECT_EQ(solve(testConverter(ids)), 3);
}
TEST(solve, sample2) {
  vector<int> ids{11, 2, 17, 13, 1, 15, 3};
  EXPECT_EQ(solve(testConverter(ids)), 5);
}
TEST(solve, test1) {
  vector<int> ids{1, 4, 8, 312, 7, 12, 78, 136, 67, 89, 43, 12, 9};
  // 4, 1, 8, 7, 312, 67, 12, 89, 78, 43, 136, 9, 12
  EXPECT_EQ(solve(testConverter(ids)), 13);
}

TEST(solve, test2) {
  vector<int> ids(1000);
  for (int i = 0; i < 1000; i++) {
    ids[i] = i / 10;
  }
  EXPECT_EQ(solve(testConverter(ids)), 1000);
}
TEST(solve, test3) {
  vector<int> ids{1, 100};
  EXPECT_EQ(solve(testConverter(ids)), 2);
}
TEST(solve, test4) {
  vector<int> ids{55, 99};
  EXPECT_EQ(solve(testConverter(ids)), 1);
}
TEST(solve, test5) {
  vector<int> ids{2, 100};
  EXPECT_EQ(solve(testConverter(ids)), 1);
}
TEST(solve, test6) {
  vector<int> ids{35, 97, 61};
  EXPECT_EQ(solve(testConverter(ids)), 2);
}
TEST(solve, test7) {
  vector<int> ids{35, 97, 61, 79};
  EXPECT_EQ(solve(testConverter(ids)), 1);
}
TEST(solve, test8) {
  vector<int> ids{35, 97, 61, 79, 91};
  EXPECT_EQ(solve(testConverter(ids)), 3);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}