#include<iostream>
using namespace std;

// Optimal Approach (No Brute)
void leftRotate(vector<int> &nums){
    int temp = nums[0];
    for(int i = 0; i < nums.size()-1; i++){
        nums[i] = nums[i+1];
    }
    nums[nums.size()-1]=temp;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < nums.size(); i++){
        cin >> nums[i];
    }
    leftRotate(nums);
    return 0;
}