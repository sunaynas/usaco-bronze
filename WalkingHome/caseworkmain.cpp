#include <bits/stdc++.h>
using namespace std;

bool dbg = false;
bool dbgD = false;

int singleTurn(vector<vector<char> > &field) {
  bool rightdown = true;
  bool downright = true;
  for (int i = 0; i < field[0].size(); i++) {
    if (field[0][i] == 'H') {
      rightdown = false;
    }
    if (field[field.size() - 1][i] == 'H') {
      downright = false;
    }
    if (field[i][0] == 'H') {
      downright = false;
    }
    if (field[i][field.size() - 1] == 'H') {
      rightdown = false;
    }
  }

  return rightdown + downright;
}

int doubleTurn(vector<vector<char> > &field) {
  int answ = 0;
  // check which rows are free
  // and if the access to get to that row is free
  for (int i = 1; i < field.size() - 1; i++) {
    // row = field[i][j]
    // column = field[j][i]
    bool freeColumn = true;
    bool freeRow = true;
    if (dbgD) cout << "looking and row and column " << i << endl;
    for (int j = 0; j < field[0].size(); j++) {
      if (field[i][j] == 'H') {
        if (dbgD) cout << "row broken at " << i << ", " << j << endl;
        freeRow = false;
      }
      if (field[j][i] == 'H') {
        if (dbgD) cout << "column broken at " << i << ", " << j << endl;
        freeColumn = false;
      }
      if (!freeColumn && !freeRow) break;
    }
    if (freeColumn) {
      // check if it works
      int a;
      for (a = 0; a < i && a != -1; a++) {
        if (field[0][a] == 'H') {
          if (dbgD)
            cout << "column top leg broken at " << 0 << ", " << a << endl;
          a = -1;
          break;
        }
      }
      int b;
      for (b = i; b < field.size() && b != -1; b++) {
        if (field[field.size() - 1][b] == 'H') {
          if (dbgD)
            cout << "column top leg broken at " << field.size() - 1 << ", " << b
                 << endl;
          b = -1;
          break;
        }
      }
      if (dbgD) cout << "a = " << a << " b= " << b << endl;
      if (a != -1 && b != -1) {
        answ++;
        if (dbgD) cout << "answ = " << answ << endl;
      }
    }
    if (freeRow) {
      // check if works
      // check field[0][0]-> field[i][0] && field[i][size-1] ->
      // field[size-1][size-1]
      int a;
      for (a = 0; a < i && a != -1; a++) {
        if (field[a][0] == 'H') {
          a = -1;
          break;
        }
      }
      int b;
      for (b = i; b < field.size() - 1 && b != -1; b++) {
        if (field[b][field.size() - 1] == 'H') {
          b = -1;
          break;
        }
      }
      if (a != -1 && b != -1) {
        answ++;
      }
    }
  }
  return answ;
}

int tripleTurnChecker(vector<vector<char> > &field, int i, int j) {
  if (dbg)
    cout << "calling triple turn checker with i= " << i << " j=" << j << endl;
  bool rightfirst = true;
  bool downfirst = true;
  // checking path
  // 2 paths:DRDR, RDRD,
  for (int a = 0; a < field.size(); a++) {
    if (!downfirst && !rightfirst) {
      break;
    }
    if (a <= j) {
      if (field[i][a] == 'H') {
        downfirst = false;
      }
      if (field[a][i] == 'H') {
        rightfirst = false;
      }
    }
    if (a >= j) {
      if (field[field.size() - 1][a] == 'H') {
        downfirst = false;
      }
      if (field[a][field.size() - 1] == 'H') {
        rightfirst = false;
      }
    }
    if (a <= i) {
      if (field[a][0] == 'H') {
        downfirst = false;
      }
      if (field[0][a] == 'H') {
        rightfirst = false;
      }
    }
    if (a >= i) {
      if (field[a][j] == 'H') {
        downfirst = false;
      }
      if (field[j][a] == 'H') {
        rightfirst = false;
      }
    }
  }

  return rightfirst + downfirst;
}

int tripleTurn(vector<vector<char> > &field) {
  if (dbg) cout << "calling triple turn" << endl;
  int answ = 0;
  // field size can be 2
  for (int i = 1; i < field.size() - 1; i++) {
    for (int j = 1; j < field.size() - 1; j++) {
      // picked first point
      answ += tripleTurnChecker(field, i, j);
      if (dbg) cout << "answ= " << answ << endl;
    }
  }
  return answ;
}

int solve(vector<vector<char> > &field, int param) {
  int answ = 0;
  answ += singleTurn(field);
  if (dbg) cout << " Single Turn" << endl;
  if (param > 1) {
    answ += doubleTurn(field);
    if (dbg) cout << " Double Turn" << endl;
  }
  if (param == 3) {
    answ += tripleTurn(field);
    if (dbg) cout << " Triple Turn" << endl;
  }
  return answ;
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
    cout << solve(field, param) << endl;
  }
  return 0;
}
#endif
