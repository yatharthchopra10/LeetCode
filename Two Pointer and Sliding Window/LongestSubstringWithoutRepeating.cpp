#include<iostream>
using namespace std;

// Time Complexity: O(N)
// Space Complexity: O(256) ~ O(1)
int longestSubstring(string s){
    vector<int> hash(256, -1);
    int l = 0;
    int r = 0;
    int maxi = 0;
    while(r < s.size()){
        if(hash[s[r]] != -1){
            if(hash[s[r]] >= l){
                l = hash[s[r]] + 1;
            }
        }
        hash[s[r]] = r;
        maxi = max(maxi, r-l+1);
        r++;
    }
    return maxi;
}

int main(){
    string s;
    cin >> s;
    cout << longestSubstring(s);
    return 0;
}