#include <bits/stdc++.h>

#include <tuple>

using namespace std;

bool goodTrio(int pos1, int pos2, int pos3, vector<string>& spottyCows,
              vector<string>& plainCows) {
  map<tuple<char, char, char>, bool> cws;
  for (int i = 0; i < spottyCows.size(); i++) {
    cws[make_tuple(spottyCows[i][pos1], spottyCows[i][pos2],
                   spottyCows[i][pos3])] = true;
  }
  for (int i = 0; i < plainCows.size(); i++) {
    if (cws[make_tuple(plainCows[i][pos1], plainCows[i][pos2],
                       plainCows[i][pos3])] == true) {
      // there is overlap
      return false;
    }
  }
  return true;
}

int solve(vector<string>& spottyCows, vector<string>& plainCows) {
  int answ = 0;
  int stringlength = spottyCows[0].size();
  for (int i = 0; i < stringlength - 2; i++) {
    for (int j = i + 1; j < stringlength - 1; j++) {
      for (int k = j + 1; k < stringlength; k++) {
        if (goodTrio(i, j, k, spottyCows, plainCows)) answ++;
      }
    }
  }
  return answ;
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
/*

got so 1 test failed ?
only 1
how to fix?
i think algorithm is correct but there is
some optimization we are missing

let me check
give me 10 min

ill start another hard problem while ur at it
sure go ahead
send me your code
*/