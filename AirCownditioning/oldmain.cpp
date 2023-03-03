#include <bits/stdc++.h>
using namespace std;

int work = 0;
bool DEBUG = true;
// there can be up to 100,000 cows
// to deal with issue of big temperatures we can subtract all nums
//  at same time with itr

// possibly make one var for net change in same range
void solve(map<int, int>& temps, map<int, int>& desiredTemps, int& commonDiff) {
  if (temps.size() == 0) {
    return;
  }
  if (DEBUG) {
    cout << "solving with temp = ";
    for (auto it : temps) {
      cout << it.second + commonDiff << " ";
    }
    cout << " and desired temps = ";
    for (auto itr : desiredTemps) {
      cout << itr.second << " ";
    }
    cout << " and common diff " << commonDiff << endl;
  }

  auto beginItr = temps.begin();
  auto endItr = temps.end();
  // cout << "itr successfully created" << endl;
  //  int firstCow = beginItr->first;
  //  int lastCow = endItr->first;
  bool correctFirst =
      (temps[beginItr->first] + commonDiff == desiredTemps[beginItr->first]);
  bool correctLast = (temps[prev(endItr)->first] + commonDiff ==
                      desiredTemps[prev(endItr)->first]);
  if (correctLast || correctFirst) {
    if (correctLast) {
      cout << "last item is correct" << endl;
      temps.erase(prev(endItr)->first);
      desiredTemps.erase(prev(endItr)->first);
      cout << "erased successfully " << endl;
    }
    if (correctFirst) {
      cout << "first item is correct" << endl;
      temps.erase(beginItr->first);
      desiredTemps.erase(beginItr->first);
      cout << "erased successfully " << endl;
    }
  } else {
    //  work to fix first is=  desiredTemps[beginItr->first] -
    //  temps[beginItr->first];

    int tempChange = desiredTemps[beginItr->first] -
                     (temps[beginItr->first] + commonDiff);  // to fix first
    // changing vals for first and last
    // amount of work to change all those vals is workfor1 * size()
    work += abs(tempChange) * temps.size();
    commonDiff += tempChange;
    cout << "adding " << tempChange << " to all temps" << endl;
    temps.erase(beginItr->first);
    desiredTemps.erase(beginItr->first);
  }
  solve(temps, desiredTemps, commonDiff);
}
#ifndef TESTING
int main() {
  int n;
  cin >> n;
  map<int, int> temps;
  map<int, int> desiredTemps;
  int temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    desiredTemps[i] = temp;
  }
  for (int i = 0; i < n; i++) {
    cin >> temp;
    temps[i] = temp;
  }
  int commonDiff = 0;
  solve(temps, desiredTemps, commonDiff);
  cout << work << endl;
  return 0;
}
#endif