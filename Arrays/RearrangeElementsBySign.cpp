#include<iostream>
using namespace std;

// Brute Force Solution
// Time Complexity: O(2N)
// Space Complexity: O(1)
vector<int> rearrangeSignBrute(vector<int> &a){
    vector<int> pos;
    vector<int> neg;
    int posi = 0;
    int negi = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] >= 0){
            pos[posi] = a[i];
            posi++;
        }
        else{
            neg[negi] = a[i];
            negi++;
        }
    }
    posi = 0;
    negi = 0;

    for(int i = 0; i < a.size(); i++){
        if(i % 2 == 0){
            a[i] = pos[posi];
            posi++;
        }
        else{
            a[i] = neg[negi];
            negi++;
        }
    }
    return a;
}

// Optimal Solution
// Time Complexity: O(N)
// Space Complexity: O(N)
vector<int> rearrangeSign(vector<int> &a){
    vector<int> ans;
    int pos = 0;
    int neg = 1;
    for(int i = 0; i < a.size(); i++){
        if(a[i] >= 0) {
            ans[pos] = a[i];
            pos += 2;
        } else {
            ans[neg] = a[i];
            neg += 2;
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> res = rearrangeSign(a);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
}