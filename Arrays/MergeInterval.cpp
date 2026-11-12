#include<iostream>
#include<algorithm>
using namespace std;

// Brute Force Solution
// Time Complexity: O(N log N) + O(2N) -> Try to think why O(2N)
// Space Complexity: O(N)
vector<vector<int>> mergeIntervalBrute(vector<vector<int>> &a){
    sort(a.begin(), a.end());
    vector<vector<int>> ans;
    for(int i = 0; i < a.size(); i++){
        int start = a[i][0];
        int end = a[i][1];
        if(!ans.empty() && end <= ans.back()[1]) continue;

        for(int j = i+1; j < a.size(); j++){
            if(a[j][0] < end) end = max(end, a[i][1]);
            else break;
        }

        ans.push_back({start, end});
    }
    return ans;
}

// Optimal Solution
// Time Complexity: O(N log N) + O(N)
// Space Complexity: O(N)
vector<vector<int>> mergeInterval(vector<vector<int>> &a){
    sort(a.begin(), a.end());
    vector<vector<int>> ans;
    for(int i = 0; i < a.size(); i++){
        if(ans.empty() || a[i][0] > ans.back()[1]){
            ans.push_back(a[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1], a[i][0]);
        }
    }
    return ans;
}

int main(){
    int n;
    vector<vector<int>> a(n, vector<int>(2));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            cin >> a[i][j];
        }
    }
    vector<vector<int>> res = mergeInterval(a);
    for(int i = 0; i < res.size(); i++) for(int j = 0; j < res[i].size(); j++) cout << res[i][j] << " ";
    return 0;
}