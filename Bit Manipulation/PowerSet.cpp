#include<iostream>
using namespace std;

// Time Complexity: O(N * 2^N)
// Space Complexity: O(2^N * N) -> O(N) is approximate, it is never O(N) but taken approximately to be equal to O(N).
vector<vector<int>> powerSet(vector<int> &a){
    int n = a.size();
    int subsets = 1 << n;
    vector<vector<int>> ans;
    for(int num = 0; num < subsets; num++){
        vector<int> list;
        for(int i = 0; i < n; i++){
            if(num & (1 << i)){
                list.push_back(a[i]);
            }
        }
        ans.push_back(list);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> res = powerSet(a);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++) cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}