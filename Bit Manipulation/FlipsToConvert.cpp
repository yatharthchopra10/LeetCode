#include<iostream>
using namespace std;

int flipsToConvert(int start, int goal){
    int ans = start ^ goal;
    int count = 0;
    while(ans != 0){
        if(ans & 1) count++;
        ans >>= 1;
    }
    return count;
}

int main(){
    int start, goal;
    cin >> start >> goal;
    cout << flipsToConvert(start, goal);
    return 0;
}