#include<iostream>
using namespace std;

// Time Complexity: O((log N  base 2)^2)
// Space Complexity: O(1)
int divideIntegers(int dividend, int divisor){
    if(dividend == divisor) return 1;
    bool sign = true;
    if(dividend >= 0 && divisor < 0) sign = false;
    if(dividend < 0 && divisor > 0) sign = false;

    int n = abs(dividend); int d = abs(divisor);
    int ans = 0;
    while(n >= d){
        int count = 0;
        while(n >= (d << (count + 1))) count++;
        ans += 1 << count;
        n = n - (d * (1 << count));
    }

    if(ans >= (1 << 31) && sign == true) return INT_MAX;
    if(ans >= (1 << 31) && sign == false) return INT_MIN;
    return sign ? ans : (-1*ans);
}

int main(){
    int dividend, divisor;
    cin >> dividend >> divisor;
    cout << divideIntegers(dividend, divisor);
    return 0;
}