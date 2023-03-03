#include <bits/stdc++.h>
using namespace std;

bool dbg = false;

#ifndef TESTING
int main() {
  int n, l;
  cin >> n >> l;
  vector<int> papers(n);
  for (int i = 0; i < n; i++) {
    int paper;
    cin >> paper;
    papers[i] = paper;
  }
  sort(papers.begin(), papers.end());
  if (dbg) {
    int ck = papers.size() - 1;
    for (auto p : papers) {
      cout << "[" << ck-- << "]" << p << " ";
    }
    cout << endl;
  }
  int h, hinx = 0;
  if (dbg) cout << "finding h without l " << endl;
  for (int i = 0; i < n; i++) {
    if (dbg) cout << "i = " << i << endl;
    if (dbg) cout << "h = " << n - i << " this paper is " << papers[i] << endl;
    h = n - i;
    if (papers[i] >= h) {
      if (dbg) cout << "found highest h at = " << h << " index " << i << endl;
      hinx = i;
      break;
    }
  }

  // now try to increase h
  // all items > hinx must be increased to h+1
  if (l == 0 || hinx == 0) {
    cout << h << endl;
    return 0;
  }
  for (int i = hinx; i < n; i++) {
    if (papers[i] == h) {
      if (l == 0) {
        cout << h << endl;
        return 0;
      }
      l--;
      papers[i]++;
    }
  }
  if (papers[hinx - 1] == h && l > 0) {
    cout << h + 1 << endl;
  } else
    cout << h << endl;
  return 0;

  /*if (dbg) cout << "finding h with l hindx=" << hinx << " h = " << h << endl;
if (papers[hinx] == h && l > 1 && hinx > 0 && papers[hinx - 1] >= h) {
  cout << h << endl;
} else if (papers[hinx] > h && l > 0 && hinx > 0 && papers[hinx - 1] >= h) {
  cout << h + 1 << endl;
} else {
  cout << h << endl;
}
return 0;
*/
  //   for (int i = 0; i < n; i++) {
  //     if (i < hinx && i >= hinx - l) {
  //       papers[i]++;
  //       if (dbg)
  //         cout << "adding one to paper " << i << " which is now " <<
  //         papers[i]
  //              << endl;
  //     }
  //     h = n - i;
  //     if (papers[i] >= h) {
  //       hinx = i;
  //       break;
  //     }
  //   }
  //   cout << h << endl;
  //   return 0;
}
#endif