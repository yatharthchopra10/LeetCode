#include<iostream>
using namespace std;

// Question 1 -> Given the row and column, print the element => (R-1) C (C-1)
// Question 2 -> Given the row, print the entire row
// Question 3 -> Given the row, print the entire triangle till that row.


// Question 1
// Time Complexity: O(r)
// Space Complexity: O(1)
int generateElement(int n, int r){
    long long res = 1;
    for(int i = 0; i < r; i++){
        res *= (n - i);
        res /= i + 1;
    }
    return res;
}

// Question 2
// Time Complexity: O(N)
// Space Complexity: O(1) -> vector used for storing array and not for performing calculations.
vector<int> generateRow(int n){
    vector<int> ans;
    long long res = 1;
    ans.push_back(1);
    for(int i = 1; i < n; i++){
        res = res * (n - i)/i;
        ans.push_back(res);
    }
    return ans;
}

// Question 3
// Time Complecity: O(N^2)
// Space Complexity: O(1) -> vector used to store array and not for performing calculations
vector<vector<int>> generateTriangle(int n){
    vector<vector<int>> ans;
    for(int i = 1; i <= n; i++){
        ans.push_back(generateRow(i));
    }
    return ans;
}

int main(){
    int r, c;
    cin >> r >> c;
    cout << generateElement(r-1, c-1);
    vector<int> res = generateRow(r);
    for(int i = 0; i < res.size(); i++) cout << res[i];
    vector<vector<int>> ans = generateTriangle(r);
    for(int i = 0; i < ans.size(); i++) for(int j = 0; j < ans[i].size(); j++) cout << ans[i][j];
    return 0;
}