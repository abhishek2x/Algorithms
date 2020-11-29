/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){

    ios :: sync_with_stdio(false);
    cin.tie(0);

    vector<int> a = {1, 4, 5, 10, 7, 3, 5, 2};

    int l=0, h=a.size()-1, mid;
    while(l <= h){
        mid = l + (h-l)/2;
        if(mid == 0){
            if(a[mid] > a[mid+1]){
                cout << a[mid];
                // break;
            }
        } else if (mid == a.size()-1){
            if(a[mid] > a[mid-1]){
                cout << a[mid];
                // break;
            }
        } else if(a[mid]>a[mid-1] && a[mid] > a[mid+1]){
            cout << a[mid] << "\n";
            // break;
        }
        else if(a[mid] < a[mid-1]){
            l = mid+1;
        } else {
            h = mid-1;
        }
    }

    return 0;
}