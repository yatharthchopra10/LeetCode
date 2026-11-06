#include<iostream>
using namespace std;

// Brute Force Approach


// Optimal Solution
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int sum = (n*(n+1))/2;
    int res = 0;
    for(int i = 0; i<nums.size(); i++){
        res += nums[i];
    }
    return sum-res;
}