#include<iostream>
using namespace std;

// Brute Force Approach


// Optimal Solution
// Time Complexity: O(N)
// Space Complexity: O(1)
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int sum = (n*(n+1))/2;
    int res = 0;
    for(int i = 0; i<nums.size(); i++){
        res += nums[i];
    }
    return sum-res;
}

int main(){
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = missingNumber(a);
    cout << ans;
    return 0;
}