#include <bits/stdc++.h>
using namespace std;
const bool dbg = false;
int main() {
  int n;
  // if (dbg) cout << "Starting..." << endl;
  cin >> n;
  int lastH = -1;
  int lastG = -1;
  int firstH = -1;
  int firstG = -1;
  int gCntb4H1 = 0;
  int hCntb4G1 = 0;
  string cows;
  vector<int> lists(n);
  int listlen;
  cin >> cows;
  for (int i = 0; i < n; i++) {
    cin >> listlen;
    lists[i] = listlen;
    if (cows[i] == 'H') {
      lastH = max(i, lastH);
    } else if (cows[i] == 'G') {
      lastG = max(i, lastG);
    }

    if (cows[i] == 'H' && firstH == -1) {
      firstH = i;
    } else if (cows[i] == 'G' && firstG == -1) {
      firstG = i;
    }
  }
  if (dbg) cout << "last h at " << lastH << ", last g at " << lastG << endl;
  if (dbg) cout << "first h at " << firstH << ", first g at " << firstG << endl;

  for (int i = 0; i < firstH || i < firstG; i++) {
    if (dbg)
      cout << "looking at cow " << i << " which is " << cows[i]
           << " and has list ending at " << lists[i] - 1 << endl;
    if (cows[i] == 'G' && i < firstH) {
      if (lists[i] - 1 >= firstH) gCntb4H1++;
    } else if (cows[i] == 'H' && i < firstG) {
      if (lists[i] - 1 >= firstG) hCntb4G1++;
    }
  }

  if (dbg)
    cout << "h's with g leader in list at " << hCntb4G1
         << ", g's with h leader in list at " << gCntb4H1 << endl;

  int paircnt = 0;
  bool hlead = false;
  bool glead = false;
  if (lists[firstG] - 1 >= lastG) {
    paircnt += hCntb4G1;
    glead = true;
  }

  if (lists[firstH] - 1 >= lastH) {
    paircnt += gCntb4H1;
    hlead = true;
  }
  if (hlead && glead) {
    paircnt++;
  }
  cout << paircnt << endl;
  return 0;
}
