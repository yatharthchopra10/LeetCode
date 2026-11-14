#include<iostream>
using namespace std;

// Brute Force Solution -> convert the given number into its binary form and check there is exactly 1 set bit or not.

// Optimal Solution -> n & (n-1) == 0
bool powerTwo(int n){
    return (n & (n-1)) == 0;
}

int main(){
    int n;
    cin >> n;
    cout << powerTwo(n);
    return 0;
}