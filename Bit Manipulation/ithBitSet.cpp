#include<iostream>
using namespace std;

// Brute Force -> convert the given number into binary form and check if the ith bit is set or not (set means bit is 1 and not set means bit is 0)

// Optimal Solution #1 -> Left Shift Operator
bool setOrNoSetLeft(int n, int i){
    if((n & 1 << i) != 0) return true;
    else return false;
}

// Optimal Solution #2 -> Right Shift Operator
bool setOrNoSetRight(int n, int i){
    if(((n >> i) & 1) == 0) return false;
    else return true;
}

int main(){
    int n, i;
    cin >> n >> i;
    cout << setOrNoSetLeft(n, i);
    cout << setOrNoSetRight(n, i);
    return 0;
}