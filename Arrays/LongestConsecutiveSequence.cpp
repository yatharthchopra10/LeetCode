#include<iostream>
#include<unordered_set>
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

// Better Solution
// Time Complexity: O(N logN) + O(N)
// Space Complexity: O(1)
int longestSuccessiveElementsBetter(vector<int> &a){
    int maxi = 0;
    int lastSmaller = INT_MIN;
    int count = 0;
    sort(a.begin(), a.end());
    for(int i = 0; i < a.size(); i++){
        if(lastSmaller != a[i] - 1){
            lastSmaller = a[i];
            count = 1;
        }
        else{
            count++;
        }
        maxi = max(maxi, count);
    }
}
// Optimal Solution
// Time Complexity: O(N) + O(N + N) -> The first O(N) for inserting each array element in the set and the next O(N + N) for finding the longest consecutive sequence.
// Space Complexity: O(N)
int longestSuccessiveElements(vector<int> &a){
    int maxi = 1;
    int count = 0;
    unordered_set<int> st;
    for(int i = 0; i < a.size(); i++) st.insert(a[i]);

    for(auto it : st){
        if(st.find(it - 1) == st.end()){
            int x = it;
            count = 1;
            while(st.find(x+1) != st.end()){
                x++;
                count++;
            }
            maxi = max(maxi, count);
        }
    }
    return maxi;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << longestSuccessiveElements(a);
    return 0;
}