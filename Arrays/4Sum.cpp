#include<iostream>
using namespace std;

// Brute force Solution and Better Solution similar to 3 Sum problem

// Optimal Solution
// Time Complexity: O(N^3)
// Space Complexity: O(1)
vector<vector<int>> fourSum(vector<int> &a, int target){
    vector<vector<int>> ans;
    sort(a.begin(), a.end());
    for(int i = 0; i < a.size(); i++){
        if(i > 0 && a[i] == a[i-1]) continue;
        for(int j = i+1; j < a.size(); j++){
            if(j != i + 1 && a[j] == a[j-1]) continue;
            int k = j+1;
            int l = a.size() - 1;

            while (k < l){
                long long sum = a[i] + a[j] + a[k] + a[l];
                if(sum > target) l--;
                else if(sum < target) k++;
                else{
                    ans.push_back({a[i], a[j], a[k], a[l]});
                    k++; l--;

                    while(a[k] == a[k-1] && k < l){
                        k++;
                    }

                    while(a[l] == a[l+1] && k < l){
                        l--;
                    }
                }
            }
        }
    }
    return ans;
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> res = fourSum(a, k);
    for(int i = 0; i < res.size(); i++) for(int j = 0; j < res[i].size(); j++) cout << res[i][j];
    return 0;
}