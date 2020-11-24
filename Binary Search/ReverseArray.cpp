/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){

    ios :: sync_with_stdio(false);
    cin.tie(0);

    vector<int> v = {9, 7, 5, 3 , 2};
    int l, r, mid, x=7;
    l = 0;
    r = v.size()-1;

    while(l<=r){
        mid = (r+l)/2;
        // cout << l << " " << r << " " << v[mid] << " " << x << "\n";
        if(v[mid] == x){
            cout << x << " found at " << mid << "\n";
            break;
        } else if(v[mid] > x){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return 0;
}
