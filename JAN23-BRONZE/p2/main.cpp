#include <bits/stdc++.h>
using namespace std;
const bool dbg = false;
void solve() {}
#ifndef TESTING
int main() {
  int n;
  // if (dbg) cout << "Starting..." << endl;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    if (str.size() < 3) {
      cout << -1 << endl;
    } else {
      if (dbg) cout << "size is greater than 3" << endl;
      if (str.find("MOO") != string::npos) {
        if (dbg) cout << "found moo" << endl;
        cout << str.size() - 3 << endl;
      } else if (str.find("MOM") != string::npos ||
                 str.find("OOO") != string::npos) {
        if (dbg) cout << "found mom or ooo" << endl;
        cout << str.size() - 3 + 1 << endl;
      } else if (str.find("OOM") != string::npos) {
        if (dbg) cout << "found mom or oom" << endl;
        cout << str.size() - 3 + 2 << endl;
      } else {
        if (dbg) cout << "found nothing" << endl;
        cout << -1 << endl;
      }
    }
  }
  return 0;
}
#endif
