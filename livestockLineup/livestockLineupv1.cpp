#include <bits/stdc++.h>
using namespace std;

bool checkAlreadyUsed(vector<string> &comb, int idx, string &cow) {
  for (int i = 0; i < idx; ++i) {
    if (comb[i] == cow) return true;
  }
  return false;
}
// fill comb will fill a cow at index "idx" in the "comb" variable
// making sure that the cow does not exists in any index < idx
void fillComb(vector<string> &comb, int idx, vector<string> &cows) {
  if (idx == cows.size()) {
    cout << ":: ";
    for (auto c : comb) {
      cout << c << " ,";
    }
    cout << endl;
    return;
  }
  cout << ".. idx=" << idx << " ";
  for (auto c : comb) {
    cout << c << " ,";
  }
  cout << endl;
  for (auto cow : cows) {
    if (!checkAlreadyUsed(comb, idx, cow)) {
      comb[idx] = cow;
      fillComb(comb, idx + 1, cows);
    }
  }
}

int main() {
  vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice",
                         "Bella",  "Blue",      "Betsy",   "Sue"};
  // iterate through all combinations

  vector<string> comb(cows.size());
  fillComb(comb, 0, cows);
  return 0;
}
/*
# Objects
a b c d e f g
a<->c

e<->g

c<->f


acf -> A
eg -> E

A b d E
A -> (acf) -> acf fca
E -> eg ge

acfbdeg
*/