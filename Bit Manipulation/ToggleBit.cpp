#include<iostream>
using namespace std;

// Brute Force Solution -> convert the given number into its binary form and toggle the respective bit.

// Optimal Solution -> Left Shift Operator and XOR Operator
int toggleBit(int n, int i){
    return n ^ (1 << i);
}

int main(){
    int n, i;
    cin >> n >> i;
    cout << toggleBit(n, i);
    return 0;
}