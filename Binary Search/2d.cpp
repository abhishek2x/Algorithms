/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){

    ios :: sync_with_stdio(false);
    cin.tie(0);

    vector<vector <int> >  a = {
        {10, 20, 30, 40},
        {15, 25, 35, 96},
        {17, 29, 37, 98},
        {32, 33, 39, 50}
    };
    int n = 4;
    int key = 17;

    int l=0, h=n-1, mid;
    while(l<n && h<n && h>=0 &&l>=0){
        // cout << l << " -- " << h << "\n";
        mid = l + (h-l)/2;
        if(a[l][h] == key){
            cout << l << " " << h;
            break;
        } else if(a[l][h] > key){
            h -=1;
        } else{
            l+=1;
        }
    }

    return 0;
}