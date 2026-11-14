#include<iostream>
using namespace std;

// Time Complexity: O(N) + O(N log N)
// Space Complexity: O(1)
float shortestJobFirst(vector<int> &a){
    sort(a.begin(), a.end());
    int time = 0;
    float avg = 0;
    for(int i = 0; i < a.size(); i++){
        avg += time;
        time += a[i];
    }
    return avg/a.size();
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >>a[i];
    cout << shortestJobFirst(a);
    return 0;
}