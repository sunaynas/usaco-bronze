#include <bits/stdc++.h>
using namespace std;

int work = 0;
bool D = false;
// it solves some segment and incrememnts the answer as it does
// makes all cows happy from start to end-1
void solve(vector<int> &temps, int start, int end) {
  // start = 4, end = 4
  if (D) {
    cout << "calling solve, start =" << start << " end=" << end << endl;
  }
  if (D) {
    cout << "TMPS at begine :";

    for (int i = start; i < end; ++i) {
      cout << temps[i] << " ";
    }
    cout << endl;
  }

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
  if (D) {
    cout << "TMPS at end [" << minimum << "]:";

    for (int i = start; i < end; ++i) {
      cout << temps[i] << " ";
    }
    cout << endl;
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

  if (D) {
    cout << endl << " TEMP : ";
    for (int i = 0; i < n; i++) cout << temps[i] << " ";
    cout << endl << " DESIRED: ";
    for (int i = 0; i < n; i++) cout << desiredTemps[i] << " ";
    cout << endl;
  }
  int zeroEnd = 0;
  bool done = false;
  int start, end;
  while (!done) {
    start = 0;
    // Start at 0
    // skip over all the items that are 0
    done = true;
    if (D) {
      cout << " TEMPS FULL:";
      for (int i = 0; i < temps.size(); i++) {
        cout << temps[i] << " ";
      }
      cout << endl;
    }
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
      if (D)
        cout << " temps[i] = " << temps[i] << " temps[i-1] = " << temps[i - 1]
             << endl;
      if (i == temps.size()) {
        end = i;
        break;
      } else if ((temps[i] == 0) ||  // if at solved but before is not solved
                 (temps[i] > 0 && temps[i - 1] < 0) ||  // if sign changes

                 (temps[i] < 0 && temps[i - 1] > 0)) {
        end = i;
        if (D) cout << " setting end = " << i << endl;
        // if (i == temps.size() - 1 && temps[i] != 0) {
        //   end = temps.size();
        // }
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

/*
    // repeat

    done = true;
    start = 0;
    end = start;
    for (int i = 1; i < temps.size(); i++) {
      if (D)
        cout << "looking at " << temps[i] << " and " << temps[i - 1] << endl;
      if (temps[i] != 0 || temps[i - 1] != 0) {
        done = false;
      }
      if ((i == temps.size() - 1 &&
           temps[i] != 0) ||  // if it's at the end and not solved
          (temps[i] == 0 &&
           temps[i - 1] != 0) ||  // if at solved but before is not solved
          (temps[i] > 0 && temps[i - 1] < 0) ||  // if sign changes
          (temps[i] < 0 && temps[i - 1] > 0)) {  // if sign changes
        start = end;
        while (temps[start] == 0) {
          start++;
        }
        end = i;
        solve(temps, start, end);
        break;
      }
    }*/