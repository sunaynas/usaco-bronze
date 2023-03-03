#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int> > instructions) {
  set<pair<int, int> > pairs;
  for (int i = 0; i < instructions[0].size() - 1; i++) {
    for (int j = i + 1; j < instructions[0].size(); j++) {
      //   cout << "making pair with greater one " << instructions[0][i]
      //        << " and smaller one " << instructions[0][j] << endl;
      pairs.insert(make_pair(instructions[0][i], instructions[0][j]));
    }
  }
  for (int a = 1; a < instructions.size(); a++) {
    // check if order is off
    for (int i = 0; i < instructions[0].size() - 1; i++) {
      for (int j = i + 1; j < instructions[0].size(); j++) {
        // finding
        auto it = pairs.find(make_pair(instructions[a][i], instructions[a][j]));
        // cout << "looking for pair " << instructions[a][i] << ", "
        //      << instructions[a][j] << endl;

        if (it == pairs.end()) {
          // cout << "found pair 4,1" << endl;
          auto it2 =
              pairs.find(make_pair(instructions[a][j], instructions[a][i]));
          if (it2 != pairs.end()) {
            // cout << "pair " << instructions[a][j] << ", " <<
            // instructions[a][i]
            //      << " erased" << endl;
            pairs.erase(it2);
          }
        } else {
          //   cout << "pair " << instructions[a][i] << ", " <<
          //   instructions[a][j]
          //        << " passed" << endl;
        }
      }
    }
  }
  return pairs.size();
}

#ifndef TESTING
int main() {
  int n, k;
  cin >> k >> n;
  // the first one in the pair is the greater one
  vector<vector<int> > instructions(k);
  int ranking;
  for (int i = 0; i < k; i++) {
    instructions[i].resize(n);
    for (int j = 0; j < n; j++) {
      cin >> ranking;
      instructions[i][j] = ranking;
    }
  }

  cout << solve(instructions) << endl;
  return 0;
}
#endif