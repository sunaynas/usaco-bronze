#include <iostream>
#include <cmath>

using namespace std;
int findDistance(int farmerStartPos, int bessiePos) {
    int farmerPos = farmerStartPos;
    int dist = 0;
    int farmerPosChange =1;

    while (!((bessiePos >= farmerStartPos && farmerPos >= bessiePos) ||
     (bessiePos <= farmerStartPos && farmerPos <= bessiePos))){
        //1,2,4,8,16,31,64,128,256
        if ((int)sqrt(farmerPosChange)*(int)sqrt(farmerPosChange) == farmerPosChange){
            dist += abs(farmerStartPos - farmerPos) + farmerPosChange;
            farmerPos = farmerStartPos + farmerPosChange;
        } else {
            dist += abs(farmerStartPos - farmerPos) + farmerPosChange;
            farmerPos = farmerStartPos - farmerPosChange;
        }
        farmerPosChange = 2*farmerPosChange;
    }
    //cout << "FINAL DISTANCE IS " ;
    dist = dist- abs(farmerPos - bessiePos);
    return dist;
}
#ifndef TESTING
int main(){
    int farmerStartPos;
    int bessiePos;
    cin >> farmerStartPos >> bessiePos;
    cout << findDistance(farmerStartPos, bessiePos) << endl;
    return 0;
}
#endif
// cout << "adding dist by: " <<  abs(farmerStartPos - farmerPos) 
            // << " steps to starting pos plus " << farmerPosChange 
            // << " steps to new pos " << farmerStartPos + farmerPosChange << endl << "dist =" << dist << endl;
            // if (farmerStartPos + farmerPosChange >= 1000){
            //     cout << "farmer hits 1000 and has " << abs(1000 - farmerStartPos - farmerPosChange) 
            //     << " extra steps after being required to go " << farmerPosChange 
            //     << " steps from starting point " << farmerStartPos << endl;
            //     farmerPos = 1000;
            //     dist -= abs(1000 - farmerStartPos - farmerPosChange);
            //     cout << "dist =" << dist << endl; 
            // } else 


// cout << "adding dist by: " <<  abs(farmerStartPos - farmerPos) 
            // << " steps to starting pos plus " << farmerPosChange 
            // << " steps to new pos " << farmerStartPos - farmerPosChange << endl << "dist =" << dist << endl;
            // if (farmerStartPos - farmerPosChange <= 0){
            //     cout << "farmer hits 0 and has " << abs(farmerStartPos - farmerPosChange) 
            //     << " extra steps after being required to go " << farmerPosChange 
            //     << " steps from starting point " << farmerStartPos << endl;
            //     farmerPos = 0;
            //     dist -= abs(farmerStartPos - farmerPosChange);
            //     cout << "dist =" << dist << endl; 
            // } else 