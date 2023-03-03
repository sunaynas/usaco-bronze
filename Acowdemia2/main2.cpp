#include <bits/stdc++.h>
using namespace std;

bool dbg = false;

#ifndef TESTING
int main() {
  int n, k;
  cin >> k >> n;
  map<string, int> names;
  map<int, string> strname;
  vector<vector<int>> ret(n);
  for (int i = 0; i < n; i++) {
    ret[i].resize(n);
    fill(ret[i].begin(), ret[i].end(), -2);
    string name;
    cin >> name;
    names[name] = i;
    strname[i] = name;
  }
  for (int i = 0; i < k; i++) {
    // for all papers
    string previnstr = "";

    if (dbg) cout << "NEW PAPER" << endl;
    for (int j = 0; j < n; j++) {
      // for each person
      string name;
      cin >> name;
      if (previnstr != "") {
        if (dbg)
          cout << "looking at prev cow " << previnstr << " and current cow "
               << name << endl;
        int prev = names[previnstr];
        int current = names[name];
        if (previnstr > name) {
          if (dbg) cout << "previous cow is younger than current " << endl;
          // previous is younger than oldest
          if (dbg)
            cout << "numeric val of prev cow is " << names[previnstr]
                 << " current cow is " << current << endl;
          ret[prev][current] = 0;
          ret[current][prev] = 1;
          for (int a = 0; a < n; a++) {
            if (dbg)
              cout << "at a= " << a << " ret[prev][a] = " << ret[prev][a]
                   << " ret[current][a] = " << ret[current][a] << endl;
            if (a != prev && a != current) {
              if (ret[prev][a] == 1) {
                ret[current][a] = 1;
                ret[a][current] = 0;
              } else if (ret[prev][a] == -1 && strname[a] > strname[current]) {
                ret[current][a] = 1;
                ret[a][current] = 0;
              }
              if (ret[current][a] == 0) {
                ret[prev][a] = 1;
                ret[a][prev] = 0;
              }
            }
            if (dbg)
              cout << "now a= " << a << " ret[prev][a] = " << ret[prev][a]
                   << " ret[current][a] = " << ret[current][a] << endl;
          }
          // have to
        } else if (previnstr != "") {
          if (dbg)
            cout << "setting relationship between " << previnstr << " and "
                 << name << " to -1" << endl;
          if (ret[prev][current] == -2) {
            ret[prev][current] = -1;
          }
          if (ret[current][prev] == -2) {
            ret[current][prev] = -1;
          }

          if (ret[current][prev] == 0 && ret[prev][current] == 1) {
            for (int a = 0; a < n; a++) {
              if (a != prev && a != current) {
                if (ret[prev][a] == 1) {
                  ret[current][a] = 1;
                  ret[a][current] = 0;
                }
                if (ret[current][a] == 0) {
                  ret[prev][a] = 0;
                  ret[a][prev] = 1;
                }
              }
            }
          }
        }
      }
      previnstr = name;
    }
  }
  // printing results
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        cout << 'B';
      } else if (ret[i][j] == -1) {
        cout << '?';
      } else {
        cout << ret[i][j];
      }
    }
    cout << endl;
  }
  return 0;
}
#endif