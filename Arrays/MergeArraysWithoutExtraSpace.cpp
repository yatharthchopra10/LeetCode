#include<iostream>
#include<algorithm>
using namespace std;

void swapIfGreater(long long arr1[], long long arr2[], int idx1, int idx2){
    if(arr1[idx1] > arr2[idx2]){
        swap(arr1[idx1], arr2[idx2]);
    }
}

// Optimal Solution #1
// Time Complexity: O(min(N, M)) + O(N logN) + O(M logM)
// Space Complexity: O(1)
void mergeOptimal(long long arr1[], long long arr2[], int n, int m){
    int left = n - 1;
    int right = 0;
    while(left >= 0 && right < m){
        if(arr1[left] > arr2[right]){
            swap(arr1[left], arr2[right]);
            left--; right++;
        }
        else break;
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

// Optimal Solution #2 -> Inspired from Shell Sort which works on the principle of gaps.
// Time Complexity: O(log (n+m) * (n+m))
// Space Complexity: O(1) 
void mergeOptimalFinal(long long arr1[], long long arr2[], int n, int m){
    int len = n + m;
    int gap = len / 2 + len % 2;
    while(gap > 0){
        int left = 0;
        int right = left + gap;
        while(right < len){
            // arr1 and arr2
            if(left < n && right >= m){
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // arr2 and arr2
            else if(left >= n){
                swapIfGreater(arr1, arr2, left - n, right - n);
            }
            // arr1 and arr1
            else{
                swapIfGreater(arr1, arr2, left, right);
            }
            left++; right++;
        }
        if(gap == 1) break;
        gap = gap / 2 + gap % 2;
    }
}

int main(){
    // Take input and print the output accordingly.
    return 0;
}