#include <bits/stdc++.h>
using namespace std;
#ifndef TESTING
int main() {
  vector<int> cows(3);
  cin >> cows[0] >> cows[1] >> cows[2];
  sort(cows.begin(), cows.end());
  int dist1 = cows[1] - cows[0];
  int dist2 = cows[2] - cows[1];
  int minimum;
  if (cows[0] + 1 == cows[1] && cows[1] + 1 == cows[2]) {
    minimum = 0;
  } else if (2 == min(dist1, dist2)) {
    minimum = 1;
  } else {
    minimum = 2;
  }
    cout << minimum << " " << max(dist1, dist2)-1;
  return 0;
}
#endif