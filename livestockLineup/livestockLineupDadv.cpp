#include <bits/stdc++.h>
using namespace std;

void collectCows(map<string, vector<string> >& cowOrder, string& c,
                 vector<string>& cow, int idx = 0) {
  auto it = cowOrder.find(c);
  if (it == cowOrder.end()) {
    return;
  }
  cow.push_back(it->second[idx]);
  collectCows(cowOrder, it->second[idx], cow);
}

void processCowClusters(map<string, vector<string> >& cowOrder,
                        set<string>& cowProcessed, string& cow,
                        map<string, vector<string> >& cowsOut) {
  // look at the cow in cow order ...
  // find all the neighbors
  // the last item in the neighbour list is at the end and is needed
  if (cowProcessed.find(cow) != cowProcessed.end()) return;
  auto it = cowOrder.find(cow);
  if (it == cowOrder.end()) {  // no neighbour
    cowsOut[cow].push_back(cow);
  } else {  // one neighbour
    // processSingleChain(cowOrder, cow, cowsOut);
    vector<string> chain;
    collectCows(cowOrder, cow, chain, 0);
    chain.push_back(cow);
    if (it->second.size() == 2) {
      collectCows(cowOrder, cow, chain, 1);
    }
    // remove the objects from cowOrder
    for (auto c : chain) {
      cowProcessed.insert(c);
    }
    string lcow = chain[chain.size() - 1];
    string rcow = chain[0];
    if (lcow > rcow) {
      // attach the chain to cow
      cowsOut[rcow] = chain;
    } else {
      // attach the chain to lcow
      reverse(chain.begin(), chain.end());
      cowsOut[lcow] = chain;
    }
  }
}
int main() {
  int cnt;
  vector<string> cows{"Bessie", "Buttercup", "Belinda", "Beatrice",
                      "Bella",  "Blue",      "Betsy",   "Sue"};
  sort(cows.begin(), cows.end());
  cout << " Starting " << endl;
  cin >> cnt;
  map<string, vector<string> > cmap;
  for (int i = 0; i < cnt; ++i) {
    string c1, c2, tr;
    cin >> c1 >> tr >> tr >> tr >> tr >> c2;
    cmap[c1].push_back(c2);
    cmap[c2].push_back(c1);
  }
  map<string, vector<string> > cowsOut;
  set<string> cowProcessed;
  for (auto c : cows) {
    processCowClusters(cmap, cowProcessed, c, cowsOut);
  }
  int i = 0;
  for (auto it = cowsOut.begin(); it != cowsOut.end(); ++it) {
    for (auto c : it->second) {
      cout << i << " ::" << c << endl;
    }
    ++i;
  }
  return 0;
}