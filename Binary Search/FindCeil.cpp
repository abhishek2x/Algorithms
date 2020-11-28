/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){

    ios :: sync_with_stdio(false);
    cin.tie(0);

    vector<int> arr = {1, 2, 3, 4, 7, 10, 14};
    int f = 5;
    int res;

    int l=0, h=arr.size()-1, mid;
    while(l <= h){
        mid = l + (h-l)/2;
        // cout << l << " " << h << " " << arr[mid] << "\n";
        if(f <= arr[mid]){
            res = arr[mid];
            h = mid-1;
        }
        else {
            l = mid+1;
        }
    }

    cout << res << "\n";

    return 0;
}