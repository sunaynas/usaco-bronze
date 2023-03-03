#include <bits/stdc++.h>
using namespace std;

#ifndef TESTING
int main() {
  int rows, columns;
  cin >> rows >> columns;
  vector<string> field(rows);
  for (int i = 0; i < rows; i++) {
    string rw;
    cin >> rw;
    field[i] = rw;
  }
  int usableGs = 0;
  int crossCnts = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      if (field[i][j] == 'G') {
        int neighbors = 0;
        if (i - 1 >= 0 && field[i - 1][j] == 'C') {
          neighbors++;
        }
        if (j - 1 >= 0 && field[i][j - 1] == 'C') {
          neighbors++;
        }
        if (j + 1 < columns && field[i][j + 1] == 'C') {
          neighbors++;
        }
        if (i + 1 < rows && field[i + 1][j] == 'C') {
          neighbors++;
        }
        if (neighbors >= 2) {
          usableGs++;
        }

        if (j + 1 < columns && i + 1 < rows && field[i + 1][j + 1] == 'G' &&
            field[i][j + 1] == 'C' && field[i + 1][j] == 'C') {
          // gc
          // cg
          if ((j - 1 < 0 || field[i][j - 1] != 'C') &&
              (i - 1 < 0 || field[i - 1][j] != 'C') &&
              (j + 2 >= columns || field[i + 1][j + 2] != 'C') &&
              (i + 2 >= rows || field[i + 2][j + 1] != 'C')) {
            // valid cross cont
            crossCnts++;
          }
        }
      } else if (field[i][j] == 'C' && j + 1 < columns && i + 1 < rows &&
                 field[i + 1][j + 1] == 'C' && field[i][j + 1] == 'G' &&
                 field[i + 1][j] == 'G') {
        // cg
        // gc
        if ((j - 1 < 0 || field[i + 1][j - 1] != 'C') &&
            (i - 1 < 0 || field[i - 1][j + 1] != 'C') &&
            (j + 2 >= columns || field[i][j + 2] != 'C') &&
            (i + 2 >= rows || field[i + 2][j] != 'C')) {
          // valid cross cont
          crossCnts++;
        }
      }
    }
  }
  cout << usableGs - crossCnts << endl;
  return 0;
}
#endif