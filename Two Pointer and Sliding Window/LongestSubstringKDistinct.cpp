#include<iostream>
using namespace std;

// Brute Force Solution -> Find each substring and then find the longest substring with k distinct characters
// Time Complexity: O(N^2) x log(256) -> log 256 will depend on the type of input the user provides.
// Space Complexity: O(256)

// Better Solution -> similar to Fruit Baskets and MAx COnsecutive Ones - III
// Time Complexity: O(2N)
// Space Complexity: O(256)

// Optimal Solution
// Time Complexity: O(N)
// Space Complexity: O(256)
int longestSubstring(string s, int k){
    unordered_map<char, int> mpp;
    int maxi = -1;
    int l = 0;
    int r = 0;
    while(r < s.size()){
        mpp[s[r]]++;
        if(mpp.size() > k){
            mpp[s[l]]--;
            if(mpp[s[l]] == 0) mpp.erase(s[l]);
            l++;
        }
        if(mpp.size() == k) maxi = max(maxi, r-l+1);
        r++;
    }
    return maxi;
}

int main(){
    int k;
    cin >> k;
    string s;
    cin >> s;
    cout << longestSubstring(s, k);
    return 0;
}