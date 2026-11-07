#include<iostream>
using namespace std;

// Brute Force Solution -> Merge Sort
// Time Complexity: O(N logN)
// Space Complexity: O(N)

// Better Solution
// Time Complexity: O(2N)
// Space Complexity: O(1)
void sortBetter(vector<int>& a){
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == 0) count0++;
        else if(a[i] == 1) count1++;
        else count2++;
    }
    for(int i = 0; i < count0; i++) a[i] = 0;
    for(int i = count0; i < count0 + count1; i++) a[i] = 1;
    for(int i = count0 + count1; i < count0 + count1 + count2; i++) a[i] = 2;

    for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
}

// Deutch National Flag Algorithm (Optimal Solution)
// Time Complexity: O(N)
// Space Complexity: O(1)
void sort(vector<int>& a){
    int n = a.size();
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while(mid <= high){
        if(a[mid] == 0){
            swap(a[mid],a[low]);
            low++;
            mid++;
        }
        else if(a[mid] == 1){
            mid++;
        }
        else{
            swap(a[mid], a[high]);
            high--;
        }
    }
    for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a);
}