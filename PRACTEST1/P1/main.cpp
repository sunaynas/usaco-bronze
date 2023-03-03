#include <bits/stdc++.h>
using namespace std;
// return green then uellow
pair<int, int> solve(vector<string> answer, vector<string> guess) {
  pair<int, int> gy;
  map<char, int> answ;
  map<char, int> guessOccurrences;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (answer[i][j] == guess[i][j]) {
        gy.first++;
      }
      answ[answer[i][j]]++;
      guessOccurrences[guess[i][j]]++;
    }
  }

  for (auto itr : guessOccurrences) {
    // if the character being guessed is also in the answ
    if (answ.find(itr.first) != answ.end()) {
      // if guessed more than there is (guess[it.first] - answ[it.first])
      // if guessed less than guess[it.first]
      if (guessOccurrences[itr.first] > answ[itr.first]) {
        gy.second += answ[itr.first];
      } else {
        gy.second += guessOccurrences[itr.first];
      }
    }
  }
  gy.second -= gy.first;
  return gy;
  // number of yellow is overlap -green
}
#ifndef TESTING
int main() {
  vector<string> answer(3);
  vector<string> guess(3);
  for (int i = 0; i < 3; i++) {
    string s;
    cin >> s;
    answer[i] = s;
  }
  for (int i = 0; i < 3; i++) {
    string s;
    cin >> s;
    guess[i] = s;
  }
  auto answ = solve(answer, guess);
  cout << answ.first << endl << answ.second;
  return 0;
}
#endif