#include<iostream>
using namespace std;

// Optimal Solution (No Brute Force)
// Time Complexity: O(2N logN + n1 + n2)
// Spoace Complexity: O(n1+n2)
vector<int> intersection(vector<int>& a, vector<int>& b) {
    int i = 0;
    int j = 0;
    int n1 = a.size();
    int n2 = b.size();
    vector<int> res;
    sort(a.begin(), a.end());
    sort(b.begin(),b.end());
    while(i<n1 && j<n2){
        if(a[i]==b[j]){
            if(res.size() == 0 || res.back()!=a[i]){
                res.push_back(a[i]);
            }
            i++;
            j++;
        }
        else if(a[i]<b[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    vector<int> res = intersection(a, b);
    for(auto num: res){
        cout << num << " ";
    }
    return 0;
}