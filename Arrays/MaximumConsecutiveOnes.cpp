#include<iostream>
using namespace std;

// Optimal Solution(No Brute Force)
// Time Complexity: O(N)
// Space Complexity: O(1)
int consequtiveOnes(vector<int> &nums){
    int count = 0;
    int maxi = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i]==1){
            count++;
            maxi = max(maxi, count);
        }
        else{
            count = 0;
            break;
        }
    }
    return maxi;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> n;
    }
    cout << consequtiveOnes(nums);
    return 0;
}