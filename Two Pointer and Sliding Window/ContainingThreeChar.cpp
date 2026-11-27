#include<iostream>
using namespace std;

// Brute Force Solution -> find all the substrings and then count all the valid substrings
// Time Complexity: O(N^2)
// Space Complexity: O(1)

// Optimal Solution
// Time Complexity: O(N)
// Space Complexity: O(1)
int containThreeChar(string s){
    int lastSeen[3] = {-1, -1, -1};
    int count = 0;
    for(int i = 0; i < s.size(); i++){
        lastSeen[s[i] - 'a'] = i;
        // if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
        //     count += (1 + min(lastSeen[0] ,lastSeen[1], lastSeen[2]));
        // }
        count += (1 + min(lastSeen[0] ,lastSeen[1], lastSeen[2]));
    }
    return count;
}

int main(){
    string s;
    cin >> s;
    cout << containThreeChar(s);
    return 0;
}