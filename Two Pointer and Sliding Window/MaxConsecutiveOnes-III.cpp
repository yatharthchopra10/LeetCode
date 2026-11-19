#include<iostream>
using namespace std;

// Brute Force Solution
// Time Complexity: O(N^2)
// Space Complexity: O(1)
int maxConsecutiveBrute(vector<int> &a, int k){
    int maxi = 0;
    for(int i = 0; i < a.size(); i++){
        int zero = 0;
        for(int j = i; j < a.size(); j++){
            if(a[j] == 0) zero++;
            if(zero <= k) maxi = max(maxi, j-i+1);
            else break;
        }
    }
    return maxi;
}

// Better Solution
// Time Complexity: O(2N)
// Space Complexity: O(1)
int maxCosecutiveBetter(vector<int> &a, int k){
    int maxi = 0;
    int l = 0;
    int zero = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == 0) zero++;
        if(zero <= k) maxi = max(maxi, i - l + 1);
        else{
            while(zero > k){
                if(a[l] == 0) zero--;
                l++;
            }
        }
    }
    return maxi;
}

// Optimal Solution
// Time Complexity: O(N)
// Space Complexity: O(1)
int maxConsecutive(vector<int> &a, int k){
    int maxi = 0;
    int l = 0;
    int r = 0;
    int zero = 0;
    while(r < a.size()){
        if(a[r] == 0) zero++;
        if(zero > k){
            if(a[l] == 0) zero--;
            l++;
        }
        if(zero <= k) maxi = max(maxi, r - l + 1);
        r++;
    }
    return maxi;
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << maxConsecutiveBrute(a, k);
    return 0;
}