#include <iostream>
#include <vector>
#include <map>
using namespace std;


void movetractor(int& time, map<pair<int, int>, int> &field, 
                int& spaceBtwnRevisits, pair<int, int> fjposition);

int solve(vector <pair<char, int> > instructions) {
    map< pair<int, int>, int> field;
    int time =0;
    // time starts at 1, mow lawn then increment time
    pair<int, int> fjposition (0,0);
    int spaceBtwnRevisits = -1;
    field[fjposition] = time;

    for(int i =0;i < instructions.size();i++){
         cout << "moving tractor " <<instructions[i].first << " from (" << fjposition.first <<
                 ", " << fjposition.second << ") at time " << time << " to ("  ;


        switch(instructions[i].first){
            case 'N':{
                cout <<instructions[i].second << endl;
                for(int j =0; j < instructions[i].second; j++){
                    fjposition.second++;
                    movetractor(time, field, spaceBtwnRevisits, fjposition);
                }
                break;
            }
            case 'E': {
                for(int j =0; j < instructions[i].second; j++){
                    fjposition.first ++;
                    movetractor(time, field, spaceBtwnRevisits, fjposition);
                }
                break;
            }
            case 'S':{
                for(int j =0; j < instructions[i].second; j++){
                    fjposition.second --;
                    movetractor(time, field, spaceBtwnRevisits, fjposition);
                }
                break;
            }
            case 'W':{
                for(int j =0; j < instructions[i].second; j++){
                    fjposition.first --;
                    movetractor(time, field, spaceBtwnRevisits, fjposition);
                }
                break;
            }
            default: break;
        }

        cout << fjposition.first <<
                 ", " << fjposition.second << ") at time " << time << endl;
    }

    return spaceBtwnRevisits;
}

void movetractor(int& time, map<pair<int, int>, int> &field, 
                int& spaceBtwnRevisits, pair<int, int> fjposition){
    //time increments first
    
    time++;
    auto itr = field.find(fjposition);
    if (itr != field.end()){
        cout << "INTERSECTION at time " << time << " with time " << itr->second << endl;
        // if the spot has alr been mowed
        // isRevisit = true
        if ((time - itr->second) < spaceBtwnRevisits || spaceBtwnRevisits == -1){
            cout << "changing ans from " << spaceBtwnRevisits << " to " << time - itr->second << endl;
            // if the space in between is smaller than last one or if it is the first one
            spaceBtwnRevisits = time - itr->second; 
        }
    } 
    cout << "adding " << time << " to pos (" << 
    fjposition.first << ", " << fjposition.second << ")" << endl;
    field[fjposition] = time;
    
}
#ifndef TESTING
int main (){
    int n;
    vector< pair<char, int> > instructions;
    cin >> n;
    for (int i =0 ; i < n; i++){
        char c; int d;
        cin >> c >> d;
        instructions.push_back(make_pair(c,d));
    }
    cout << solve(instructions);
    return 0;
}
#endif