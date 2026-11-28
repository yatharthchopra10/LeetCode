#include<iostream>
using namespace std;

// Brute Force Solution
// Time Complexity: O(N^2)
// Space Complexity: O(26)
int longestCharReplaceBrute(string s, int k){
    int maxFreq = 0;
    int maxi = 0;
    for(int i = 0; i < s.size(); i++){
        int hash[26] = {0};
        for(int j = i; j < s.size(); j++){
            maxFreq = max(maxFreq, ++hash[s[j] - 'A']);
            int changes = (j - i + 1) - maxFreq;
            if(changes <= k) maxi = max(maxi, j - i + 1);
            else break;
        }
    }
    return maxi;
}

// Better Solution #1
// Time Complexity: (O(N) + O(N)) x 26
// Space Complexity: O(26)
int longestCharReplaceBetter(string s, int k){
    int maxFreq = 0;
    int maxi = 0;
    int hash[26] = {0};
    int l = 0;
    int r = 0;
    while(r < s.size()){
        maxFreq = max(maxFreq, ++hash[s[r] - 'A']);
        while((r-l+1) - maxFreq > k){
            hash[s[l] - 'A']--;
            maxFreq = 0;
            for(int i = 0; i < 26; i++){
                maxFreq = max(maxFreq, hash[i]);
                l++;
            }
        }
        if((r-l+1) <= k){
            maxi = max(maxi, (r-l+1));
        }
        r++;
    }
    return maxi;
}

// Better Solution #2 -> don't decrease the maximum frequency as it is reduntant, Dry Run and understand if any doubts.
// Time Complexity: O(N) + O(N)
// Space Complexity: O(26)
int longestCharReplaceBetterFinal(string s, int k){
    int maxFreq = 0;
    int maxi = 0;
    int hash[26] = {0};
    int l = 0;
    int r = 0;
    while(r < s.size()){
        maxFreq = max(maxFreq, ++hash[s[r] - 'A']);
        while((r-l+1) - maxFreq > k){
            hash[s[l] - 'A']--;
            l++;
        }
        if((r-l+1) <= k){
            maxi = max(maxi, (r-l+1));
        }
        r++;
    }
    return maxi;
}

// Optimal Solution
// Time Complexity: O(N)
// Space Complexity: O(26)
int longestCharReplace(string s, int k){
    int maxFreq = 0;
    int maxi = 0;
    int hash[26] = {0};
    int l = 0;
    int r = 0;
    while(r < s.size()){
        maxFreq = max(maxFreq, ++hash[s[r] - 'A']);
        if((r-l+1) - maxFreq > k){
            hash[s[l] - 'A']--;
            l++;
        }
        if((r-l+1) <= k) maxi = max(maxi, (r-l+1));
        r++;
    }
    return maxi;
}

int main(){
    string s;
    int k;
    cin >> s >> k;
    cout << longestCharReplace(s, k);
    return 0;
}