#include <bits/stdc++.h>

using namespace std;

bool findOverlap(pair<char, int> cow1, pair<char, int> cow2) {
  char cow1dir = cow1.first;
  int cow1num = cow1.second;
  auto cow2dir = cow2.first;
  auto cow2num = cow2.second;

  if (cow1dir == 'G') {
    bool oppOverlap = (cow1num <= cow2num && cow2dir == 'L');
    bool sameOverlap = (cow1num >= cow2num && cow2dir == 'G');
    if (oppOverlap || sameOverlap) {
      return true;
    }
  } else if (cow1dir == 'L') {
    bool oppOverlap = (cow1num >= cow2num && cow2dir == 'G');
    bool sameOverlap = (cow1num <= cow2num && cow2dir == 'L');
    if (oppOverlap || sameOverlap) {
      return true;
    }
  }

  return false;
}

int solve(vector<pair<char, int>> &instructions) {
  vector<int> overlap(instructions.size(), 0);
  int maxOverlap = 0;

  for (int i = 0; i < instructions.size(); i++) {
    for (int j = 0; j < instructions.size(); j++) {
      if (findOverlap(instructions[i], instructions[j])) {
        // cout << "cow " << instructions[i].first << " "
        // <<instructions[i].second << " overlaps with cow " <<
        // instructions[j].first << " "  <<instructions[j].second << endl;
        overlap[i]++;
      }
    }
    // cout << "changing maxOverlap from " << maxOverlap << " to " <<
    // max(maxOverlap, overlap[i]) << endl;
    maxOverlap = max(maxOverlap, overlap[i]);
  }
  return instructions.size() - maxOverlap;
}

#ifndef TESTING
int main() {
  int n;
  cin >> n;
  vector<pair<char, int>> instructions(n);

  // parse instructions
  for (int i = 0; i < n; i++) {
    char c;
    int d;
    cin >> c >> d;
    // adds instructions to vector of instructions
    instructions[i] = make_pair(c, d);
  }
  cout << solve(instructions);
  return 0;
}
#endif