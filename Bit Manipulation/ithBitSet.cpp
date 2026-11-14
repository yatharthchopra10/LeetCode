#include<iostream>
using namespace std;

// Brute Force -> convert the given number into binary form and check if the ith bit is set or not (set means bit is 1 and not set means bit is 0)

// Optimal Solution -> Shift Operator
bool setOrNoSet(int n, int i){
    int check = 1 << i;
    if((n & check) != 0) return true;
    else return false;
}

int main(){
    int n, i;
    cin >> n >> i;
    cout << setOrNoSet(n, i);
    return 0;
}