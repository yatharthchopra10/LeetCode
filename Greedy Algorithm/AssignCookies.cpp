#include<iostream>
using namespace std;

// Time Complexity: O(N logN + M logM + M)
// Space Complexity: O(1)
int assignCookies(vector<int> &greed, vector<int> &child){
    int n = greed.size();
    int m = child.size();
    int l = 0;
    int r = 0;
    sort(greed.begin(), greed.end());
    sort(child.begin(), child.end());
    while(l < m && r < n){
        if(greed[r] <= child[l]){
            r += 1;
        }
        l += 1;
    }
    return r;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> greed(n);
    for(int i = 0; i < n; i++) cin >> greed[i];
    vector<int> child(m);
    for(int i = 0; i < m; i++) cin >> child[i];
    int ans = assignCookies(greed, child);
    cout << ans;
    return 0;
}