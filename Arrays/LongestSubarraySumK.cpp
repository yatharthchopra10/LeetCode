#include<iostream>
using namespace std;

// Brute Force Solution
// Time Complexity: O(N^2)
// Space Complexity: O(1)
int longestSubarrayWithSumKBrute(vector<int> a, long long k){
    int n = a.size();
    int sum = a[0];
    int maxi = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            sum += a[j];
            if(sum == k){
                maxi = max(maxi, j - i + 1);
                break;
            }
        }
    }
}

// Better Solution -> Optimal Solution for Array containing negatives as well
int longestSubarrayWithSumKBetter(vector<int> a, long long k){
    
}

// Optimal Solution
// Time Complexity: O(N)
// Space Complexity: O(1)
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int i = 0;
    int j = 0;
    long long sum = a[0];
    int maxi = 0;
    int n = a.size();
    while(j < n){
        while(i <= j && sum > k){
            sum -= a[i];
            i++;
        }
        if(sum == k){
            maxi = max(maxi, j - i + 1);
        }
        j++;
        if(j < n) sum += a[j];
    }
    return maxi;
}

int main(){
    int n;
    cin >> n;
    long long k;
    cin >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << longestSubarrayWithSumK(a, k);
    return 0;
}