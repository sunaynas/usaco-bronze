#include <bits/stdc++.h>
using namespace std;
const bool DEBUG = false;

bool maxCowChange(map<string, bool> &maxCows, map<string, int> &cows) {
  map<string, int>::iterator itr;
  // dont necessarily need to store this a as pair
  pair<string, int> entryWithMaxValue;
  // go through the 3 cows to find the max milk atm
  for (itr = cows.begin(); itr != cows.end(); ++itr) {
    if (itr->second > entryWithMaxValue.second) {
      entryWithMaxValue = make_pair(itr->first, itr->second);
    }
  }
  // cout << "max milker is " << entryWithMaxValue.first << " at "
  //      << entryWithMaxValue.second << " gals per day" << endl;

  bool changed = false;
  map<string, int>::iterator itr2;
  // find who else is at that max
  for (itr2 = cows.begin(); itr2 != cows.end(); ++itr2) {
    if (itr2->second == entryWithMaxValue.second &&
        maxCows[itr2->first] != true) {
      // if that cow is = to the max and it previously
      // it was not a max
      // cout << "changing " << itr2->first
      //      << " from not being a max to being a max " << endl;
      maxCows[itr2->first] = true;
      changed = true;
    } else if (maxCows[itr2->first] == true &&
               itr2->second != entryWithMaxValue.second) {
      // if this cow USED to be the max and now it is not
      // cout << "changing " << itr2->first
      //      << " from  being a max to not being a max " << endl;
      changed = true;
      maxCows[itr2->first] = false;
    }
  }
  return changed;
  // if difference from prev max cows then ret true
  // change max cows first ofc
}
int solve(vector<pair<string, string> > &instructions) {
  // instructions are sorted by day so you can access them chronologically
  map<string, int> cows;
  cows["Bessie"] = 7;
  cows["Elsie"] = 7;
  cows["Mildred"] = 7;
  map<string, bool> maxCows;
  maxCows["Bessie"] = true;
  maxCows["Elsie"] = true;
  maxCows["Mildred"] = true;
  int maxCowChanges = 0;
  // only changing 1 at a time
  for (int i = 0; i < instructions.size(); i++) {
    if (instructions[i].first != "" && instructions[i].second != "") {
      if (DEBUG) cout << "day " << i << endl;
      // cows[instructions[i].first]
      if ((instructions[i].second)[0] == '+') {
        if (DEBUG)
          cout << "adding " << (int)((instructions[i].second)[1] - '0')
               << " to cow " << instructions[i].first
               << "'s production which is now "
               << cows[instructions[i].first] +
                      (int)((instructions[i].second)[1] - '0')
               << endl;
        cows[instructions[i].first] += (int)((instructions[i].second)[1] - '0');
      } else {  // subtracting
        if (DEBUG)
          cout << "subtracting " << (int)((instructions[i].second)[1] - '0')
               << " to cow " << instructions[i].first
               << "'s production which is now "
               << cows[instructions[i].first] -
                      (int)((instructions[i].second)[1] - '0')
               << endl;
        cows[instructions[i].first] -= (int)((instructions[i].second)[1] - '0');
      }
      if (DEBUG)
        cout << "calling max cow change with Bessie: " << cows["Bessie"]
             << " Elsie: " << cows["Elsie"] << " Mildred: " << cows["Mildred"]
             << ", and max cow with Bessie: " << maxCows["Bessie"]
             << " Elsie: " << maxCows["Elsie"]
             << " Mildred: " << maxCows["Mildred"] << endl;
      if (maxCowChange(maxCows, cows)) {
        maxCowChanges++;
        if (DEBUG) cout << "change is now " << maxCowChanges << endl;
      }
    }
  }
  return maxCowChanges;
}
#ifndef TESTING
int main() {
  int n;
  cin >> n;
  vector<pair<string, string> > instructions(100);
  fill(instructions.begin(), instructions.end(), make_pair("", ""));
  for (int i = 0; i < n; i++) {
    int day;
    string cow, change;
    cin >> day >> cow >> change;
    instructions[day] = make_pair(cow, change);
  }
  cout << solve(instructions);
  return 0;
}
#endif