#include<iostream>
#include<set>
using namespace std;

// Brute Force Solution
// Time Complexity: O(N^2) -> we didn't consider the time complexity of the set operations because at max there can be only 3 elements in the set and log3 is nearly equal to 1 itself.
// Space Complexity: O(3)
int fruitBasketsBrute(vector<int> &a, int k){
    int maxi = 0;
    for(int i = 0; i < a.size(); i++){
        set<int> st;
        for(int j = i; j < a.size(); j++){
            st.insert(a[j]);
            if(st.size() <= k) maxi = max(maxi, j - i + 1);
            else break;
        }
    }
    return maxi;
}

// Better Solution
// Time Complexity: O(2N)
// Space Complexity: O(3)
int fruitBasketsBetter(vector<int> &a, int k){
    int maxi = 0;
    int l = 0;
    int r = 0;
    unordered_map<int, int> mpp;
    while(r < a.size()){
        mpp[a[r]]++;
        if(mpp.size() <= k) maxi = max(maxi, r - l + 1);
        else{
            while(mpp.size() > k){
                mpp[a[l]]--;
                if(mpp[a[l]] == 0) mpp.erase(a[l]);
                l++;
            }
        }
        r++;
    }
    return maxi;
}

// Optimal Solution
// Time Complexity: O(N)
// Space Complexity: O(3)
int fruitBaskets(vector<int> &a, int k){
    int maxi = 0;
    unordered_map<int, int> mpp;
    int l = 0;
    int r = 0;
    while(r < a.size()){
        mpp[a[r]]++;
        if(mpp.size() > k){
            mpp[a[l]]--;
            if(mpp[a[l]] == 0) mpp.erase(a[l]);
            l++;
        }
        if(mpp.size() <= k) maxi = max(maxi, l-r+1);
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
    cout << fruitBaskets(a, k);
    return 0;
}