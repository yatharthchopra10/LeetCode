#include<iostream>
using namespace std;

// Optimal Solution(No Brute Force)
// Time Complexity: O(N)
// Space Complexity: O(1)
int singleNumber(vector<int>& nums) {
    int res = 0;
    for(int i = 0; i < nums.size(); i++){
        res ^= nums[i];
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i , n; i++){
        cin >> a[i];
    }
    cout << singleNumber(a);
    return 0;
}