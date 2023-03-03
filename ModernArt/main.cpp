#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int> > CV;

class Rect {
 public:
  int imin;
  int jmin;
  int imax;
  int jmax;
  int color;
};

bool findOverlap(Rect rect1, Rect rect2) {
  // returns if rect 2 is in rect 1
}

void findBound(CV &canvas, Rect &ret) {
  for (int i = 0; i < canvas.size(); i++) {
    for (int j = 0; j < canvas.size(); j++) {
      if (canvas[i][j] == ret.color) {
        ret.imax = max(ret.imax, i);
        ret.imin = min(ret.imin, i);
        ret.jmax = max(ret.jmax, j);
        ret.jmin = min(ret.jmin, j);
      }
    }
  }
}

int solve(CV &canvas) {
  // auto r = findFullRects(canvas, skipColor);
  vector<Rect> colors(10);
  for (int i = 1; i < 10; i++) {
    findBound(canvas, colors[i]);
  }

  for (int a = 1; a < 10; a++) {
    // for each color
    for (int b = 1; b < 10; b++) {
      if () {
      }
    }
  }
}

#ifndef TESTING
int main() {
  int n;
  cin >> n;
  // map<pair<int, int>, int> canvas;
  CV canvas(n);

  for (int i = 0; i < 0; i++) {
    canvas[i].resize(n);
    string line;
    cin >> line;
    for (int j = 0; j < n; j++) {
      // canvas[make_pair(i, j)] = color;
      canvas[i][j] = line[j];
    }
  }
  solve(canvas);
  return 0;
}
#endif