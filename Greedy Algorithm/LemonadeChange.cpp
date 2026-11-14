#include<iostream>
using namespace std;

// Time Complexity: O(N)
// Space Complexity: O(1)
bool lemonadeChange(vector<int> &a){
    int five = 0;
    int ten = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == 5){
            five++;
        }
        else if(a[i] == 10){
            if(five){
                ten++;
                five--;
            }
            else return false;
        }
        else{
            if(ten & five){
                ten--;
                five--;
            }
            else if(five >= 3){
                five -= 3;
            }
            else return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << lemonadeChange(a);
    return 0;
}