#include <bits/stdc++.h>
using namespace std;
// chains of closest ones together? need to cosnider that
bool DEBUG = false;

int findNearest(set<int> &cows, int cow) {
  int neighborSearch = 0;
  while (cow - neighborSearch > -1) {
    neighborSearch++;
    if (cows.find(cow + neighborSearch) != cows.end()) {
      return cow + neighborSearch;
    } else if (cows.find(cow - neighborSearch) != cows.end()) {
      return cow - neighborSearch;
    }
  }
  // error
  return -1;
}

int solve(set<int> &cows) {
  //  2345
  // ->  X ?? X <------
  // |X  ||    ||        X|
  // || is diff when approaching from diff sides
  // can either be <--> or in same direction
  // if all in same dir add 1 if 2 direction add 2
  //          <-  ->  ->
  // 1 2 |4 5| 8 12 15 17 |19 20| 22 |27 29|
  // if ends are not closest duos then +2 and take out 2 nearest cows
  vector<pair<int, int> > closestDuos;
  set<int> ignoreCows;
  for (auto a : cows) {
    int aNearestCow = findNearest(cows, a);
    if (DEBUG)
      cout << "cow " << a << "'s closest neighbor is " << aNearestCow
           << " and their closesest neighbor is "
           << findNearest(cows, aNearestCow) << endl;
    // if its nearest nearest is itself
    // and the cow is not in ignore
    if (ignoreCows.find(a) == ignoreCows.end() &&
        a == findNearest(cows, aNearestCow)) {
      if (DEBUG)
        cout << "found one pair of cows who are closest to one another "
             << endl;
      closestDuos.push_back(make_pair(a, aNearestCow));
      ignoreCows.insert(aNearestCow);
      ignoreCows.insert(a);
    }
  }

  // i think this shouldbe changed. in between any 2 || u should check
  // if they are going same dir or not
  // each one can only have two sides anyway

  return closestDuos.size() + 1;
}

#ifndef TESTING
int main() {
  int n;
  cin >> n;
  set<int> cows;
  for (int i = 0; i < n; i++) {
    int cowDist;
    cin >> cowDist;
    cows.insert(cowDist);
  }
  cout << solve(cows);
  return 0;
}
#endif

// failed 3,4,6,7,8,9,10
// [assed 1,2,5

/* // closestDuos[closestDuos.size()].second &&
  // closestDuos[closestDuos.size()-1].first are range

  if (closestDuos.size() % 2 == 0) {
    int dir1 = 0, dir2 = 2;  // -1 for back, 1 for ->
    auto itr = cows.find(closestDuos[closestDuos.size()].second);
    if (itr != cows.end()) itr++;
    if (findNearest(cows, *itr) > (*itr)) {
      dir1 = 1;
    } else if (findNearest(cows, *itr) < (*itr)) {
      dir1 = -1;
    }
    auto itr2 = cows.find(closestDuos[closestDuos.size() - 1].first);
    if (itr2 != cows.end()) itr2--;
    if (findNearest(cows, *itr2) > (*itr2)) {
      dir2 = 1;
    } else if (findNearest(cows, *itr2) < (*itr2)) {
      dir2 = -1;
    }

    if (dir1 == dir2) {
      return closestDuos.size() + 1;
    } else
      return closestDuos.size() + 2;
  }*/