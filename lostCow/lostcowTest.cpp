#include <iostream>
//include the google test dependencies
#include <gtest/gtest.h>
#define TESTING
// int findDistance(int farmerStartPos, int bessiePos);
#include "lostcow.cpp"
//our first unit test
TEST(basic, test1)
{
  EXPECT_EQ(findDistance(3, 6), 9) << "The distance is not correct";
}

TEST(basic, test2)
{
  EXPECT_EQ(findDistance(3, 60), 183) << "The distance is not correct";
  EXPECT_EQ(findDistance(3, 3), 0) << "The distance is not correct";
  EXPECT_EQ(findDistance(0, 0), 0) << "The distance is not correct";
  EXPECT_EQ(findDistance(0, 1), 1) << "The distance is not correct";
  EXPECT_EQ(findDistance(0,2), 8) << "The distance is not correct";
}
// #ifdef TESTING
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
//#endif
