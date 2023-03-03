// situation1: there exists some g-> such that there is a <-l greater than it
//  for this one need to consider what happens if there is a <-l b4 the range or
//  a g-> after
// sit 2: all <-l come before all g->
// sit 3&4: there are only <-l or only g->
//  also need to worry about time
// technically if there is 1000 instructions and 10^9 possible iterations
// it would go over
// also make sure ranges are correct, L or G can be = 0

#include <gtest/gtest.h>
// clang++ -std=c++17  testFileName.cpp -lgtest -lgtest_main -pthread -o
// testername
#include <iostream>
#define TESTING
#include "countingLiars2.cpp"

TEST(findOverlapGcow, test1) {
  pair<char, int> cow1 = {'G', 1000};
  pair<char, int> cow2 = {'L', 1000};
  EXPECT_EQ(findOverlap(cow1, cow2), true);
}
TEST(findOverlapGcow, test2) {
  pair<char, int> cow1 = {'G', 345609};
  pair<char, int> cow2 = {'L', 123456789};
  EXPECT_EQ(findOverlap(cow1, cow2), true);
}
TEST(findOverlapGcow, test3) {
  pair<char, int> cow1 = {'G', 459732567};
  pair<char, int> cow2 = {'L', 4679};
  EXPECT_EQ(findOverlap(cow1, cow2), false);
}
TEST(findOverlapGcow, test4) {
  pair<char, int> cow1 = {'G', 0};
  pair<char, int> cow2 = {'G', 0};
  EXPECT_EQ(findOverlap(cow1, cow2), true);
}
TEST(findOverlapGcow, test5) {
  pair<char, int> cow1 = {'G', 1000000000};
  pair<char, int> cow2 = {'G', 0};
  EXPECT_EQ(findOverlap(cow1, cow2), true);
}
TEST(findOverlapGcow, test6) {
  pair<char, int> cow1 = {'G', 0};
  pair<char, int> cow2 = {'G', 1000000000};
  EXPECT_EQ(findOverlap(cow1, cow2), false);
}

TEST(findOverlapLcow, test1) {
  pair<char, int> cow1 = {'L', 1000};
  pair<char, int> cow2 = {'L', 1000};
  EXPECT_EQ(findOverlap(cow1, cow2), true);
}
TEST(findOverlapLcow, test2) {
  pair<char, int> cow1 = {'L', 0};
  pair<char, int> cow2 = {'L', 1000000000};
  EXPECT_EQ(findOverlap(cow1, cow2), true);
}
TEST(findOverlapLcow, test3) {
  pair<char, int> cow1 = {'L', 1000000000};
  pair<char, int> cow2 = {'L', 0};
  EXPECT_EQ(findOverlap(cow1, cow2), false);
}
TEST(findOverlapLcow, test4) {
  pair<char, int> cow1 = {'L', 0};
  pair<char, int> cow2 = {'G', 0};
  EXPECT_EQ(findOverlap(cow1, cow2), true);
}
TEST(findOverlapLcow, test5) {
  pair<char, int> cow1 = {'L', 459732567};
  pair<char, int> cow2 = {'G', 4679};
  EXPECT_EQ(findOverlap(cow1, cow2), true);
}
TEST(findOverlapLcow, test6) {
  pair<char, int> cow1 = {'L', 345609};
  pair<char, int> cow2 = {'G', 123456789};
  EXPECT_EQ(findOverlap(cow1, cow2), false);
}

TEST(solve, test1) {
  vector<pair<char, int> > instructions(1000);
  for (int i = 0; i < 1000; i++) {
    instructions[i] = {'G', i};
  }
  EXPECT_EQ(solve(instructions), 0);
}
TEST(solve, test2) {
  vector<pair<char, int> > instructions(1000);
  for (int i = 0; i < 1000; i++) {
    instructions[i] = {'L', i};
  }
  EXPECT_EQ(solve(instructions), 0);
}
TEST(solve, test3) {
  vector<pair<char, int> > instructions(1000);
  for (int i = 0; i < 1000; i++) {
    if (i % 2 == 0) {
      instructions[i] = {'G', i};
    } else {
      instructions[i] = {'L', i};
    }
  }
  EXPECT_EQ(solve(instructions), 499);
}
TEST(solve, example1) {
  vector<pair<char, int> > instructions{{'G', 3}, {'L', 5}};
  EXPECT_EQ(solve(instructions), 0);
}
TEST(solve, example2) {
  vector<pair<char, int> > instructions{{'G', 3}, {'L', 2}};
  EXPECT_EQ(solve(instructions), 1);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}