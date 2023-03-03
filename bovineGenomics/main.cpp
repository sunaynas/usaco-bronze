#include <bits/stdc++.h>
using namespace std;

bool dbg = false;

int solve(vector<string> spottyCows, vector<string> plainCows) {
  int ret = 0;
  set<char> sptCwdna;
  set<char> plnCwdna;
  bool goodPos = true;
  for (int i = 0; i < spottyCows[0].size(); i++) {
    // iterating through all positions
    goodPos = true;
    for (int j = 0; j < spottyCows.size(); j++) {
      if (dbg) cout << "looking at pos " << i << " and cow " << j << endl;
      //  iterating through all cows
      if (sptCwdna.size() == 4 || plnCwdna.size() == 4) {
        if (dbg)
          cout << "either spoted or plain cows included all chars" << endl;
        sptCwdna.clear();
        plnCwdna.clear();
        goodPos = false;
        break;
      }
      sptCwdna.insert(spottyCows[i][j]);
      plnCwdna.insert(plainCows[i][j]);
      //   sptCwdna.insert(spottyCows[j][i]);
      //   plnCwdna.insert(plainCows[j][i]);
    }
    // checking for overlaps in set
    if (goodPos) {
      for (auto a : sptCwdna) {
        if (dbg) cout << "looking at a=" << a << endl;
        if (plnCwdna.find(a) != plnCwdna.end()) {
          if (dbg) cout << "there was an overlap of " << a << endl;
          goodPos = false;
          break;
        }
      }
    }
    if (goodPos) {
      if (dbg) cout << "pos " << i << " worked" << endl;
      ret++;
    }
    sptCwdna.clear();
    plnCwdna.clear();
  }
  return ret;
}

#ifndef TESTING
int main() {
  int n, stringLen;
  cin >> n >> stringLen;
  vector<string> plainCows(n);
  vector<string> spottyCows(n);
  string DNA;
  for (int i = 0; i < n; i++) {
    cin >> DNA;
    spottyCows[i] = DNA;
  }
  for (int i = 0; i < n; i++) {
    cin >> DNA;
    plainCows[i] = DNA;
  }
  cout << solve(spottyCows, plainCows) << endl;
  return 0;
}
#endif