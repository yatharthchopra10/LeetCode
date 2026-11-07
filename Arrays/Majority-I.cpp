#include<iostream>
#include<map>
using namespace std;

// Brute Force Solution
// Time Complexity: O(N^2)
// Space Complexity: O(1)
int majorityBrute(vector<int>& a){
    int n = a.size();
    int count = 0;
    int store = 0;
    for(int i = 0; i < n; i++){
        store = a[i];
        for(int j = 0; j < n; j++){
            if(a[j] == store){
                count++;
            }
        }
        if(count > n/2){
            break;
        }
    }
    return store;
}

// Better Solutioin -> Hashing
// Time Complexity: O(N logN + N) -> N log N for storing in the hash map and N for traversing in it.
// Space Complexity: O(N)
int majorityBetter(vector<int>& a){
    int n = a.size();
    map<int, int> mpp;
    for(int i = 0; i < n; i++){
        mpp[a[i]]++;
    }

    for(auto it : mpp){
        if(it.second > n/2){
            return it.first;
        }
    }
}

// Moore's Voting Algorithm (Optimal Solution)
// Time Complexity: O(N) + O(N) {The secong O(N) will not take place if the problem states that there is always a majority element.}
// Space Complexity: O(1)
int majority(vector<int>& a){
    int el;
    int count = 0;
    int n = a.size();
    int check = 0;
    for (int i = 0; i < n; i++) {
        if (count == 0){
            el = a[i];
            count = 1;
        }
        else if (a[i] == el){
            count++;
        }
        else{
            count--;
        }
    }
    for(int i = 0; i < n; i++){
        if(el == a[i]) check++;
    }
    if(check > n/2){
        return el;
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << majority(a);
    return 0;
}