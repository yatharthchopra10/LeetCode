#include<iostream>
using namespace std;

// Optimal Solution
// Time Complexity: O(N^2)
// Space Complexity: O(1)
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        
        int j = i + 1;
        int k = nums.size() - 1;

        while (j < k) {
            int total = nums[i] + nums[j] + nums[k];

            if (total > 0) {
                k--;
            } else if (total < 0) {
                j++;
            } else {
                res.push_back({nums[i], nums[j], nums[k]});
                j++;

                while (nums[j] == nums[j-1] && j < k) {
                    j++;
                }
            }
        }
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i , n; i++) cin >> a[i];
    vector<vector<int>> res = threeSum(a);
    for (auto triplet : res) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "\n";
    }
}