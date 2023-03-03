#include <bits/stdc++.h>
using namespace std;
int tracklen;

int solve(int maxSpd) {
  //   int time = 0;
  //   int speed = 0;
  int reachedSpd = ceil((1.0 * maxSpd * maxSpd) / 2.0);
  cout << "reach max speed at d = " << reachedSpd << " mx spd = " << maxSpd
       << endl;
  if (reachedSpd >= tracklen) {
    cout << "never reach max spd" << endl;
    // find speed at which it first passes track len
    return ceil((double)sqrt(2 * tracklen));
  }
  // have to have
  int a = -maxSpd + sqrt(pow(maxSpd, 2) + (tracklen - reachedSpd) / 2);
  if ((maxSpd + a) * (maxSpd + a / 2) + a * a / 2 < tracklen) {
    return maxSpd + 2 * a + 1;
  }
  return maxSpd + 2 * a +
         ceil(tracklen -
              ((maxSpd + a) * (maxSpd + a / 2) + a * a / 2) / maxSpd);
}

#ifndef TESTING
int main() {
  int n, X;
  cin >> tracklen >> n;
  for (int i = 0; i < n; i++) {
    cin >> X;
    cout << solve(X) << endl;
  }
  return 0;
}
#endif