#include<iostream>
using namespace std;

// Optimal Solution(No Brute Force)
// Time Complexity: O(n1 + n2)
// Space Complexity: O(n1 + n2)
vector<int> findUnion(vector<int> &a, vector<int> &b) {
    int i = 0;
    int j = 0;
    int n1 = a.size();
    int n2 = b.size();
    vector<int> res;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            if(res.size()==0 || res.back()!=a[i]){
                res.push_back(a[i]);
            }
            i++;
        }
        else{
            if(res.size()==0 || res.back()!=b[j]){
                res.push_back(b[j]);
            }
            j++;
        }
    }
    
    while(i<n1){
        if(res.size()==0 || res.back()!=a[i]){
            res.push_back(a[i]);
        }
        i++;
    }
    while(j<n2){
        if(res.size()==0 || res.back()!=b[j]){
            res.push_back(b[j]);
        }
        j++;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> a(n);
    for(int i = 0; i < a.size(); i++){
        cin >> a[i];
    }
    vector<int> b(n);
    for(int i = 0; i < b.size(); i++){
        cin >> b[i];
    }
    vector<int> ans = findUnion(a,b);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}