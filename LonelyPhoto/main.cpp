#include <bits/stdc++.h>
using namespace std;
string cows;
vector<int> cowVec;
bool D = false;

void lonelyCow(int start, int end, long long& thrownPics, int& gcnt,
               int& hcnt) {
  if (start + end > cows.size()) {
    return;
  }
  if (gcnt == 0 && hcnt == 0) {
    for (int i = start; i < start + end; i++) {
      if (cows[i] == 'G') {
        gcnt++;
      } else if (cows[i] == 'H') {
        hcnt++;
      }
    }
  } else {
    gcnt += cows[start + end - 1] == 'G';
    hcnt += cows[start + end - 1] == 'H';
  }
  if (gcnt < 2 || hcnt < 2) {
    if ((cows[start + end - 1] == 'H' && hcnt == 1 && gcnt != 1) ||
        (cows[start + end - 1] == 'G' && gcnt == 1 && hcnt != 1)) {
      thrownPics++;
    } else if (gcnt == 1 || hcnt == 1) {
      thrownPics += cowVec[start + end - 1];
    }

    if (cows[start + end - 1] == 'H') {
      hcnt += cowVec[start + end - 1] - 1;
    } else {
      gcnt += cowVec[start + end - 1] - 1;
    }
    return lonelyCow(start, end + cowVec[start + end - 1], thrownPics, gcnt,
                     hcnt);
  } else {
    return;
  }
}

#ifndef TESTING
int main() {
  int n;
  cin >> n;

  cin >> cows;

  cowVec.resize(cows.size());

  cowVec[cows.size() - 1] = 1;
  for (int i = cows.size() - 2; i >= 0; --i) {
    if (cows[i] != cows[i + 1]) {
      cowVec[i] = 1;
    } else {
      cowVec[i] = cowVec[i + 1] + 1;
    }
  }
  if (D) {
    cout << cows << endl;
    for (int v : cowVec) {
      cout << v;
    }
    cout << endl;
  }
  long long thrownPhotos = 0;
  for (int i = 0; i < cows.size() - 2; i++) {
    long long thrownPics = 0;
    int gcnt = 0, hcnt = 0;
    lonelyCow(i, 3, thrownPics, gcnt, hcnt);
    thrownPhotos += thrownPics;
  }
  cout << thrownPhotos << endl;
  return 0;
}
#endif
/*
HHHBHHBB
32112121
*/