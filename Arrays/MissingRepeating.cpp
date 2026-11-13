#include<iostream>
using namespace std;

// Brute Force Solution
// Time Complexity: O(N^2)
// Space Complexity: O(1)
vector<int> missingRepeatingBrute(vector<int> &a){
    int count = 0;
    int missing = -1;
    int repeating = -1;
    vector<int> ans;
    for(int i = 0; i < a.size(); i++){
        count = 0;
        for(int j = 0; j < a.size(); j++){
            if(a[j] == i){
                count++;
            }
        }
        if(count == 2) repeating = i;
        if(count == 0) missing = i;

        if(repeating != -1 && missing != -1) break;
    }
    ans.push_back(missing);
    ans.push_back(repeating);
    return ans;
}

// Better Solution
// Time Complexity: O(2N)
// Space Complexity: O(1)
vector<int> missingRepeatingBetter(vector<int> &a){
    int n = a.size();
    vector<int> hash(n+1, 0);
    int missing = -1;
    int repeating = -1;
    vector<int> ans;
    for(int i = 0; i < n; i++) hash[a[i]]++;

    for(int i = 1; i <= n; i++){
        if(hash[i] == 2) repeating = i;
        else if(hash[i] == 0) missing = i;

        if(missing != -1 && repeating != -1) break;
    }

    ans.push_back(missing);
    ans.push_back(repeating);
    return ans;
}

// Optimal Solution #1 -> using Maths
// Time Complexity: O(N)
// Space Complexity: O(1)
vector<int> missingRepeatingOptimal(vector<int> &a){
    vector<int> ans;
    long long n = a.size();
    long long sn = n*(n=1)/2;
    long long s2n = n*(n+1)*(2*n+1)/6;
    long long s = 0, s2 = 0;
    for(int i = 0; i < a.size(); i++){
        s += (long long)a[i];
        s2 += (long long)a[i] * (long long)a[i];
    }
    long long val1 = s - sn;
    long long val2 = s2 - s2n;
    long long x = (val1+val2)/2;
    long long y = x - val1;
    ans.push_back(x);
    ans.push_back(y);
    return ans;
}

// Optimal Solution #2 -> Using Xor
vector<int> missingRepeatingOptimalFinal(vector<int> &a){
    
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> res = missingRepeatingOptimal(a);
    for(int i = 0; i < res.size(); i++) cout << res[i];
    return 0;
}