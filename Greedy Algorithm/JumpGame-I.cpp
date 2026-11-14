#include<iostream>
using namespace std;

// Time Complexity: O(N)
// Space Complexity: O(1)
bool jumpGame(vector<int> &a){
    int maxIdx = 0;
    for(int i = 0; i < a.size(); i++){
        if(i > maxIdx) return false;
        maxIdx = max(maxIdx, i + a[i]);
        if(maxIdx >= a.size()) break;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << jumpGame(a);
    return 0;
}