#include<iostream>
#include<set>
using namespace std;

// Brute Force Solution
// Time Complexity: O(N^2) -> we didn't consider the time complexity of the set operations because at max there can be only 3 elements in the set and log3 is nearly equal to 1 itself.
// Space Complexity: O(3)
int fruitBasketsBrute(vector<int> &a){
    int maxi = 0;
    for(int i = 0; i < a.size(); i++){
        set<int> st;
        for(int j = i; j < a.size(); j++){
            st.insert(a[j]);
            if(st.size() <= 2) maxi = max(maxi, j - i + 1);
            else break;
        }
    }
    return maxi;
}

// Better Solution
// Time Complexity: O(2N)
// Space Complexity: O(3)
int fruitBasketsBetter(vector<int> &a){
    int maxi = 0;
    int l = 0;
    int r = 0;
    unordered_map<int, int> mpp;
    while(r < a.size()){
        mpp[a[r]]++;
        if(mpp.size() <= 2) maxi = max(maxi, r - l + 1);
        else{
            while(mpp.size() > 2){
                mpp[a[l]]--;
                if(mpp[a[l]] == 0) mpp.erase(a[l]);
                l++;
            }
        }
        r++;
    }
    return maxi;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << fruitBasketsBetter(a);
    return 0;
}