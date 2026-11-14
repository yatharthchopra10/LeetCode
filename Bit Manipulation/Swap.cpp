#include<iostream>
using namespace std;

// This method uses extra space to swap 2 numbers
void swapTemp(int a, int b){
    int temp = a;
    a = b;
    b = temp;
    cout << a << " " << b;
}

void swap(int a, int b){
    a = a ^ b;
    b = a ^ b; // b = a ^ b but a = a ^ b in the previous line => b = (a ^ b) ^ b = a, => b = a
    a = a ^ b; // a = a ^ b but b = a and a = a ^ b in the previous steps => a = (a ^ b) ^ a, => a = b
    // Hence a = b and b = a.
    cout << a << " " << b;
}

int main(){
    int a;
    int b;
    cin >> a >> b;
    swap(a, b);
    return 0;
}