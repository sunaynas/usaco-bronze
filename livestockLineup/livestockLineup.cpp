#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vstring;
/*
void insert(string cow1, string cow2) {
  string minS = min(cow1, cow2);
  cow1 = max(cow1, cow2);
  cow2 = minS;
  string next = cow2;
  for (int i = getIndexOfCow(cow1) + 1; i <= getIndexOfCow(cow2); i++) {
    string garb = cows[i];
    cows[i] = next;
    next = garb;
  }
  return;
}
void insertbackwards(string cow1, string cow2) {
  string minS = min(cow1, cow2);
  cow1 = max(cow1, cow2);
  cow2 = minS;
  //
  return;
}

int getIndexOfCow(string cowname) {
  for (int i; i < cows.size(); i++) {
    if (cowname == cows[i]) {
      return i;
    }
  }
}
vector<string> solve(map<string, vector<string>> reqCows) {
  for (int i = 0; i < 8; i++) {
    auto itr = reqCows.find(cows[i]);
    if (itr != reqCows.end()) {
    }
  }
}*/
// if cow is not been printed earlier only then print it
// add the cow being printed to the set.
void printCow(string cow, set<string> &cowUsed) {
  if (cowUsed.find(cow) == cowUsed.end()) {
    cout << cow << endl;
    cowUsed.insert(cow);
  }
}
// find all the neighbors for cow thats given.
void findOneNeighbors(map<string, vstring> &reqCows, string &cow,
                      vector<string> &neighbors) {
  neighbors.push_back(cow);
  auto nv = reqCows.find(cow);
  cout << " findOneNeighbors:" << cow
       << " nv = " << ((nv == reqCows.end()) ? "true" : "false") << "." << endl;

  if (nv != reqCows.end()) {
    cout << "    FON " << nv->second.size() << endl;
    auto n = nv->second.at(0);
    findOneNeighbors(reqCows, n, neighbors);
  }
}
// find all the neighbors for cow thats given.
void findAllNeighbors(map<string, vstring> &reqCows, string &cow,
                      set<string> &cowUsed) {
  cout << " findAllNeighbors : " << cow << endl;
  auto nv = reqCows.find(cow);
  vector<string> right, left;
  if (nv != reqCows.end()) {
    vector<string> n = nv->second;
    findOneNeighbors(reqCows, n[0], left);
    cout << "    l-> " << left.size() << endl;
    auto leftItm = max_element(begin(left), end(left));

    auto rightItm = right.end();
    if (n.size() == 2) {
      findOneNeighbors(reqCows, n[1], right);
      rightItm = max_element(begin(right), end(right));
    }
    cout << "    r-> " << right.size() << endl;
    // find min cow on left and right
    //    cout << "    max-> " << *leftItm << " " << *rightItm << endl;
    if (rightItm != right.end() && *leftItm < *rightItm) {
      // print left -> cow -> right
      for (int i = left.size() - 1; i >= 0; i--) {
        printCow(left[i], cowUsed);
      }
      printCow(cow, cowUsed);
      for (int i = 0; i < right.size(); ++i) {
        printCow(right[i], cowUsed);
      }

    } else {
      // print right -> cow -> left
      for (int i = right.size() - 1; i >= 0; i--) {
        printCow(right[i], cowUsed);
      }
      printCow(cow, cowUsed);
      for (int i = 0; i < left.size(); ++i) {
        printCow(left[i], cowUsed);
      }
    }
  } else {
    printCow(cow, cowUsed);
  }
}

int main() {
  vector<string> cows{"Bessie", "Buttercup", "Belinda", "Beatrice",
                      "Bella",  "Blue",      "Betsy",   "Sue"};
  int n;
  cin >> n;
  // data structure to store provided information
  // for each cow store who they are next to
  map<string, vstring> reqCows;
  for (int i = 0; i < n; i++) {
    string cow1, cow2, garb;
    cin >> cow1 >> garb >> garb >> garb >> garb >> cow2;
    // auto minCow = min(cow1, cow2);
    if (cow2 > cow1) {
      reqCows[cow1].push_back(cow2);
    } else {
      reqCows[cow2].push_back(cow1);
    }
  }
  // solve(reqCows);
  for (auto it = reqCows.begin(); it != reqCows.end(); ++it) {
    cout << " ReqCow " << it->first << " :: ";
    for (auto v : it->second) {
      cout << " " << v;
    }
    cout << endl;
  }

  // iterate through all the cows in sorted order
  sort(cows.begin(), cows.end());
  for (auto c : cows) {
    cout << c << " ";
  }
  cout << endl;
  // c-a , f-a, z-c
  // a->c,f c->z
  // a-> c f
  // caf or fac
  // zcaf
  // facz
  set<string> cowUsed;
  for (auto cow : cows) {
    findAllNeighbors(reqCows, cow, cowUsed);
  }
}