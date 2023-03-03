#include <bits/stdc++.h>
using namespace std;

string cowEndResult;

map<int, pair<int, int> > hoofshakes;
bool DEBUG = false;

bool simulate(int cow, int k) {
  vector<bool> hypotheticalCows(cowEndResult.size(), false);
  vector<int> cowShakes(cowEndResult.size(), 0);
  if (DEBUG) cout << "simulating cow " << cow << " with kval " << k << endl;
  hypotheticalCows[cow] = 1;
  if (DEBUG)
    cout << "hypothetical cow " << cow << " is set to  "
         << hypotheticalCows[cow] << endl;

  auto i = hoofshakes.begin();
  for (; i != hoofshakes.end(); i++) {
    if (DEBUG)
      cout << i->first << " " << i->second.first << " " << i->second.second
           << endl;
    if (i->second.first == cow + 1 || i->second.second == cow + 1) {
      if (DEBUG) cout << "first occurrence at " << i->first << endl;
      break;
    }
  }

  for (; i != hoofshakes.end(); i++) {
    // dealing with 2 cows i->second.first && i->second.second
    // only infect if less than k
    if (DEBUG)
      cout << "this shake is at time " << i->first << " between cow "
           << i->second.first - 1 << " and " << i->second.second - 1 << endl
           << "at the moment the first cow is "
           << hypotheticalCows[i->second.first - 1] << " and the second cow is "
           << hypotheticalCows[i->second.second - 1] << endl;
    if ((hypotheticalCows[i->second.first - 1] == 1 &&
         cowShakes[i->second.first - 1] < k) &&
        (hypotheticalCows[i->second.second - 1] == 1 &&
         cowShakes[i->second.second - 1] < k)) {
      hypotheticalCows[i->second.second - 1] = 1;
      hypotheticalCows[i->second.first - 1] = 1;
      cowShakes[i->second.first - 1]++;
      cowShakes[i->second.second - 1]++;
    } else if ((hypotheticalCows[i->second.first - 1] == 1 &&
                cowShakes[i->second.first - 1] < k)) {
      hypotheticalCows[i->second.second - 1] = 1;
      hypotheticalCows[i->second.first - 1] = 1;
      cowShakes[i->second.first - 1]++;
    } else if ((hypotheticalCows[i->second.second - 1] == 1 &&
                cowShakes[i->second.second - 1] < k)) {
      hypotheticalCows[i->second.second - 1] = 1;
      hypotheticalCows[i->second.first - 1] = 1;
      cowShakes[i->second.second - 1]++;
    }
  }

  for (int i = 0; i < hypotheticalCows.size(); i++) {
    if (DEBUG)
      cout << "at index i=" << i << " this cases cow would be "
           << (int)hypotheticalCows[i] << " and the real cow would be "
           << int(cowEndResult[i] - '0') << endl;
    if ((int)hypotheticalCows[i] != int(cowEndResult[i] - '0')) {
      return false;
    }
  }
  return true;
}
pair<int, int> validPatientZero(int cow) {
  // find first appearance chronologically in hoof shake
  pair<int, int> kvals;
  for (int kMin = 1; kMin < hoofshakes.size(); kMin++) {
    if (simulate(cow, kMin)) {
      kvals.first = kMin;
      if (DEBUG) cout << "setting the k min to " << kMin << endl;
      break;
    }
    if (kMin == hoofshakes.size() - 1) {
      if (DEBUG)
        cout << "kMin is not found, the cow cannot be patient 0 " << endl;
      return make_pair(-1, -1);
    }
  }
  if (DEBUG) cout << " sucessful break" << endl;
  for (int kMax = hoofshakes.size(); kMax > -1; kMax--) {
    if (simulate(cow, kMax)) {
      if (kMax == hoofshakes.size()) {
        if (DEBUG) cout << "k max has no bound and goes to infinity " << endl;
        kvals.second = -1;
        break;
      }
      kvals.second = kMax;
      if (DEBUG) cout << "setting the k max to " << kMax << endl;
      break;
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
      if (DEBUG) cout << "setting final min to " << minK << endl;
      if (answ.second == -1) {
        maxK = -1;
        if (DEBUG) cout << "setting infinity min to true " << endl;
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
    hoofshakes[time] = make_pair(cow1, cow2);
  }
  int minK, maxK, possiblePatientZs;
  solve(minK, maxK, possiblePatientZs);
  if (minK == INT_MAX) {
    minK = 0;
  }
  cout << possiblePatientZs << " " << minK << " ";
  if (maxK == -1) {
    cout << "Infinity" << endl;
  } else
    cout << maxK << endl;
  return 0;
}
#endif