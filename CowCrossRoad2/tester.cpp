#include <gtest/gtest.h>
// clang++ -std=c++17  testFileName.cpp -lgtest -lgtest_main -pthread -o
// testername
#include <iostream>
#define TESTING
#include "main.cpp"

TEST(tester, test1) { 
    EXPECT_EQ(solve("ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ"), 13*25); 
}

TEST(tester, sample){
    EXPECT_EQ(solve("ABCCABDDEEFFGGHHIIJJKKLLMMNNOOPPQQRRSSTTUUVVWWXXYYZZ"), 1); 
}
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}