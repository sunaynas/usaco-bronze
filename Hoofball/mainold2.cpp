#include <bits/stdc++.h>
using namespace std;

bool DEBUG = false;
bool DEBUG2 = false;

int findNearest(set<int> &cows, int cow) {
  int neighborSearch = 0;
  while (cow - neighborSearch > -1) {
    neighborSearch++;
    if (cows.find(cow + neighborSearch) != cows.end()) {
      return cow + neighborSearch;
    } else if (cows.find(cow - neighborSearch) != cows.end()) {
      return cow - neighborSearch;
    }
  }
  // error
  return -1;
}

int solve(vector<char> &cows) {
  int answ = 0;
  int i = 0;
  while (i < cows.size()) {
    if (i + 2 < cows.size() && cows[i] == 'r' && cows[i + 1] == 'p' &&
        cows[i + 2] == 'l') {
      if (DEBUG2) cout << "adding 2 to answ, case RPL " << endl;
      answ += 2;
      if (DEBUG2) cout << "size is " << cows.size() << ", i is " << i << endl;
    } else if (i + 1 < cows.size() && cows[i] == 'l' && cows[i + 1] == 'p') {
      if (DEBUG2) cout << "adding 1 to answ, case LP " << endl;
      answ += 1;
    } else if (i + 1 < cows.size() && cows[i] == 'l' && cows[i + 1] == 'r') {
      if (DEBUG2) cout << "adding 1 to answ, case LR " << endl;
      answ += 1;
    } else if (i + 1 < cows.size() && cows[i] == 'p' && cows[i + 1] == 'r') {
      if (DEBUG2) cout << "adding 1 to answ, case PR " << endl;
      answ += 1;
    } else if (i + 1 < cows.size() && cows[i] == 'p' && cows[i + 1] == 'p') {
      // lppr
      answ += 1;
      if (DEBUG2) cout << "adding 1 to answ, case PP " << endl;
    }
    i++;
    // if (DEBUG2) cout << "index is now " << i << endl;
  }
  return answ;
}

#ifndef TESTING
int main() {
  int n;
  cin >> n;
  set<int> cows;
  for (int i = 0; i < n; i++) {
    int cowDist;
    cin >> cowDist;
    cows.insert(cowDist);
  }
  if (DEBUG) {
    cout << "saved input ";
    for (auto a : cows) {
      cout << a << ", ";
    }
    cout << endl;
  }
  vector<char> solveCows;
  int lastPdist;
  for (auto a : cows) {
    char dir;
    int aNearestCow = findNearest(cows, a);
    if (a == findNearest(cows, aNearestCow)) {
      bool nopB4 =
          solveCows.size() > 0 && solveCows[solveCows.size() - 1] != 'p';
      if (nopB4) {
        lastPdist = abs(a - aNearestCow);
        solveCows.push_back('p');
      } else {
        bool distSame = abs(a - aNearestCow) == lastPdist;
        if (!distSame) {
          lastPdist = abs(a - aNearestCow);
          solveCows.push_back('p');
        } else {
          bool lpb4 = solveCows.size() > 2 &&
                      solveCows[solveCows.size() - 1] != 'p' &&
                      solveCows[solveCows.size() - 2] != 'l';
          if (lpb4) {
            lastPdist = abs(a - aNearestCow);
            solveCows.push_back('p');
          }
        }  // dist between pairs and between pairs is same
      }
    } else if (aNearestCow > a && (solveCows.size() == 0 ||
                                   solveCows[solveCows.size() - 1] != 'r')) {
      solveCows.push_back('r');
    } else if (aNearestCow < a && (solveCows.size() == 0 ||
                                   solveCows[solveCows.size() - 1] != 'l')) {
      solveCows.push_back('l');
    }
  }
  if (DEBUG2) {
    cout << "converted to ";
    for (int i = 0; i < solveCows.size(); i++) {
      cout << solveCows[i] << ", ";
    }
    cout << endl;
  }
  cout << solve(solveCows);
  return 0;
}
#endif

// 336, 384, 387, 422, 493, 650, 778, 794, 887, 916
//  r    p----p    l    l    r    p----p    p----p
//             35    71   157  128  16   93    29