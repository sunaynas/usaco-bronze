#include <bits/stdc++.h>
using namespace std;

// 1 is right, 0 is down
int solve(vector<vector<char> >& field, int i, int j, int param, bool dir,
          int& answ) {
  // cout << "solve called with i=" << i << " j=" << j << " param= " << param
  //<< " and dir =" << dir << endl;
  if (field[i][j] == 'H') return 0;
  if (i == field.size() - 1 && j == field.size() - 1) {
    // cout << "\tMade it home" << endl;
    return 1;
  }
  if (dir) {
    if (j < field.size() - 1) {
      answ += solve(field, i, j + 1, param, true, answ);
    }
    if (i < field.size() - 1 && param > 0) {
      answ += solve(field, i + 1, j, param - 1, false, answ);
    }
  }
  if (!dir) {
    if (j < field.size() - 1 && param > 0) {
      answ += solve(field, i, j + 1, param - 1, true, answ);
    }
    if (i < field.size() - 1) {
      answ += solve(field, i + 1, j, param, false, answ);
    }
  }
  return 0;
}
#ifndef TESTING
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int gridsize, param;
    char hay;
    cin >> gridsize >> param;
    vector<vector<char> > field(gridsize);
    for (int a = 0; a < gridsize; a++) {
      field[a].resize(gridsize);
      string st;
      cin >> st;
      for (int b = 0; b < gridsize; b++) {
        field[a][b] = st[b];
      }
    }
    int answ = 0;
    solve(field, 0, 1, param, true, answ);
    solve(field, 1, 0, param, false, answ);
    cout << answ << endl;
  }
  return 0;
}
#endif