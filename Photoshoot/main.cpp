#include <bits/stdc++.h>
using namespace std;

#ifndef TESTING
int main() {
  int n;
  // n lowest = 2
  // n highest = 2*10^5!!
  cin >> n;
  vector<char> cows;

  string cowString;
  cin >> cowString;
  // i am tempted to store it from 1
  for (int i = 0; i < n; i += 2) {
    if (cowString[i] == 'H' && cowString[i + 1] == 'G') {
      // c for correct
      if (cows.size() == 0 || cows[cows.size() - 1] != 'c') {
        cows.push_back('c');
      }
    } else if (cowString[i] == 'G' && cowString[i + 1] == 'H') {
      // w for wrong
      if (cows.size() == 0 || cows[cows.size() - 1] != 'w') {
        cows.push_back('w');
      }
    }
  }
  if (cows[cows.size() - 1] == 'c') {
    cout << cows.size() - 1 << endl;
  } else
    cout << cows.size() << endl;
  return 0;
}
#endif