#include<iostream>
using namespace std;

// Brute Force Solution -> convert the given number into its binary number and remove the rightmost set bit.

// Optimal Solution -> Observing the binary form of the given number and the one preceeding it.
int removeSetBit(int n){
    return n & (n-1);
}

int main(){
    int n;
    cin >> n;
    cout << removeSetBit(n);
    return 0;
}