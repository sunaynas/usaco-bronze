#include <bits/stdc++.h>
using namespace std;

bool DEBUG = true;

void flip(vector<char> &cows, int flipIndex) {
  if (DEBUG) {
    cout << "vector before flip at [" << flipIndex << "]";
    for (int i = 0; i < cows.size(); i++) {
      cout << cows[i];
    }
    cout << endl;
  }
  for (int i = 0; i <= flipIndex; i++) {
    if (cows[i] == 'w') {
      cows[i] = 'c';
    } else if (cows[i] == 'c') {
      cows[i] = 'w';
    }
  }
  // flip index is how far from end?
  reverse(cows.begin(), cows.end() - cows.size() + flipIndex + 1);
  if (DEBUG) {
    cout << "vector after flip ";
    for (int i = 0; i < cows.size(); i++) {
      cout << cows[i];
    }
    cout << endl;
  }
}

int solve(vector<char> &cows) {
  int indexStartMakeWrong = cows.size();
  for (int i = cows.size() - 1; i >= 0; i--) {
    if (cows[i] == 'w') {
      if (DEBUG) cout << "first wrong sighted at index " << i << endl;
      indexStartMakeWrong = i;
      break;
    }
  }
  int flips = 0;
  int maxw = 0;
  int maxc = 0;
  int maxwStep = 0;
  if (DEBUG)
    cout << "looking for rights to turn wrong starting from index "
         << indexStartMakeWrong << endl;
  for (int i = indexStartMakeWrong; i >= 0; i--) {
    if (cows[i] == 'c') {
      if (DEBUG) cout << "found right to wrong at " << i << endl;
      flip(cows, i);
      flips++;
      if (DEBUG) {
        int wc = 0;
        int cc = 0;
        for (int t = 0; t < cows.size(); ++t) {
          if (cows[t] == 'w') wc++;
          if (cows[t] == 'c') cc++;
        }
        if (wc > maxw) {
          maxw = wc;
          maxwStep = flips;
          maxc = cc;
        }
      }
    }
  }
  if (DEBUG)
    cout << " Max W was " << maxw << " max C ws " << maxc
         << "  at flip = " << maxwStep << " current Flip " << flips << endl;
  return flips + 1;
  // bc u need one final flip to make everything right after its wrong
}

#ifndef TESTING
int main() {
  int n;
  // n lowest = 2
  // n highest = 2*10^5!!
  cin >> n;
  vector<char> cows;

  string cowString;
  cin >> cowString;

  // i am tempted to store it from 1
  for (int i = 0; i < n; i += 2) {
    if (cowString[i] == 'H' && cowString[i + 1] == 'H') {
      cows.push_back('h');
    } else if (cowString[i] == 'H' && cowString[i + 1] == 'G') {
      // c for correct
      cows.push_back('c');
    } else if (cowString[i] == 'G' && cowString[i + 1] == 'G') {
      cows.push_back('g');
    } else if (cowString[i] == 'G' && cowString[i + 1] == 'H') {
      // w for wrong
      cows.push_back('w');
    }
  }
  if (DEBUG) {
    cout << " LEN:" << cowString.size() << endl;
    cout << "saved string " << cowString << " as ";
    for (int i = 0; i < cows.size(); i++) {
      cout << cows[i];
    }
    cout << endl;
  }
  cout << solve(cows) << endl;
  return 0;
}
#endif

/*
chghhhwwgwgwhggchhhcwcwhwhggwwgchwgghcwgwccwhgcwcgwwwwgwcwgwchccchhhwhgwhcwwhww
ghcwccchhwwhhcwccgcghgcchhcgwcwwwgwwwcgcggwgwghcwwcchcggggghhgcchwhcchcwwhhggcchgghhhhwhccwghhcwwwccgwcwccww
gcgwgchwghwwcwwcgwhhhchghggcchcwwhghgwghgchchccchhwwhhhccghwchhhcwchhhchhgwwgwhgwwgcgcgwghwghwgwghhhchhwhwhc
hwghchccgghghwhhgghghwghwwhhwwwgcghwghgchggghggggcghggccgcchwwcwwwwcghgwhhhwwwhghwcgghggchcghhgwwwgwhwggwcch
wwwcwcwwcccchcggwghhhwwwwchhhhcggwgwcwcchhgchcgchwhchhghcccggggwgcwwchwghcgghhcchggcgccwgcc
wghw hg first wrong sighted at index 497
wwgcwwgwgghwwhhggwhgchwccwgcggggwwwhghhwhchwgwhwghhwwcwcgcggwhhhhwcccchhhgcggwhwwwwccwcw
ccchwwcggchcgcccghhgwhwgghggwchghccchhhcghgwccccwcchwwgwwgghgwgggghggghwghgchgwgccchhcchgchghgghhchghggwwhwh
gchwhchchhwhhhgcgchgchgcgwgwgccghcgccghhwhhhwcwhhhwchgwwhhhcchhwwwhwhwghgcghghccwhwwgghghwhhhcgwccwcchgchwgc
gwgccwwcwcgwwcccwhhgcwwhchhhhgghwwgghhccwhwwhchwwghhgggggwhwwccwhgcgcggwgwcccgcccwcgwhhwwghgwgwwcwhhcchhwwwc
whgcchccwhcghchhhwwwhwcgcwcgccccgwcwghcwwcgcwhggchwgccgghchcwcwhhhwgghcgcgcchhhghw
wghwhg


vec b4 flip
cgcghwwgwccgccwhcgcghcwgwchchwchcghwhghhwwwwwgcwcgcghwwcwwhcwgghwghgwwhggcwgchw
cwwcwcwchwcwhwcwhhwchhhccgcwwwchhwwgwcwhcwwchwgcwhcghchhcgccchwwgwwggwchwgwghcwccgghwcgwhwhwggchwhcwchhhwccg
ghhhcghhccwcccwhggwcwwhgcccwwgchgwghwhgcwwwwwcwwwgchwwghgwchwghwhwcwgcchchwchgchcgwgcchwccghhgggggghhgwhgwgc
hcchcwcwghccccggwwwwggchgcgchghhhggcgghghhwwcchcccgcghgchwchwhwhhhwwwwgwwhwwhhcwwgwwgcgwwhhchwcwwghcwgwhccwg
hcwcgwcggghcwhgwcwhgcghgcwcghhwwcghwwhhcgwgwcghgghwgccwwgwhwgccwwhcgwggggcghhgchgwggwwwwgcgchc
hwh

whwgwgccccggcghwghhgwggggcgwhccwwgchcgccwwgchgghgwcgcgwhhcchgwcchhgwcwghgwghcwcghcwhgggwcgwcwhgcwwhcgcwhgccwchwhhccgwgccgccwhhcchccgcccchhhchchwchwghgwgwwwhwwcchhghggwgghhhghwgwghwggccccggwwwwhgcwcwhwwhwgcghcghhgggggghhgwwchwwgcgwhwghwchwhwwgcwchchgchwcghgcchwgcccwcccccwghchgcghwgccwwwghccwcgghcwwwcwwhhgwhhhggwwchhhwcwhchwggchchcgwchggwwcwhgcgchwcggccgcchwwwgwhhwhgwhcwgchwccwhcwcgcchhwcccwgwwhhhwchhcwchcwchwcwcwccwchwgcwgghccghgchggcwhccwcchgwgwcwgccccchhghchgwhwchwhwcgcwhgwgwhcwwgwwcgcchgwgwhwh


cw c
c wc
wwc
ccc

cccwwwwccc www
wwwcccc wwwwww
wwwwccc wwwwww

c ->
w ->
            <- c2
            <- w2
12345678901234
GGGHGHHGHHHGHG
g w w c h c c
gww chcc
ccgchcc

find the point where flipping will make left and right equale


*/
