#include<iostream>
using namespace std;

// Time Complexity: O(2K)
// Space Complexity: O(1)
int maximumPoints(vector<int> &a, int k){
    int lsum = 0;
    int rsum = 0;
    int r = a.size() - 1;
    int maxi = 0;
    for(int i = 0; i < k; i++){
        lsum += a[i];
    }
    for(int i = k - 1; i > 0; i--){
        lsum -= a[i];
        rsum += a[r];
        r--;
        maxi = max(maxi, lsum + rsum);
    }
    return maxi;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << maximumPoints(a, k);
    return 0;
}