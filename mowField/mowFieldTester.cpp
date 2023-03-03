#include <iostream>
#include <gtest/gtest.h>
#define TESTING
#include "mowfield.cpp"


map<pair<int, int>, int> field;
int testtime = 8;

TEST (movetractortest, test1){
    int spaceBtwnRevisits = -1;
    pair<int, int> fjposition (0,0);
    // field[fjposition] = 0;
    movetractor(testtime, field, spaceBtwnRevisits, fjposition);
    EXPECT_EQ(spaceBtwnRevisits , -1)<< "The answer is not correct";
    EXPECT_EQ(testtime, 9)<< "The testtime is not correct";
    EXPECT_EQ(field[fjposition], 9)<< "The change of field was not correct";
}
TEST (movetractortest, test2){
    int spaceBtwnRevisits = -1;

    {
        pair<int, int> fjposition (0,1);
        movetractor(testtime, field, spaceBtwnRevisits, fjposition);
    }
    {
        pair<int, int> fjposition (0,0);
        movetractor(testtime, field, spaceBtwnRevisits, fjposition);
    }
    EXPECT_EQ(spaceBtwnRevisits , 2)<< "The answer is not correct";
    EXPECT_EQ(testtime, 11)<< "The testtime is not correct";
    {
        pair<int, int> fjposition (0,1);
        EXPECT_EQ(field[fjposition], 10)<< "The change of field was not correct";
    }
    {
        pair<int, int> fjposition (0,0);
        EXPECT_EQ(field[fjposition], 11)<< "The change of field was not correct";
    }
}

TEST(solveTest, test1){
    vector< pair<char, int> > instructions = {{'N',10}, {'S', 10}, {'E', 20}};
    EXPECT_EQ(solve(instructions), 2) << "The answer is not correct";
}
TEST(solveTest, test2){
    vector< pair<char, int> > instructions = {{'N',10}, {'E', 20}};
    EXPECT_EQ(solve(instructions), -1) << "The answer is not correct";
}
TEST(solveTest, test3){
    vector< pair<char, int> > instructions = {{'E',10}, {'N', 2}, {'W', 4}, {'S', 2}};
    EXPECT_EQ(solve(instructions), 12) << "The answer is not correct";
}
TEST(solveTest, test4){
    vector< pair<char, int> > instructions = {{'E',10}, {'N', 2}, {'W', 4}, {'S', 4}};
    EXPECT_EQ(solve(instructions), 12) << "The answer is not correct";
}
TEST(solveTest, test5){
    vector< pair<char, int> > instructions = {{'E',10}, {'N', 2}, {'W', 4}, {'S', 4}, {'E',1},{'N',1},{'W',1}};
    EXPECT_EQ(solve(instructions), 4) << "The answer is not correct";
}
TEST(solveTest, test6){
    vector< pair<char, int> > instructions = {{'E',10}, {'N', 2}, {'W', 10}, {'S', 4}, {'W',1},{'N',2},{'E',3}};
    EXPECT_EQ(solve(instructions), 6) << "The answer is not correct";
}
TEST(solveTest, test7){
    vector< pair<char, int> > instructions = {{'E',10}, {'N', 2}, {'W', 10}, {'S', 4}, {'W',1},{'N',2},{'E',1}};
    EXPECT_EQ(solve(instructions), 6) << "The answer is not correct";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}