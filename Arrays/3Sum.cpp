#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

// Brute Force Solution -> if unique triplets are needed then use set and not 2D array
// Time Complexity: O(N^3)
// Space Complexity: O(1)
vector<vector<int>> threeSumBrute(vector<int> &a){
    vector<vector<int>> res;
    int sum = 0;
    for(int i = 0; i < a.size(); i++){
        for(int j = i + 1; j < a.size(); j++){
            for(int k = j + 1; k < a.size(); k++){
                sum = a[i] + a[j] + a[k];
                if(sum == 0) res.push_back({i, j, k});
            }
            sum = 0;
        }
    }
    return res;
}

// Better Solution
// Time Complexity: O(N^2)
// Space Complexity: O(N)
vector<vector<int>> threeSumBetter(vector<int> &a){
    set<vector<int>> st;
    for(int i = 0; i < a.size(); i++){
        set<int> hashset;
        for(int j = i+1; j < a.size(); j++){
            int k = -(a[i] + a[j]);
            if(hashset.find(k) != hashset.end()){
                vector<int> temp = {i, j, k};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(a[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// Optimal Solution
// Time Complexity: O(N^2)
// Space Complexity: O(1)
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        
        int j = i + 1;
        int k = nums.size() - 1;

        while (j < k) {
            int total = nums[i] + nums[j] + nums[k];

            if (total > 0) k--;
            else if (total < 0) j++;
            else {
                res.push_back({nums[i], nums[j], nums[k]});
                j++;

                while (nums[j] == nums[j-1] && j < k) j++;
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