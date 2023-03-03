#include <bits/stdc++.h>
using namespace std;
const bool dbg = true;

class Aircons {
 public:
  int startRange;
  int endRange;
  int cooled;
  int cost;

  Aircons(int a, int b, int c, int pr) {
    startRange = a;
    endRange = b;
    cooled = c;
    cost = pr;
  }
};

// returns cost if it covers all cows
// if it doesnt work, returns neg 1
int solve(vector<bool>& usedAirCons, vector<int> stalls,
          vector<Aircons>& airCons) {
  int price = 0;
  for (int i = 0; i < usedAirCons.size(); i++) {
    if (usedAirCons[i]) {
      price += airCons[i].cost;
      // apply each aircon
      for (int a = airCons[i].startRange; a <= airCons[i].endRange; a++) {
        stalls[a] -= airCons[i].cooled;
      }
    }
  }
  // check if all cows happy
  for (int i = 0; i < stalls.size(); i++) {
    if (stalls[i] > 0) {
      return -1;
    }
  }
  return price;
}

#ifndef TESTING
int main() {
  int n, m;
  // if (dbg) cout << "Starting..." << endl;
  cin >> n >> m;
  vector<int> stalls(100, 0);
  vector<Aircons> airCons;

  // put waht cows need
  for (int i = 0; i < n; i++) {
    int rstart, rend, cool;
    cin >> rstart >> rend >> cool;
    for (int i = rstart; i <= rend; i++) {
      stalls[i] += cool;
    }
  }

  // storing aircons

  for (int i = 0; i < m; i++) {
    int rstart, rend, cool, cost;
    cin >> rstart >> rend >> cool >> cost;
    airCons.push_back(Aircons(rstart, rend, cool, cost));
  }
  m = airCons.size();
  int ret = INT_MAX;
  // permuting through aircons
  for (int perm = 1; perm < (1 << m); perm++) {
    vector<bool> usedAirCons(m, false);
    for (int a = 0; a < m; a++) {
      if (perm & (1 << a)) {
        usedAirCons[a] = true;
      }
    }
    int prc = solve(usedAirCons, stalls, airCons);
    if (prc != -1 && prc < ret) {
      ret = prc;
    }
  }
  cout << ret << endl;
  return 0;
}
#endif
