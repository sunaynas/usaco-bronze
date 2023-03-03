#include <bits/stdc++.h>
using namespace std;
class Cow {
 public:
  int x;
  int y;
  char dir;
  pair<int, int> minIntersect;
};
// returns steps until death and who died
// steps are -1 if no intersect
// cow dead will = -1 if they intersect at same time
pair<int, int> intersect(Cow cow1, Cow cow2) {
  // for E eqn: y = get<1>(cow) for x>= get<0>(cow)
  // for N eqn: x = get<0>(cow) for y>= get<1>(cow)
}

int solve(int i, vector<Cow> cows) {
  for (int j = 0; j < cows.size(); j++) {
  }
  if (solve(cows[i].minIntersect, cows) >) }

#ifndef TESTING
int main() {
  int n;
  cin >> n;
  vector<Cow> cows(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    char d;
    cin >> d >> x >> y;
    cows[i].x = x;
    cows[i].y = y;
    cows[i].dir = d;
  }
  for (int i = 0; i < cows.size(); i++) {
    solve(i, cows);
  }
  return 0;
}
#endif