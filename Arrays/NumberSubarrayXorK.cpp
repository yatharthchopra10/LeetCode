#include<iostream>
using namespace std;

// Brute Force Solution
// Time Complexity: O(N^3) -> another for loop for calculating xor
// Space Complexity: O(1)

// Better Solution
// Time Complexity: O(N^2)
// Space Complexity: O(1)
int subarrayXorBetter(vector<int> &a, int k){
    int ans = 0;
    int count = 0;
    for(int i = 0; i < a.size(); i++){
        ans = 0;
        for(int j = i+1; j < a.size(); j++){
            ans = ans ^ (a[i] ^ a[j]);
            if(ans == k){
                count++;
            }
        }
    }
    return count;
}

// Optimal Solution
// Time Complexity: O(N log N)
// Space Complexity: O(N)
int subarrayXor(vector<int> &a, int k){
    unordered_map<int, int> mpp;
    int ans = 0;
    mpp[0] = 1;
    int count = 0;
    for(int i = 0; i < a.size(); i++){
        ans = ans ^ a[i];
        int x = ans ^ k;
        count += mpp[x];
        mpp[ans]++;
    }
    return count;
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int res = subarrayXor(a, k);
    cout << res;
    return 0;
}