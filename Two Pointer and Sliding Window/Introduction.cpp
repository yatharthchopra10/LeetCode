#include<iostream>
using namespace std;

// 1. Constant Window
// Time Complexity: O(2N)
// Space Compelxity: O(1)
int constantWindow(vector<int> &a, int k){
    int sum = 0;
    int maxi = 0;
    int l = 0;
    int r = k-1;
    for(int i = l; i <= r; i++) sum += a[i];
    while(r < a.size() - 1){
        sum -= a[l];
        l++;
        r++;
        sum += a[r];
        maxi = max(maxi, sum);
    }
    return maxi;
}

// 2. Longest Subarray/Substring with some condition
// Proceed with Brute Force -> Better -> Optimal
// Time Complexity for Brute Force is O(N^2), O(2N) for Better and O(N) for Optimal.
// Better Solution (Use two for loops for Brute Force Solution)
// Time Complexity: O(2N) -> it won't be O(N^2) because the inner loop is not running for N times, overall the outer loop runs for N times and the inner loop runs for N times overall.
// Space Complexity: O(1)
int subarraySum(vector<int> &a, int k){
    int l = 0;
    int r = 0;
    int sum = 0;
    int maxi = 0;
    while(r < a.size()){
        sum += a[r];
        while(sum > k){
            sum -= a[l];
            l++;
        }
        if(sum <= k) maxi = max(maxi, r-l+1);
        r++;
    }
    return maxi;
}

// Optimal Solution
// Time Complexity: O(N)
// Space Complexity: O(1)
int subarraySum(vector<int> &a, int k){
    int l = 0;
    int r = 0;
    int sum = 0;
    int maxi = 0;
    while(r < a.size()){
        sum += a[r];
        if(sum > k){
            sum -= a[l];
            l++;
        }
        if(sum <= k) maxi = max(maxi, r-l+1);
        r++;
    }
    return maxi;
}

// 3. Number of subarrays with some condition -> solved using question 2

// 4. Shortest/ Minimum window with some condition