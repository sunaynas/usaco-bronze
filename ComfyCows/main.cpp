#include <bits/stdc++.h>
using namespace std;
int pack(int x, int y) {
  // return x + y * (2 ^ 11);
  return x | (y << 11);
}
const int M = (1 << 11) - 1;
int getx(int p) {
  return p & M;
  // return p % (1 << 11);
}
int gety(int p) {
  return p >> 11;
  // return p / (1 << 11);
}

static int neighbors(map<int, bool>& cows, int& cord) {
  //   cout << "finding neighbors of cow " << cord.first << " " << cord.second
  //        << endl;
  int neighbors = 0;
  //  if (cows[{cord.first + 1, cord.second}] == true) {
  //  if (cows[pack(getx(cord) + 1, gety(cord))] == true) {
  if (cows[cord + 1] == true) {
    // cout << "found a neighbor to the right" << endl;
    neighbors++;
  }
  if (cows[cord - 1] == true) {
    // cout << "found a neighbor to the left" << endl;
    neighbors++;
  }
  if (cows[cord + (1 << 11)] == true) {
    // cout << "found a neighbor above" << endl;
    neighbors++;
  }
  if (cows[cord - (1 << 11)] == true) {
    // cout << "found a neighbor below" << endl;
    neighbors++;
  }
  // cout << "this cow has " << neighbors << " neighbors" << endl;
  return neighbors;
}

static int neighborsNeighbor(int& neighborsNeighbor) {
  // cout << "calling neighbors neighbor" << endl;
  if (neighborsNeighbor == 3) {
    // cout << "adding one happy cow" << endl;
    return 1;
  } else if (neighborsNeighbor == 4) {
    // cout << "removing one happy cow" << endl;
    return -1;
  }
  return 0;
}

#ifndef TESTING
int main() {
  //   cout << INT_MAX << endl;
  //   // 2147483647
  //   cout << (1 << 31) << endl;
  // x, y 0..1000
  // packed_location = x + y * 1000;
  // x = packed_location % 1000
  // y = packed_location / 1000;
  // pair<int,int> packed_location;
  int n;
  cin >> n;
  int happyCows = 0;
  //  map<pair<int, int>, bool> cows;      // x,y = cow
  //  map<pair<int, int>, int> neighborz;  // x, y = neb
  map<int, bool> cows;      // x,y = cow
  map<int, int> neighborz;  // x, y = neb

  // pair<int, int> cord;
  int cord, x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    cord = pack(x, y);
    neighborz[cord] = neighbors(cows, cord);
    if (neighborz[cord] == 3) {
      happyCows++;
    }
    cows[cord] = true;
    int up = cord + (1 << 11);
    //        pack(getx(cord), gety(cord) + 1);  // {cord.first, cord.second +
    //        1};
    int down = cord - (1 << 11);
    // pack(getx(cord), gety(cord) - 1);
    int right = cord + 1;
    // pack(getx(cord) + 1, gety(cord));
    int left = cord - 1;
    // pack(getx(cord) - 1, gety(cord));
    neighborz[right]++;
    neighborz[left]++;
    neighborz[up]++;
    neighborz[down]++;
    if (cows[right] == true) {
      happyCows += neighborsNeighbor(neighborz[right]);
    }
    if (cows[left] == true) {
      happyCows += neighborsNeighbor(neighborz[left]);
    }
    if (cows[up] == true) {
      happyCows += neighborsNeighbor(neighborz[up]);
    }
    if (cows[down] == true) {
      happyCows += neighborsNeighbor(neighborz[down]);
    }
    cout << happyCows << endl;
  }
  return 0;
}
#endif