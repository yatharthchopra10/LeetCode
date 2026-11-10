#include<iostream>
#include<algorithm>
using namespace std;

// Brute Force Soluton
// Time Complexity: O(2N^2)
// Space Complexity: O(N)
vector<vector<int>> rotateMatrixBrute(vector<vector<int>> &a){
    int n = a.size();
    vector<vector<int>> b(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[j][n - 1 - i] = a[i][j];
        }
    }
    a = b;
    return a;
}

// Optimal Solution
// Time Complexity: O(N/2 * N/2)
// Space Complexity: O(N * N/2)
vector<vector<int>> rotateMatrix(vector<vector<int>> &a){
    for(int i = 0; i < a.size(); i++){
        for(int j = i + 1; j < a[i].size(); j++){
            swap(a[i][j], a[j][i]);
        }
    }

    for(int i = 0; i < a.size(); i++){
        reverse(a[i].begin(), a[i].end());
    }

    return a;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];
    vector<vector<int>> res = rotateMatrix(a);
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cout << res[i][j];
    return 0;
}