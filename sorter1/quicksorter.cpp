#include <iostream>
#include <vector>
using namespace std;
void qsort(int* num, int low, int high);

int main (){
    int n;
   // cout <<"INPUT COUNT" << endl;
    cin >> n;
    int nums[n];
    for (int i =0; i < n; i++){
        cin >> nums[i];
    } 
    //cout << "starting"<< endl;
    qsort(nums, 0, n);

    for (int i = 0; i< n; i++){
        cout << nums[i] << endl;
    }
    return 0;
}

//swaps two numbers stored in array 
void swap (int nums[], int a, int b){
    int tmpVal = nums[a];
    nums[a] = nums[b];
    nums[b]= tmpVal; 
}

//finds a pivot point for a section 
int pickpivot (int nums[], int start, int end){
    if (start == end-2){
        int a = nums[start];
        nums[start] = min(a, nums[end-1]);
        nums[end-1] = max(a, nums[end-1]);
        int n = end-start;
        int mid = start + n/2;
        return mid;
    } else {
        int n = end-start;
        int mid = start + n/2;
        int a = nums[start];
        int b = nums[mid];
        int c = nums[end-1];

        nums[start] = min(min(a, b), c);
        nums[end-1] = max(max(a, b), c);
        nums[mid] = a + b + c - (nums[start] + nums[end-1]);
        return mid;
    }
    
}

//given pivot point it puts the pivot in the right spot. 
//all nums before it are less, all after are greater
int sort (int nums[], int start, int end){

    int pivot = pickpivot(nums, start, end);
    if (pivot >= end || pivot < start){
        cout << "INVALID PIVOT POINT WHEN SORTING" << endl;
        return -100000;
    }
    int n = end-start;
    swap(nums, pivot, end - 1);
    pivot = end - 1;
    int left;
    int right;
    //cout <<" Sorter called with start="<< start<<" end="<<end<<endl;
    while (true){
        left = -1;
        right = -1;
        int count = start;
        while (left == -1 && count < end-1) {
            if (nums[count] > nums[pivot]) {
                left = count;
            } else {
                count ++;
            }
        }
        count = end-2;
        while (right == -1 && count >= start){
            if (nums[count] < nums[pivot]) {
                right = count;
                if(left>right){
                    swap(nums, left, pivot);
                    pivot = left;
                    return pivot;
                }
            } else {
                count --;
            }
        }
        if (left != -1 && right != -1) {
            swap(nums, left, right);
        } else {
            return pivot;
        }
    }
}

void qsort(int* num, int low, int high) {
    if (low < high) {
        int loc = sort(num, low, high);
        qsort(num, low, loc);
        qsort(num, loc + 1, high);
    }
}

