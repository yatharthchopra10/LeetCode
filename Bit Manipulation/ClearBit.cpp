#include<iostream>
using namespace std;

// Brute Force Solution -> convert the given number into its binary form and clear the bit.

// Optimal Solution -> Left Shift Operator and AND Operator
int clearBit(int n, int i){
    return (n & ~(1 << i));
}

int main(){
    int n, i;
    cin >> n >> i;
    cout << clearBit(n, i);
    return 0; 
}