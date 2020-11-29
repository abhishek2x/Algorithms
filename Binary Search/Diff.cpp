/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){

    ios :: sync_with_stdio(false);
    cin.tie(0);

    vector<int> arr = {1,2 ,4, 5, 7, 8, 24, 43, 234};
    int k = 18; 
    int l=0, h=arr.size()-1, mid;
    while(l <= h){
        mid = l + (h-l)/2;
        if(arr[mid] == k){
            return arr[mid];
        } else if(arr[mid] < k){
            l = mid+1;
        } else {
            h = mid-1;
        }
    }

    // At this point, l > h**
    cout << l << " " << h << "\n";
    int high = arr[h];  // 24
    int low = arr[l]; // 8
    if(abs(k-low)<=abs(k-high)){
        cout << low;
    } else {
        cout << high;
    }
    // cout << low ? (abs(k-low)<=abs(k-high)) : high;
    return 0;
}