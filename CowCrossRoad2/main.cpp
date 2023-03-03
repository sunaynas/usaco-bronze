#include <bits/stdc++.h>
using namespace std;

// finds total number of crossing pairs
int solve(string order) {
  cout << " Running Solve" << endl;
  int totalCrossingPairs = 0;
  for (int i = 0; i < 52 - 1; i++) {
    // order[i]
    map<char, int> countCrosses;
    int j = i + 1;
    for (; order[i] != order[j] && j < 52; j++) {
      countCrosses[order[j]]++;
    }
    bool secondOccurence = (j == 52 && order[i] != order[j]);
    if (!secondOccurence) {
      for (auto it : countCrosses) {
        if (it.second == 1) {
          totalCrossingPairs++;
        }
      }
    }
  }
  return totalCrossingPairs / 2;
}

#ifndef TESTING
int main() {
  string order;
  cin >> order;
  cout << solve(order);
  return 0;
}
#endif