#include <bits/stdc++.h>
using namespace std;

void solve(string& cows, int& range, int& grasses, vector<char>& ret) {
  grasses = 0;
  vector<int> Goverlap(cows.size());
  vector<int> Hoverlap(cows.size());

  for (int i = 0; i < cows.size(); i++) {
    if (cows[i] == 'H') {
      Hoverlap[i]++;
      for (int j = 1; j <= range; j++) {
        if (i + j < cows.size()) {
          Hoverlap[i + j]++;
        }
        if (i - j > -1) {
          Hoverlap[i - j]++;
        }
      }
    } else {
      Goverlap[i]++;
      for (int j = 1; j <= range; j++) {
        if (i + j < cows.size()) {
          Goverlap[i + j]++;
        }
        if (i - j > -1) {
          Goverlap[i - j]++;
        }
      }
    }
  }
  // go tr
  int lastGgrass = -1;
  int hmax = 0, hmaxindx = -1;
  int hcow = -1;
  for (int i = 0; i < cows.size(); i++) {
    cout << "i = " << i << ", hcow =" << hcow << ", hmaxindx = " << hmaxindx
         << ", hmax =" << hmax << ", hoverlap i=" << Hoverlap[i]
         << ", cow i=" << cows[i] << endl;

    if (cows[i] == 'H' && (hmaxindx == -1 || hmaxindx + range < i)) {
      hmax = 0;
      hcow = i;
      cout << "finding grass for cow " << hcow << endl;
    }
    if (Hoverlap[i] > hmax) {
      hmax = Hoverlap[i];
      hmaxindx = i;
    }
    if (hcow != -1 && i == hcow + range) {
      cout << "found grass for cow " << hcow << " at " << hmaxindx
           << " val= " << Hoverlap[hmaxindx] << endl;
      grasses++;
      ret[hmaxindx] = 'H';
    }
    cout << "i = " << i << ", hcow =" << hcow << ", hmaxindx = " << hmaxindx
         << ", hmax =" << hmax << ", hoverlap i=" << Hoverlap[i]
         << ", cow i=" << cows[i] << endl;
    // if looking for new cow
    // looking for grass for that cow

    if (cows[i] == 'G' && (lastGgrass != -1 || lastGgrass < i - range)) {
      // find pos to plant grass
      int max = 0, maxindx;
      for (int j = 0; j <= range; j++) {
        // if (i - j >= 0 && Hoverlap[i - j] > max) {
        //   max = Hoverlap[i - j];
        //   maxindx = i - j;
        // }
        if (i + j < Goverlap.size() && Goverlap[i + j] > max) {
          //   max = Goverlap[i + j];
          //   maxindx = i + j;
          if (ret[i + j] == 'H') {
            if (hmax >= Goverlap[i + j]) {
              // skip
            } else if (hmax < Goverlap[i + j]) {
              max = Goverlap[i + j];
              maxindx = i + j;
            }
          } else {
            max = Goverlap[i + j];
            maxindx = i + j;
          }
        }
      }
      lastGgrass = maxindx;
      if (ret[maxindx] == 'H') {
        ret[maxindx - 1] = 'H';
        hmaxindx = maxindx - 1;
        hmax = ret[maxindx - 1];
      }
      ret[maxindx] = 'G';
      grasses++;
    }
  }
  // if they are same
  // for all cows in range of grass, mark as filled
  // and remove them from overlap
  // from -range to pos range everything is 0
}

#ifndef TESTING
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int size, walk;
    string cows;
    cin >> size >> walk >> cows;
    int grass;
    vector<char> ret(cows.size(), '.');
    solve(cows, walk, grass, ret);
    cout << grass << endl;
    for (int i = 0; i < cows.size(); i++) {
      cout << ret[i];
    }
    cout << endl;
  }
  return 0;
}
#endif

// if (cows[i] == 'H' && (lastHgrass != -1 || lastHgrass < i - range)) {
//   // find pos to plant grass
//   int hmax = 0, hmaxindx;
//   for (int j = 0; j <= range; j++) {
//     // if (i - j >= 0 && Hoverlap[i - j] > max) {
//     //   max = Hoverlap[i - j];
//     //   hmaxindx = i - j;
//     // }
//     if (i + j < Hoverlap.size() && Hoverlap[i + j] > hmax) {
//       hmax = Hoverlap[i + j];
//       hmaxindx = i + j;
//     }
//   }
//   lastHgrass = hmaxindx;
//   grasses++;
//   ret[hmaxindx] = 'H';
// }