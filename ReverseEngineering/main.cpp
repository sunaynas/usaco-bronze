#include <bits/stdc++.h>
using namespace std;

// class Data {
//  public:
//   string input;
//   bool output;
//   Data(string put, bool oput) {
//     input = put;
//     output = oput;
//   }
// };

bool dbg = false;

// need to add ignore pos
bool solve(map<string, bool>& instr, int& strsize, bool& sameRets,
           set<int>& ignorepos) {
  // num of positions = data.input.size()
  // for each position
  if (dbg)
    cout << "calling solve with instruction size " << instr.size() << endl;
  sameRets = true;
  if (instr.size() == 1) {
    return true;
  }
  for (int i = 0; i < strsize; i++) {
    bool brk = false;
    // find the first i that is not in the ignore list.
    while (ignorepos.find(i) != ignorepos.end()) {
      if (dbg) cout << i << " is going to be ignored" << endl;
      if (i < strsize - 1)
        i++;
      else {
        brk = true;
        break;
      }
    }
    if (brk) {
      break;
    }
    if (dbg) cout << "looking at pos " << i << endl;
    char trueOut = 'z';
    char falseOut = 'z';
    bool consistentOnes = true, consistentZeros = true;
    char output = 'z';
    // check if its the one
    for (auto it : instr) {
      if (dbg)
        cout << "looking at instr string " << it.first << " which returned "
             << it.second << endl;
      if (sameRets && output != 'z' && output != (int(it.second) + '0')) {
        if (dbg) cout << "setting sameRets to false " << endl;
        sameRets = false;
      }
      output = int(it.second) + '0';
      if (it.first[i] == '0' && consistentZeros) {
        if (falseOut == 'z') {
          if (dbg) cout << "setting false output to " << output << endl;
          falseOut = output;
        } else if (falseOut != output) {
          if (dbg) cout << "setting consistent zeros to false " << endl;
          consistentZeros = false;
        }
      }
      if (it.first[i] == '1' && consistentOnes) {
        if (trueOut == 'z') {
          if (dbg) cout << "setting true output to " << output << endl;
          trueOut = output;
        } else if (trueOut != output) {
          if (dbg) cout << "setting consistent ones to false " << endl;
          consistentOnes = false;
        }
      }
      if (!consistentOnes && !consistentZeros) {
        break;
      }
    }
    if (sameRets) {
      return true;
    }
    if (consistentOnes) {
      vector<string> ss;
      for (auto it : instr) {
        if (it.first[i] == '1') {
          if (dbg) cout << "erasing " << it.first << endl;
          ss.push_back(it.first);
        }
      }
      for (string v : ss) {
        instr.erase(v);
      }
      if (dbg) cout << "adding " << i << " to ignore" << endl;
      ignorepos.insert(i);
      return solve(instr, strsize, sameRets, ignorepos);
    } else if (consistentZeros) {
      vector<string> ss;
      for (auto it : instr) {
        if (it.first[i] == '0') {
          if (dbg) cout << "erasing " << it.first << endl;
          ss.push_back(it.first);
          if ((instr.size() - ss.size()) == 1) {
            break;
          }
        }
      }
      for (string v : ss) {
        instr.erase(v);
      }
      if (dbg) cout << "adding " << i << " to ignore" << endl;
      ignorepos.insert(i);
      return solve(instr, strsize, sameRets, ignorepos);
    }
  }
  return false;
}
#ifndef TESTING
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, m;
    cin >> n >> m;
    // vector<Data> instr(m);
    map<string, bool> instr;
    bool lie = false;
    for (int j = 0; j < m; j++) {
      string str;
      bool boo;
      cin >> str >> boo;
      if (!lie) {
        if (instr.find(str) != instr.end() && instr[str] != boo) {
          lie = true;
        }
        instr[str] = boo;
      }
    }

    bool sameRets = false;
    set<int> ignorepos;
    if (!lie) {
      // if solve is true, lie is not true
      lie = !solve(instr, n, sameRets, ignorepos);
    }
    if (lie) {
      cout << "LIE" << endl;
    } else {
      cout << "OK" << endl;
    }
  }
  return 0;
}
#endif