#include <bits/stdc++.h>
using namespace std;

string cowEndResult;
class CowPair {
 public:
  int c1;
  int c2;
  CowPair(int a, int b) {
    c1 = a;
    c2 = b;
  }
  bool match(int a) { return c1 == a || c2 == a; }
};

map<int, CowPair> hoofshakes;
bool DEBUG = true;

bool simulate(int cow, int k) {
  vector<bool> hypotheticalCows(cowEndResult.size(), false);
  vector<int> cowShakes(cowEndResult.size(), 0);

  hypotheticalCows[cow] = true;
  cowShakes[cow]++;

  auto i = hoofshakes.begin();

  for (i; i != hoofshakes.end(); i++) {
    if (i->second.match(cow)) {
      break;
    }
  }
  for (i; i != hoofshakes.end(); i++) {
    // dealing with 2 cows i->second.first && i->second.second
    // only infect if less than k
    if (hypotheticalCows[i->second.c1] == true &&
        cowShakes[i->second.c1] <= k) {
      hypotheticalCows[i->second.c2] = true;
      cowShakes[i->second.c1]++;
    } else if (hypotheticalCows[i->second.c2] == true &&
               cowShakes[i->second.c2] <= k) {
      hypotheticalCows[i->second.c1] = true;
      cowShakes[i->second.c2]++;
    }
  }

  for (int i = 0; i < hypotheticalCows.size(); i++) {
    if ((int)hypotheticalCows[i] != int(cowEndResult[i])) {
      return false;
    }
  }
  return true;
}
pair<int, int> validPatientZero(int cow) {
  // find first appearance chronologically in hoof shake
  pair<int, int> kvals;
  if (DEBUG) cout << "starting with kval " << 1 << " to check min" << endl;
  for (int kMin = 1; kMin < hoofshakes.size(); kMin++) {
    if (DEBUG) cout << "kval " << kMin << endl;
    if (simulate(cow, kMin)) {
      kvals.first = kMin;
      break;
    }
    if (kMin == hoofshakes.size() - 1) {
      return make_pair(-1, -1);
    }
  }
  for (int kMax = hoofshakes.size(); kMax < hoofshakes.size(); kMax++) {
    if (simulate(cow, kMax)) {
      kvals.second = kMax;
      break;
    }
    if (kMax == hoofshakes.size() - 1) {
      kvals.second = -1;
    }
  }
  return kvals;
  // if doesnt work will return -1
}

void solve(int &minK, int &maxK, int &possiblePatientZs) {
  minK = INT_MAX;
  maxK = 0;
  possiblePatientZs = 0;
  bool infinity = false;
  for (int i = 0; i < cowEndResult.size(); i++) {
    if (DEBUG) cout << "checking if cow " << i << " is patient zero" << endl;
    auto answ = validPatientZero(i);
    if (answ.first != -1) {
      possiblePatientZs++;
      minK = min(minK, answ.first);
      if (answ.second == -1) {
        infinity = true;
      }
      if (!infinity) {
        maxK = max(maxK, answ.second);
      }
    }
  }
}

#ifndef TESTING
int main() {
  int n, t;
  cin >> n >> t;
  cin >> cowEndResult;
  int time, cow1, cow2;
  for (int i = 0; i < t; i++) {
    cin >> time >> cow1 >> cow2;
    hoofshakes[time] = CowPair(cow1, cow2);
  }
  int minK, maxK, possiblePatientZs;
  solve(minK, maxK, possiblePatientZs);
  cout << possiblePatientZs << " " << minK << " " << maxK;
  return 0;
}
#endif