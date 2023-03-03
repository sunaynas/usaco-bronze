#include <bits/stdc++.h>
using namespace std;

#ifndef TESTING
int main() {
  int n;
  cin >> n;
  vector<long long> cows(n);
  long long cow;
  for (int i = 0; i < n; i++) {
    cin >> cow;
    cows[i] = cow;
  }
  long long maxProfit = 0;
  int price = 0;
  sort(cows.begin(), cows.end());
  for (int i = 0; i < n; i++) {
    // cout << "looking at cow " << (i + 1) << " which will pay " << cows[i]
    //    << endl;
    // profit we are looking at =
    // cows[i] *i
    if (cows[i] * (n - i) > maxProfit) {
      maxProfit = cows[i] * (n - i);
      price = cows[i];
    }
  }
  cout << maxProfit << " " << price << endl;
  return 0;
}
#endif