#include <bits/stdc++.h>
using namespace std;
// just check everything there are very few blocks and letters
// shouldnt be an issue
bool solve(vector<string> blocks, string word) {
  // cout << "SOLVE Called with block : " << blocks.size() << " word:" << word
  //<< endl;
  if (word.size() == 0) {
    return true;
  }
  // code to find only the first letter and matching cube
  for (int j = 0; j < blocks.size(); j++) {
    if (blocks[j].find(word[0]) != string::npos) {
      vector<string> block2(blocks.begin(), blocks.end());
      block2.erase(block2.begin() + j);
      string word2 = word.substr(1, word.size() - 1);
      if (solve(block2, word2)) {
        return true;
      }
    }
  }
  return false;
}

#ifndef TESTING
int main() {
  int q;
  cin >> q;
  vector<string> blocks(4);
  for (int i = 0; i < 4; i++) {
    cin >> blocks[i];
  }
  for (int i = 0; i < q; i++) {
    string word;
    cin >> word;
    if (solve(blocks, word)) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    if (i != q - 1) {
      cout << endl;
    }
  }
  return 0;
}
#endif