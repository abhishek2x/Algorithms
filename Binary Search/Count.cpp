/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){

    ios :: sync_with_stdio(false);
    cin.tie(0);

    vector<int> v = {1, 3, 10, 10, 10, 12, 13};
    int l, r, mid, x=10;
    l = 0;
    r = v.size()-1;

    int firstOccr, lastOccr;

    while(l<=r){
        mid = (r+l)/2;
        if(v[mid] == x){
            firstOccr = mid;
            r = mid-1;
        } else if(v[mid] > x){
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    l = 0;
    r = v.size()-1;

    while(l<=r){
        mid = (r+l)/2;
        if(v[mid] == x){
            lastOccr = mid;
            l = mid+1;
        } else if(v[mid] > x){
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << lastOccr-firstOccr;
    return 0;
}
