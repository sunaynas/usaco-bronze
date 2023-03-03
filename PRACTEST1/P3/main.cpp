#include <bits/stdc++.h>
using namespace std;

// if you have multiple maxes
// solve the closeset one and then the next max will b max
// if you have 2 same digits
// keep looking until one is different
int solve(vector<int> cows) {
  long long corn = 0;
  auto it = max_element(cows.begin(), cows.end());
  auto before = next(it, 1);
  auto after = prev(it, 1);
  if (cows[*before] > cows[*after]) {
  }
}

#ifndef TESTING
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int numOfCows;
    cin >> numOfCows;
    vector<int> cows(numOfCows);
    for (int j = 0; j < numOfCows; j++) {
      int cow;
      cin >> cow;
      cows[j] = cow;
    }
    cout << solve(cows);
  }
  return 0;
}
#endif