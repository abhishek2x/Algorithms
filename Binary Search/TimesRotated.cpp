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
    int l, r, mid;
    l = 0;
    r = v.size()-1;

    int N = v.size();
    while(l<=r){
        mid = (r+l)/2;
        cout << l << " " << r << "\n";
        if(v[mid] < v[mid-1] && v[mid] < v[mid+1]){
            cout << mid << "\n";
        } else if(v[mid] >= v[l]){
            l = (mid+1);
        } else if (v[mid] < v[r]){
            r = (mid-1);
        }
    return 0;
    }
}
