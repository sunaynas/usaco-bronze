#include <bits/stdc++.h>
using namespace std;

int work = 0;
bool D = false;
// it solves some segment and incrememnts the answer as it does
// makes all cows happy from start to end-1
int adjMinimum(vector<int> &temps, int start, int end) {
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
  return minimum;
}
int findFlip(vector<int> &temps, int start) {
  int end = start + 1;
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
  return end;
}
void solve(int zeroEnd, vector<int> &temps) {
  int start, end;
  start = zeroEnd;
  for (int i = zeroEnd; i < temps.size(); i++) {
    if (temps[i] != 0) {
      zeroEnd = i;
      start = i;
      break;
    }
  }
  end = findFlip(temps, start);
  if (adjMinimum(temps, start, end) == 0) return;
  return solve(zeroEnd, temps);
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
  solve(0, temps);
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