#include <bits/stdc++.h>
using namespace std;

#ifndef TESTING
int check(int summative, int firstIndex, vector<int> times){
  int swaps= 0;
  //cout << "calling check function to check if general sum " << summative
    //   << " will work" << endl;
  // index+1 is the number of items
  //  since you are merging you subtract 1 so just index
  swaps += firstIndex;
  //cout << "adding " << firstIndex << " swaps for first instance of sum";
  int getToSummative = 0;
  int index = firstIndex +1 ;
  for (int i = firstIndex + 1; i < times.size(); i++) {
    getToSummative += times[i];
    //cout << "index is " << i << " and count to sum is " << getToSummative <<
      //  endl;
    if (getToSummative > summative) {
      //cout << "the sum " << summative << " does not work " << endl;
      return -1;
    } else if (getToSummative == summative) {
      getToSummative = 0;
      //cout << "adding swaps necessary to combine indexes " << index << " to " << i << endl;
      swaps += (i - index);
      index = i + 1;
    }
    }
    if (getToSummative != 0){
    //cout << "FINAL SWAPS = total bc it merged to 1 " << endl << endl << endl;
    return times.size() - 1;
    }
    //cout << "FINAL SWAPS = " << swaps << endl << endl << endl;
    return swaps;
}

int solve(vector<int> times){
    int max = *max_element(times.begin(), times.end());
    //cout <<endl << " max val is " << max << endl;
    int potentialMid = 0;
    int potentialValIndex;
    for (int i = 0; i<times.size(); i++) {
      potentialMid += times[i];
      //cout << "potential mid is " << potentialMid << endl;
      if (potentialMid>= max){
        //cout << "potential mid " << potentialMid 
       // <<  " is now greater than the max at index " 
        //<< i << endl;
        int answ = check(potentialMid, i, times);
        if (answ != -1) {
          return answ;
        }
      }
    }
}

int main() {
  int testCases;
  cin >> testCases;
  for (int n=0; n < testCases; n++){
    int p;
    cin >> p;
    vector<int> times(p);
    for (int l = 0; l < p; l++) {
      int num;
      cin >> num;
      times[l] = num;
    }
    cout <<solve(times) << endl; 
  }
    return 0;
}
#endif