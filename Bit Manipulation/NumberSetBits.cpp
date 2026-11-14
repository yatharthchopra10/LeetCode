#include<iostream>
using namespace std;

// Solution using normal Arithmetic Operators
int numberSetBitsArithmetic(int n){
    int count = 0;
    while(n > 1) {
        if(n % 2 == 1) count++;
        n /= 2;
    }
    if (n == 1) count++;
    return count;
}

// Solution using Bit Manipulatio for finding odd numbers and for dividing a number.
// Time Complexity: O(log N with base 2)
int numberSetBitsProper(int n){
    int count = 0;
    while (n > 1){
        count += n & 1;
        n = n >> 1;
    }
    if(n == 1) count++;
    return count;
}

// Another Solution using Bit Manipulation using & Operator -> Better Approach than the previous one due to its time complexity.
// Time Complexity: O(no. of set bits)
int numberSetBitsFinal(int n){
    int count = 0;
    while(n != 0){
        n = n & (n-1);
        count++;
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    cout << numberSetBitsArithmetic(n);
    return 0;
}

/**
 * ! IMPORTANT LEARNINGS FROM THIS PROBLEM OF BIT MANIPULATION

 * * 1. For checking if a number is odd or even we can use & operator -> n & 1 returns 1 if the number is odd and 0 if it is even because the rightmost bit of any odd number is always 1 and that for an even number, it is always 0.
 * * 2. For dividing any number by 2 we can use right shift operator and for multiplying we can use left shift operator.
 * * 3. In most of the competitive programming solutions, we will find the use of bitwise operators in many questions as it makes the runtime faster and simplifies the work for a compiler, therefore adapting towards using bit manipulation is very essential in competitive programming. For example, in the binary search algorithm, we do (low + high)/2 but instead of this we can use (low + high) >> 1.
 * * 4. Built-in function to count the number of set bits: --builtin_popcount(n)

**/