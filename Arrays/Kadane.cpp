#include<iostream>
using namespace std;

// Brute Force Solution -> Same as Better Solution but for calculating sum we run another loop
// Time Complexity: O(N^3)
// Space Complexity: O(1)

// Better Solution -> calculate the sum within the j loop itself
// Time Complexity: O(N^2)
// Space Complexity: O(1)
int maxSubarraySumBetter(vector<int> &a){
    int sum = 0;
    int maxi = 0;
    int n = a.size();
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            sum += a[j];
            maxi = max(maxi, sum);
        }
        sum = 0;
    }
    return maxi;
}

// Kadane's Algorithm (Optimal Solution)
// Time Complexity: O(N)
// Space Complexity: O(1)
int maxSubarraySum(vector<int> &a){
    int sum = 0;
    int maxi = INT_MIN;
    
    for(int i = 0; i < a.size(); i++) {
        sum += a[i];
        maxi = max(maxi, sum);  // Did not make a separate if conditional block so that an array which has only negatives doesn't show an error as maxi will be -infinity.
        
        if (sum < 0) sum = 0;
    }
    
    return maxi;
}

// Additional Question: print the subarray with the maximum sum
// Time Complexity: O(N)
// Space Complexity: O(1)
int additionalSubarraySum(vector<int> &a){
    int sum = 0;
    int maxi = INT_MIN;
    int n = a.size();
    int ansStart = 0;
    int ansEnd = 0;
    int start = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
        if(sum == 0) start = i;

        if(sum < 0) sum = 0;
        else{
            maxi = max(maxi, sum);
            ansStart = start;
            ansEnd = i;
        }
    }
    return ansEnd - ansStart + 1;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << maxSubarraySum(a);
    return 0;
}