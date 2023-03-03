#include <bits/stdc++.h>
using namespace std;

int work = 0;
bool D = false;
// it solves some segment and increments the answer as it does
// makes all cows happy from start to end-1
void solve(vector<int> &temps, int start, int end) {
  // start = 4, end = 4
  int minimum = INT_MAX;
  for (int i = start; i < end; i++) {
    minimum = min(abs(temps[i]), minimum);
  }
  bool pos = temps[start] > 0;
  for (int i = start; i < end; i++) {
    // if pos
    if (pos) {
      temps[i] = temps[i] - minimum;
    } else {  // if neg
      temps[i] = temps[i] + minimum;
    }
  }
  work += minimum;
}

int main() {
  int n;
  cin >> n;
  vector<int> temps(n);
  vector<int> desiredTemps(n);
  int temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    desiredTemps[i] = temp;
  }
  for (int i = 0; i < n; i++) {
    cin >> temp;
    temps[i] = desiredTemps[i] - temp;
  }

  int zeroEnd = 0;
  bool done = false;
  int start, end;
  while (!done) {
    start = 0;
    // Start at 0
    // skip over all the items that are 0
    done = true;
    for (int i = zeroEnd; i < temps.size(); i++) {
      if (temps[i] != 0) {
        zeroEnd = i;
        start = i;
        done = false;
        break;
      }
    }
    end = start + 1;
    // mark starting point
    // go till next zero or sign flip
    for (int i = start + 1; i <= temps.size(); i++) {
      if (i == temps.size()) {
        end = i;
        break;
      } else if ((temps[i] == 0) ||  // if at solved but before is not solved
                 (temps[i] > 0 && temps[i - 1] < 0) ||  // if sign changes
                 (temps[i] < 0 && temps[i - 1] > 0)) {
        end = i;
        break;
      }
    }
    // mark end
    // solve
    solve(temps, start, end);
  }
  cout << work << endl;
  return 0;
}

// 0 3 1 1 3
