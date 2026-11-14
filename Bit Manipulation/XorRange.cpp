#include<iostream>
using namespace std;

int xorUptoN(int n){
    if(n % 4 == 1) return 1;
    else if(n % 4 == 2) return n+1;
    else if(n % 4 == 3) return 0;
    else return n;
}

int xorRange(int l, int r){
    return xorUptoN(l-1) ^ xorUptoN(r);
}

int main(){
    int l, r;
    cin >> l >> r;
    cout << xorRange(l, r);
    return 0;
}