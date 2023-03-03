#include <bits/stdc++.h>
using namespace std;

bool DEBUG = false;

bool winner(vector<int> &diceA, vector<int> &diceB) {
  // returns if dice a would win against dice b
  // always out of 16
  if (DEBUG)
    cout << "DiceA " << diceA[0] << " " << diceA[1] << " " << diceA[2] << " "
         << diceA[3] << " and DiceB " << diceB[0] << " " << diceB[1] << " "
         << diceB[2] << " " << diceB[3] << endl;
  int wincnt = 0;
  int losecnt = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (diceA[i] > diceB[j]) {
        wincnt++;
      } else if (diceA[i] < diceB[j]) {
        losecnt++;
      }
    }
  }
  return (wincnt > losecnt);
}

string solve(vector<int> &diceA, vector<int> &diceB) {
  // supposed to win agians me = loser(diceA, diceB)
  // supposed to lose against me = winner(diceA, diceB)
  // calculate which a or b wins
  vector<int> *supposedLoser = &diceB;
  vector<int> *supposedWinner = &diceA;
  if (winner(diceA, diceB)) {
    supposedLoser = &diceA;
    supposedWinner = &diceB;
  }

  vector<int> permute(4);
  for (int a = 1; a < 11; a++) {
    permute[0] = a;
    for (int b = 1; b < 11; b++) {
      permute[1] = b;
      for (int c = 1; c < 11; c++) {
        permute[2] = c;
        for (int d = 1; d < 11; d++) {
          permute[3] = d;
          if (winner(*supposedWinner, permute) &&
              winner(permute, *supposedLoser)) {
            if (DEBUG)
              cout << "permutation " << permute[0] << " " << permute[1] << " "
                   << permute[2] << " " << permute[3] << " worked" << endl;
            return "yes";
          }
        }
      }
    }
  }

  return "no";
}

#ifndef TESTING
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    vector<int> diceA(4);
    vector<int> diceB(4);
    for (int j = 0; j < 4; j++) {
      int side;
      cin >> side;
      diceA[j] = side;
    }
    for (int j = 0; j < 4; j++) {
      int side;
      cin >> side;
      diceB[j] = side;
    }
    cout << solve(diceA, diceB) << endl;
  }
  return 0;
}
#endif