#include <bits/stdc++.h>
using namespace std;

bool DEBUG = false;
bool DEBUG2 = false;

int findNearest(set<int> &cows, int cow) {
  int neighborSearch = 0;
  while (true) {  // cow - neighborSearch > -1) {
    neighborSearch++;
    if (cows.find(cow - neighborSearch) != cows.end()) {
      return cow - neighborSearch;
    } else if (cows.find(cow + neighborSearch) != cows.end()) {
      return cow + neighborSearch;
    }
  }
  // error
  return -1;
}

// int solve(vector<char> &cows) {
//   int answ = 0;
//   int i = 0;
//   while (i < cows.size()) {
//     if (i + 2 < cows.size() && cows[i] == 'r' && cows[i + 1] == 'p' &&
//         cows[i + 2] == 'l') {
//       if (DEBUG2) cout << "adding 2 to answ, case RPL " << endl;
//       answ += 2;
//       if (DEBUG2) cout << "size is " << cows.size() << ", i is " << i <<
//       endl;
//     } else if (i + 1 < cows.size() && cows[i] == 'l' && cows[i + 1] == 'p') {
//       if (DEBUG2) cout << "adding 1 to answ, case LP " << endl;
//       answ += 1;
//     } else if (i + 1 < cows.size() && cows[i] == 'l' && cows[i + 1] == 'r') {
//       if (DEBUG2) cout << "adding 1 to answ, case LR " << endl;
//       answ += 1;
//     } else if (i + 1 < cows.size() && cows[i] == 'p' && cows[i + 1] == 'r') {
//       if (DEBUG2) cout << "adding 1 to answ, case PR " << endl;
//       answ += 1;
//     } else if (i + 1 < cows.size() && cows[i] == 'p' && cows[i + 1] == 'p') {
//       // lppr
//       answ += 1;
//       if (DEBUG2) cout << "adding 1 to answ, case PP " << endl;
//     }
//     i++;
//     // if (DEBUG2) cout << "index is now " << i << endl;
//   }
//   return answ;
// }

#ifndef TESTING
int main() {
  int n;
  cin >> n;
  set<int> cows;
  vector<int> cv(n);
  for (int i = 0; i < n; i++) {
    int cowDist;
    cin >> cowDist;
    cv[i] = cowDist;
    cows.insert(cowDist);
  }
  sort(cv.begin(), cv.end());
  if (DEBUG) {
    cout << "saved input ";
    int pcow = 0;
    for (auto a : cows) {
      cout << a << "[" << a - pcow << "], ";
      pcow = a;
    }
    cout << endl;
  }
  vector<char> solveCows;
  string cowDir;
  int lastPdist;
  // for (int i = 0; i < cv.size(); ++i) {
  //   int nd = (i < (cv.size() - 1)) ? (cv[i + 1] - cv[i]) : INT_MAX;
  //   int pd = (i != 0) ? (cv[i] - cv[i - 1]) : INT_MAX;
  //   if (i == 0 || nd < pd) {
  //     solveCows.push_back('r');
  //     cowDir += 'r';
  //   } else if (i == (cv.size() - 1) || nd >= pd) {
  //     solveCows.push_back('l');
  //     cowDir += 'l';
  //   }
  // }
  for (auto a : cows) {
    int aNearestCow = findNearest(cows, a);
    if (aNearestCow > a) {
      solveCows.push_back('r');
      cowDir += 'r';
    } else if (aNearestCow < a) {
      solveCows.push_back('l');
      cowDir += 'l';
    }
  }

  if (DEBUG2) {
    cout << "converted to ";
    for (int i = 0; i < solveCows.size(); i++) {
      cout << solveCows[i] << ", ";
    }
    cout << endl;
  }
  int tcnt = 0;
  // find all 'rl' and count

  for (int i = 0; i < solveCows.size() - 1; i++) {
    if (solveCows[i] == 'r' && solveCows[i + 1] == 'l') {
      tcnt++;
      if (i + 2 < solveCows.size() && i > 0 && solveCows[i + 2] == 'l' &&
          solveCows[i - 1] == 'r') {
        tcnt++;
      }
    }
  }
  cout << tcnt << endl;
  return 0;
}
#endif

// 336, 384, 387, 422, 493, 650, 778, 794, 887, 916
//  r    p----p    l    l    r    p----p    p----p
//             35    71   157  128  16   93    29

/*

5
7 1 3 11 4

*/