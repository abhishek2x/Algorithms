/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){

    ios :: sync_with_stdio(false);
    cin.tie(0);

    vector<int> v = {6, 7, 8, 9, 1, 2, 3;
    vector<int> v = {9, 7, 5, 3 , 2};
    int l, r, mid;
    l = 0;
    r = v.size()-1;

    while(l<=r){
        mid = (r+l)/2;
        if(v[mid]<v[mid-1] && v[mid]<v[mid+1]){
            cout << "Congrats you got at " << mid;
            break;
        }
        else if(v[mid] < v[r]){
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    return 0;
}