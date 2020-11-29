/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){

    ios :: sync_with_stdio(false);
    cin.tie(0);

    vector<int> bInf = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    int l=0, h=1, mid;
    while(bInf[h] < 1){
        h *= 2;
    }

    int firstOccr;
    while(l <= h) {
        mid = l+(h-l)/2;
        if(bInf[mid] == 1){
            firstOccr = mid;
            h = mid-1;
        }
        else if (bInf[mid] < 1){
            l = mid + 1;
        } else {
            h = mid-1;
        }
    }

    cout << firstOccr;

    return 0;
}