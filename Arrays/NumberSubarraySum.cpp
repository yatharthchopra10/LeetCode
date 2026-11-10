#include<iostream>
using namespace std;

// Optimal Solution (Brute and Better Solutions in previous subarray problem)
// Time Complexity: O(N log N)
// Space Complexity: O()
int subarraySum(vector<int> &a, int k){
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int cnt = 0;
    int sum = 0;
    for(int i = 0; i < a.size(); i++){
        sum += a[i];
        int rem = sum - k;
        cnt += mpp[rem];
        mpp[sum]++;
    }
    return cnt;
}

int main(){
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int res = subarraySum(a, k);
    cout << res;
    return 0;
}