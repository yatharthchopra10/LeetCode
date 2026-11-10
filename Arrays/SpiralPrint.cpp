#include<iostream>
using namespace std;

// Optimal Solution
// Time Complexity: O(N^2)
// Space Complexity: O(1)
void spiralPrint(vector<vector<int>> &a){
    int top, left = 0;
    int bottom = a.size() - 1;
    int right = a[0].size() - 1;
    while(top <= bottom && left <= right){
        for(int i = left; i <= right; i++){
            cout << a[top][i] << " ";
        }
        top++;
        for(int i = top; i <= bottom; i++){
            cout << a[i][right] << " ";
        }
        right--;
        if(top <= bottom){
            for(int i = right; i >= left; i--){
                cout << a[bottom][i] << " ";
            }
        }
        bottom--;
        if(left <= right){
            for(int i = bottom; i >= top; i++){
                cout << a[i][left] << " ";
            }
        }
        left++;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];
    spiralPrint(a);
    return 0;
}