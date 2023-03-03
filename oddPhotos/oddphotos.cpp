#include <bits/stdc++.h>
using namespace std;

int solve(int evenIds, int oddIds) {
  // he wants first even second odd
  // so eq num of even odd together ends in odd
  if (evenIds > oddIds) {
    return 2 * (oddIds) + 1;
  } else if (oddIds > evenIds) {
    int leftoverOdds = oddIds - evenIds;

    if (leftoverOdds % 3 == 0) {
      return 2 * (leftoverOdds / 3) + evenIds * 2;
    } else if (leftoverOdds % 3 == 1) {
      return 2 * floor(leftoverOdds / 3) - 1 + evenIds * 2;
    } else if (leftoverOdds % 3 == 2) {
      return 2 * floor(leftoverOdds / 3) + 1 + evenIds * 2;
    }
  } else {  // (evenIds == oddIds)
    return evenIds + oddIds;
  }
  // e+e = e, o+o= e, e+o=o
}

int solve(pair<int, int> args) { return solve(args.first, args.second); }

pair<int, int> testConverter(vector<int> cowIds) {
  pair<int, int> evenOddIds;
  for (int i = 0; i < cowIds.size(); i++) {
    if (cowIds[i] % 2 == 0) {
      evenOddIds.first++;
    } else {
      evenOddIds.second++;
    }
  }
  return evenOddIds;
}
#ifndef TESTING
int main() {
  int n;
  cin >> n;
  int evenIds = 0;
  int oddIds = 0;
  for (int i = 0; i < n; i++) {
    int id;
    cin >> id;
    if (id % 2 == 0) {
      evenIds++;
    } else {
      oddIds++;
    }
  }
  cout << solve(evenIds, oddIds);
}
#endif