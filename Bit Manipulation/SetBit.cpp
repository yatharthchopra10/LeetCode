#include<iostream>
using namespace std;

// Brute Force Solution -> convert the given number into its binary form and change the bit to 1.

// Optimal Solution -> Left Shift Operator and OR Operator
int setBit(int n, int i){
    return (n | (1 << i));
}

int main(){
    int n, i;
    cin >> n >> i;
    cout << setBit(n, i);
    return 0;
}