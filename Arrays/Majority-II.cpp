#include<iostream>
using namespace std;

// Brute Force Solution
// Time Complexity: O(N^2)
// Space complexity: O(1)
vector<int> majorityBrute(vector<int> &a){
    int count = 0;
    vector<int> ans(2);
    for(int i = 0; i < a.size(); i++){
        if(ans.size() == 0 || a[0] != a[i]){
            for(int j = 0; j < a.size(); j++){
                if(a[i] == a[j]){
                    count++;
                }
            }
            if(count>(a.size()/3)){
                ans.push_back(a[i]);
            }
        }
        count = 0;
        if(ans.size() == 2) break;
    }
    return ans;
}

// Better Solution
// Time Complexity: O(N log N)
// Space Complexity: O(N)
vector<int> majorityBetter(vector<int> &a){
    unordered_map<int, int> mpp;
    int min = a.size()/3;
    vector<int> ans;
    for(int i = 0; i < a.size(); i++){
        if(ans.size() == 2) break;
        mpp[a[i]]++;
        if(mpp[a[i]]>min){
            ans.push_back(a[i]);
        }
    }
    return ans;
}

// Optimal Solution
// Time Complexity: O(2N)
// Space Complexity: O(1)
vector<int> majority(vector<int> &a){
    int count1 = 0;
    int count2 = 0;
    int el1 = a[0];
    int el2 = a[0];
    vector<int> ans;
    for(int i = 0; i < a.size(); i++){
        if(count1 == 0 && a[i] != el2){
            el1 = a[i];
            count1 = 1;
        }
        else if(count2 == 0 && a[i] != el1){
            el2 = a[i];
            count2 = 1;
        }
        else if(a[i] == el1) count1++;
        else if(a[i] == el2) count2++;
        else{
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == el1) count1++;
        else if(a[i] == el2) count2++;
    }

    if(count1 > a.size()/3) ans.push_back(el1);
    if(count2 > a.size()/3) ans.push_back(el2);

    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> ans = majority(a);
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}