#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  pair<char, int> p[n];
  for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
  int ans = n;
  for (int i = 0; i < n; i++) {
    int liars = 0;
    for (int j = 0; j < n; j++)
      if ((p[j].first == 'L' && p[i].second > p[j].second) ||
          (p[j].first == 'G' && p[i].second < p[j].second))
        liars++;
    ans = min(ans, liars);
  }
  cout << ans;
}