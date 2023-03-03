#include <iostream>
#include <map>
#include <cmath>
#include <vector>
using namespace std;

int solve (int smallest, int greatest, vector< pair<char, int> > instructions, int numOfCows){
    // if (greatest < smallest){
    //     return min(lCount, gCount);
    // }

    int upperBoundExtras = 0;
    int lowerBoundExtras = 0;
    //index 0 correlates to smallest
    // greatest - smallest is last index, so size is last index+1
    vector<int> numberLine (greatest-smallest+1, 0);
    int greatestAgreed = 0;

    cout << "Bessie is between " << greatest << " and " << smallest << endl;

    //adding cows opinions to vector
    for (int k = 0; k < numOfCows; k++){
        if (instructions[k].first== 'G'){
            //add nothing if instructions[k].second > greatest bc out of bounds of number line
            if (instructions[k].second > greatest){
                upperBoundExtras++;
                cout << "cow  is out of upper bound at " << instructions[k].second 
                << ". upperBoundExtras is now "  << upperBoundExtras << endl ;
            } else {
                cout << "adding 1 to indexes from "<< instructions[k].second - smallest
                 <<" to the end(" <<  greatest - smallest << ") inclusive" << endl;
                //from the number they said to the end
                for (int j = instructions[k].second - smallest; j <= greatest - smallest; j++){
                    numberLine[j]++;
                    cout << "numberline[" << j << "] is now " << numberLine[j] << endl;
                }
            }
        } else if (instructions[k].first== 'L'){
            //when instructions[k].second < smallest it is out of bounds of number line
            if (instructions[k].second < smallest){
                lowerBoundExtras++;
                cout << "cow  is out of lower bound at " << instructions[k].second 
                << ". lowerBoundExtras is now "  << lowerBoundExtras << endl ;
            } else {
                cout << "adding 1 to indexes from " <<  instructions[k].second - smallest << " inclusive" << endl;
                //from the beginning to the number they said
                for (int j = 0; j <= instructions[k].second - smallest; j++){
                    numberLine[j]++;
                    cout << "numberline[" << j << "] is now " << numberLine[j] << endl;
                }
            }
        }
    }

    //finding the maximum possible num of cows that can agree;
    for (int i = 0; i < greatest-smallest+1; i++){
        greatestAgreed = max(greatestAgreed, numberLine[i]);
    }
    int outOfBounds = max(upperBoundExtras, lowerBoundExtras);
    //min cows lying = total cows - max cows telling truth
    return numOfCows - max(greatestAgreed, outOfBounds);
}

int main (){
    int n;
    cin >> n;
    int greatest = 0;
    int smallest = pow(10, 9);
    vector< pair<char, int> > instructions(n);
    
    //parse instructions
    for (int i = 0; i < n; i++){
        char c; int d;
        cin >> c >> d;
        //adds instructions to vector of instructions
        instructions[i] = make_pair(c,d);

        //finds range
        if (c == 'G'){
            smallest = min(smallest, d);
        } else {
            greatest = max(greatest, d);
        }
    }

    //print answer
    if (smallest == pow(10, 9) || greatest == 0){
        cout << 0;
    } else {
        cout << solve(smallest, greatest, instructions, n);
    }

    return 0;
} 