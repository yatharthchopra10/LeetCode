#include<iostream>
using namespace std;

// Brute Force Solution
// Time Complexity: ~ O(N^2)
// Space Complexity: O(N) -> Extra space is used but for storing the answer and not for doing any calculations.
vector<int> leadersBrute(vector<int> &a){
    vector<int> ans;
    int neg = -1;
    for(int i = 0; i < a.size(); i++){
        for(int j = i+1; j < a.size(); j++){
            if(a[i]<a[j]) {
                neg = 0;
                break;
            }
        }
        if(neg == -1) {
            ans.push_back(a[i]);
        }
    }
    return ans;
}

// Optimal Solution
vector<int> leaders(vector<int> &a){
    int maxi = INT_MIN;
    vector<int> ans;
    for(int i = a.size() - 1; i >= 0; i--){
        if (a[i] >= maxi) ans.push_back(a[i]);
        maxi = max(maxi, a[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> res = leaders(a);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}