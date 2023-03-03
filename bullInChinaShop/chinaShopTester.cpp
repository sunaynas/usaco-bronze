#include <gtest/gtest.h>
// clang++ -std=c++17  testFileName.cpp -lgtest -lgtest_main -pthread -o
// testername
#include <iostream>
#define TESTING
#include "bullinChinaShop.cpp"

//bool compareShape(vector<vector<char>> a, vector<vector<char>> b) {
//
//}


TEST(cropTest, test1) {
  vector<vector<char> > obj = {{'.', '.', '.', '.'},
                               {'.', '#', '#', '.'},
                               {'.', '#', '#', '.'},
                               {'.', '.', '.', '.'}};
  vector<vector<char> > croppedObj = {{'#', '#'}, {'#', '#'}};
  auto answ = crop(obj);

  EXPECT_EQ(answ.size(), croppedObj.size());
  // EXPECT_EQ(compareShape(answ, croppedObj), true);
  for (int i = 0; i < croppedObj.size(); ++i) {
    EXPECT_EQ(answ[i].size(), croppedObj[i].size());

    for (int j = 0; j < croppedObj[i].size(); j++) {
      EXPECT_EQ(croppedObj[i][j], answ[i][j]);
    }
  }
}
TEST(cropTest, test2) {
  vector<vector<char> > obj = {{'.', '.', '.', '.'},
                               {'.', '#', '.', '.'},
                               {'.', '.', '#', '.'},
                               {'.', '.', '.', '.'}};
  vector<vector<char> > croppedObj = {{'#', '.'}, {'.', '#'}};

  auto answ = crop(obj);

  EXPECT_EQ(answ.size(), croppedObj.size());

  for (int i = 0; i < croppedObj.size(); ++i) {
    EXPECT_EQ(answ[i].size(), croppedObj[i].size());

    for (int j = 0; j < croppedObj[i].size(); j++) {
      EXPECT_EQ(croppedObj[i][j], answ[i][j]);
    }
  }
}
TEST(cropTest, test3) {
  vector<vector<char> > obj = {{'.', '.', '.', '.'},
                               {'.', '#', '.', '.'},
                               {'.', '.', '.', '.'},
                               {'.', '.', '.', '.'}};
  vector<vector<char> > croppedObj = {{'#'}};

  auto answ = crop(obj);

  EXPECT_EQ(answ.size(), croppedObj.size());

  for (int i = 0; i < croppedObj.size(); ++i) {
    EXPECT_EQ(answ[i].size(), croppedObj[i].size());

    for (int j = 0; j < croppedObj[i].size(); j++) {
      EXPECT_EQ(croppedObj[i][j], answ[i][j]);
    }
  }
}
TEST(cropTest, cuttofftopbottom) {
  vector<vector<char> > obj = {{'.', '.', '.', '.', '.'},
                               {'#', '.', '.', '.', '.'},
                               {'.', '.', '.', '#', '.'},
                               {'.', '#', '.', '.', '#'},
                               {'.', '.', '.', '.', '.'}};
  vector<vector<char> > croppedObj = {
      {'#', '.', '.', '.', '.'},
      {'.', '.', '.', '#', '.'},
      {'.', '#', '.', '.', '#'},
  };

  auto answ = crop(obj);

  EXPECT_EQ(answ.size(), croppedObj.size());

  for (int i = 0; i < croppedObj.size(); ++i) {
    EXPECT_EQ(answ[i].size(), croppedObj[i].size());

    for (int j = 0; j < croppedObj[i].size(); j++) {
      EXPECT_EQ(croppedObj[i][j], answ[i][j]);
    }
  }
}
TEST(cropTest, test5) {
  vector<vector<char> > obj = {{'#', '.', '.', '.'},
                               {'.', '.', '.', '.'},
                               {'.', '.', '.', '.'},
                               {'.', '.', '.', '#'}};
  vector<vector<char> > croppedObj = {{'#', '.', '.', '.'},
                                      {'.', '.', '.', '.'},
                                      {'.', '.', '.', '.'},
                                      {'.', '.', '.', '#'}};

  auto answ = crop(obj);

  EXPECT_EQ(answ.size(), croppedObj.size());

  for (int i = 0; i < croppedObj.size(); ++i) {
    EXPECT_EQ(answ[i].size(), croppedObj[i].size());

    for (int j = 0; j < croppedObj[i].size(); j++) {
      EXPECT_EQ(croppedObj[i][j], answ[i][j]);
    }
  }
}
TEST(cropTest, cuttOffSides) {
  vector<vector<char> > obj = {{'.', '.', '#', '.'},
                               {'.', '.', '.', '.'},
                               {'.', '.', '.', '.'},
                               {'.', '#', '.', '.'}};
  vector<vector<char> > croppedObj = {
      {'.', '#'}, {'.', '.'}, {'.', '.'}, {'#', '.'}};

  auto answ = crop(obj);

  EXPECT_EQ(answ.size(), croppedObj.size());

  for (int i = 0; i < croppedObj.size(); ++i) {
    EXPECT_EQ(answ[i].size(), croppedObj[i].size());

    for (int j = 0; j < croppedObj[i].size(); j++) {
      EXPECT_EQ(croppedObj[i][j], answ[i][j]);
    }
  }
}

TEST(pieceOverlapTest, test1) {
  vector<vector<char> > og = {{'#', '.', '#', '.'},
                              {'.', '.', '.', '#'},
                              {'.', '.', '.', '.'},
                              {'#', '#', '.', '.'}};
  vector<vector<char> > piece = {{'.'}, {'#'}};
  vector<pair<int, int> > expectedOverlaps = {{0, 3}, {2, 0}, {2, 1}};
  auto answ = pieceOverlap(og, piece);

  EXPECT_EQ(answ.size(), expectedOverlaps.size());

  for (int i = 0; i < expectedOverlaps.size(); ++i) {
    EXPECT_EQ(answ[i].first, expectedOverlaps[i].first);
    EXPECT_EQ(answ[i].second, expectedOverlaps[i].second);
  }
}
TEST(pieceOverlapTest, test2) {
  vector<vector<char> > og = {{'#', '.', '#', '.'},
                              {'.', '.', '.', '#'},
                              {'.', '.', '.', '.'},
                              {'#', '#', '.', '.'}};
  vector<vector<char> > piece = {
      {'.', '#'}, {'.', '.'}, {'.', '.'}, {'#', '.'}};
  vector<pair<int, int> > expectedOverlaps = {{0, 1}};
  auto answ = pieceOverlap(og, piece);

  EXPECT_EQ(answ.size(), expectedOverlaps.size());

  for (int i = 0; i < expectedOverlaps.size(); ++i) {
    EXPECT_EQ(answ[i].first, expectedOverlaps[i].first);
    EXPECT_EQ(answ[i].second, expectedOverlaps[i].second);
  }
}

TEST(originalOverlapTester, test1) {
  vector<vector<char> > og = {{'#', '.', '#', '.'},
                              {'.', '.', '.', '#'},
                              {'.', '.', '.', '.'},
                              {'#', '#', '.', '.'}};
  vector<vector<char> > pieceA = {{'#', '.', '#', '.'}, {'.', '.', '.', '#'}};
  vector<vector<char> > pieceB = {{'.', '.', '.', '.'}, {'#', '#', '.', '.'}};
  pair<int, int> posA = {0, 0};
  pair<int, int> posB = {2, 0};
  EXPECT_EQ(originalCovered(og, pieceA, pieceB, posA, posB), true);
}
TEST(originalOverlapTester, notCovered) {
  vector<vector<char> > og = {{'#', '.', '#', '.'},
                              {'.', '.', '.', '#'},
                              {'.', '.', '.', '.'},
                              {'#', '#', '.', '.'}};
  vector<vector<char> > pieceA = {{'#', '.', '.', '.'}, {'.', '.', '.', '#'}};
  vector<vector<char> > pieceB = {{'.', '.', '.', '.'}, {'#', '#', '.', '.'}};
  pair<int, int> posA = {0, 0};
  pair<int, int> posB = {2, 0};
  EXPECT_EQ(originalCovered(og, pieceA, pieceB, posA, posB), false);
}

TEST(originalOverlapTester, piecesCollide) {
  vector<vector<char> > og = {{'#', '.', '#', '.'},
                              {'.', '.', '.', '#'},
                              {'.', '.', '.', '.'},
                              {'#', '#', '.', '.'}};
  vector<vector<char> > pieceA = {{'#', '.', '.', '.'}, {'.', '.', '.', '#'}};
  vector<vector<char> > pieceB = {{'.', '.', '.', '#'}, {'#', '#', '.', '.'}};
  pair<int, int> posA = {0, 0};
  pair<int, int> posB = {1, 0};
  EXPECT_EQ(originalCovered(og, pieceA, pieceB, posA, posB), false);
}

TEST(wholeProg, test1) {
  vector<vector<char> > og = {{'.', '.', '.', '.', '.', '.', '.', '.'},
                              {'.', '.', '.', '.', '.', '.', '#', '.'},
                              {'.', '.', '#', '#', '.', '#', '#', '.'},
                              {'.', '#', '.', '.', '#', '.', '#', '.'},
                              {'.', '#', '.', '.', '#', '.', '#', '.'},
                              {'.', '.', '#', '#', '.', '#', '#', '.'},
                              {'.', '.', '.', '.', '.', '.', '#', '.'},
                              {'.', '.', '.', '.', '.', '.', '.', '.'}};
  vector<vector<vector<char> > > pieces{
      {{'.', '.', '.', '.', '.', '.', '.', '.'},
       {'.', '.', '.', '.', '.', '.', '#', '.'},
       {'.', '.', '#', '#', '.', '#', '#', '.'},
       {'.', '#', '.', '.', '#', '.', '#', '.'},
       {'.', '#', '.', '.', '#', '.', '#', '.'},
       {'.', '.', '#', '#', '.', '#', '#', '.'},
       {'.', '.', '.', '.', '.', '.', '#', '.'},
       {'.', '.', '.', '.', '.', '.', '.', '#'}},
      {{'.', '.', '.', '.', '.', '.', '.', '.'},
       {'.', '.', '.', '.', '.', '.', '.', '.'},
       {'.', '.', '.', '.', '.', '.', '.', '.'},
       {'.', '.', '.', '.', '.', '.', '.', '.'},
       {'.', '.', '.', '.', '.', '.', '.', '.'},
       {'.', '.', '.', '#', '.', '.', '.', '.'},
       {'.', '.', '.', '.', '.', '.', '.', '.'},
       {'.', '.', '.', '.', '.', '.', '.', '.'}},
      {{'.', '.', '.', '.', '.', '.', '.', '.'},
       {'.', '.', '.', '.', '.', '.', '.', '.'},
       {'.', '.', '#', '#', '.', '.', '.', '.'},
       {'.', '#', '.', '.', '#', '.', '.', '.'},
       {'.', '#', '.', '.', '#', '.', '.', '.'},
       {'.', '.', '#', '#', '.', '.', '.', '.'},
       {'.', '.', '.', '.', '.', '.', '.', '.'},
       {'.', '.', '.', '.', '.', '.', '.', '.'}},
      {{'.', '.', '.', '.', '.', '.', '.', '.'},
       {'.', '.', '.', '.', '.', '.', '#', '.'},
       {'.', '.', '.', '.', '.', '#', '#', '.'},
       {'.', '.', '.', '.', '.', '.', '#', '.'},
       {'.', '.', '.', '.', '.', '.', '#', '.'},
       {'.', '.', '.', '.', '.', '#', '#', '.'},
       {'.', '.', '.', '.', '.', '.', '#', '.'},
       {'.', '.', '.', '.', '.', '.', '.', '.'}}};
  pair<int, int> expectedAnsw = {3, 4};
  pair<int, int> answ = solve(og, pieces);
  EXPECT_EQ(expectedAnsw.first, answ.first);
  EXPECT_EQ(expectedAnsw.second, answ.second);
}
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}