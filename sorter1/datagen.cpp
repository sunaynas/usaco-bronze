#include <iostream>
#include <fstream>  
#include <cmath>
#include <vector>

using namespace std;

int randGen(int max) {
    return (floor(rand() * max));
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "Usages: datagen <fileName> <count>" << endl;
        return 1;
    }
    const string fname = string(argv[1]);
    const int count = atoi(argv[2]);
    ofstream inputFile(fname + ".input");
    ofstream outputFile(fname + ".output");
    inputFile << count << endl;

    vector<int> v;
    const int rMax = pow(2, 32);
    for(int i = 0 ; i < count; ++i) {
        int r =  randGen(rMax);
        inputFile << r << endl;
        v.push_back(r);
    }
    sort(v.begin(), v.end());
    for(int i : v)  {
        outputFile << i << endl;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}