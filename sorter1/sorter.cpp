#include <iostream>
using namespace std;

bool done (int nums[], int n) {
    for (int i =0; i < n-1; i++){
        if (nums[i]> nums[i+1]){
            return false;
        } 
    }
    return true;
}

int main (){
    int n;
    cin >> n;
    int nums[n];
    for (int i =0; i < n; i++){
        cin >> nums[i];
    }
    bool swapHappened = true;
    while (swapHappened) { // (!done(nums, n)) {
        swapHappened = false;
        for (int i =0; i < n-1; i++){
            if (nums[i+1] < nums[i]){
                swapHappened = true;
                int j = nums[i+1];
                int k = nums[i];
                nums[i+1] = k;
                nums[i] = j;
            }
        }
    }
    // cout <<endl;
    for (int i =0; i < n; i++){
        cout << nums[i] << endl;
    }
    // cout << endl;
    return 0;
}