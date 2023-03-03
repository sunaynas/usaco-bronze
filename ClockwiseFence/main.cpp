#include <bits/stdc++.h>
using namespace std;

string solve(string fence) {
  int maxOffset = 0, maxOffsetIndx = -1;
  int xoffset = 0;
  for (int i = 0; i < fence.size(); i++) {
    if (fence[i] == 'E') {
      xoffset++;
    } else if (fence[i] == 'W') {
      xoffset--;
    }
    if (abs(xoffset) > abs(maxOffset)) {
      maxOffset = xoffset;
      maxOffsetIndx = i;
    }
  }
  //   cout << "reached max x offset at " << maxOffsetIndx << " with offset of "
  //        << maxOffset << endl;
  for (int i = maxOffsetIndx;; i++) {
    if (fence[i] == 'N') {
      if (maxOffset > 0) {
        return "CCW";
      } else if (maxOffset < 0) {
        return "CW";
      }
    } else if (fence[i] == 'S') {
      if (maxOffset > 0) {
        return "CW";
      } else if (maxOffset < 0) {
        return "CCW";
      }
    }
  }
  // something wrong
  return "ERROR";
}

#ifndef TESTING
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string fence;
    cin >> fence;
    cout << solve(fence) << endl;
  }
  return 0;
}
#endif