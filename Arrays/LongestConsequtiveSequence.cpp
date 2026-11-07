#include<iostream>
using namespace std;

// Brute Force Solution
// Time Complexity: O(N^2)
// space Complexity: O(1)
bool linearSearch(const vector<int>& arr, int num) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == num) return true;
    }
    return false;
}

int longestSuccessiveElementsBrute(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;

    int longest = 1;

    for (int i = 0; i < n; i++) {
        int x = arr[i];
        int count = 1;

        while (linearSearch(arr, x + 1) == true) {
            x = x + 1;
            count = count + 1;
        }

        longest = max(longest, count);
    }

    return longest;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << longestSuccessiveElementsBrute(a);
    return 0;
}