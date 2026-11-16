#include<iostream>
using namespace std;

// Constant Window
int constantWindow(vector<int> &a, int k){
    int sum = 0;
    int maxi = 0;
    int l = 0;
    int r = k-1;
    for(int i = l; i <= r; i++) sum += a[i];
    while(r < a.size() - 1){
        sum -= a[l];
        l++;
        r++;
        sum += a[r];
        maxi = max(maxi, sum);
    }
    return maxi;
}