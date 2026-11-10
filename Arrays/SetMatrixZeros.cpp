#include<iostream>
using namespace std;

void markRow(vector<vector<int>> &a, int row){
    for(int j = 0; j < a[row].size(); j++){
        if(a[row][j] != 0) {
            a[row][j] = -1;
        }
    }
}

void markColumn(vector<vector<int>> &a, int col){
    for(int i = 0; i < a.size(); i++){
        if(a[i][col] != 0) {
            a[i][col] = -1;
        }
    }
}

// Brute Force Solution
// Time Complexity: O(N^3)
// Space Complexity: O(1)
vector<vector<int>> setMatrixZerosBrute(vector<vector<int>> &a){
    int n = a.size();
    int m = a[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 0){
                markRow(a, i);
                markColumn(a, j);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == -1){
                a[i][j] = 0;
            }
        }
    }
    return a;
}

// Better Solution
// Time Complexity: O(2N^2)
// Space complexity: O(N+M)
vector<vector<int>> setMatrixZerosBetter(vector<vector<int>> &a){
    vector<int> row(a.size(), 1);
    vector<int> col(a[0].size(), 1);

    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[i].size(); j++){
            if(a[i][j] == 0){
                row[i] = 0;
                col[j] = 0;
            }
        }
    }

    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[i].size(); j++){
            if(row[i] == 0){
                a[i][j] = 0;
            }
            else if(col[j] == 0){
                a[i][j] = 0;
            }
        }
    }
    return a;
}

// Optimal Solution -> Time Complexity can't be further optimized because it is a 2D array but Space Complexity can be further optimised by taking the row and column vector inside the matrix itself.
// Time Complexity: O(N^2)
// Space Complexity: O(1)
vector<vector<int>> setMatrixZeros(vector<vector<int>> &a){
    int col0 = 1;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[i].size(); j++){
            if(a[i][j] == 0){
                a[i][0] = 0;
                if(j != 0){
                    a[0][j] = 0;
                }
                else{
                    col0 = 0;
                }
            }
        }
    }

    for(int i = 1; i < a.size(); i++){
        for(int j = 1; j < a[i].size(); j++){
            if(a[i][j] != 0){
                if(a[0][j] == 0 || a[i][0] == 0){
                    a[i][j] = 0;
                }
            }
        }
    }

    if(a[0][0] == 0){
        for(int i = 0; i < a[0].size(); i++){
            a[0][i] = 0;
        }
    }

    if(col0 == 0){
        for(int i = 0; i < a.size(); i++){
            a[i][0] = 0;
        }
    }

    return a;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];
    vector<vector<int>> res = setMatrixZeros(a);
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cout << res[i][j];
    return 0;
}