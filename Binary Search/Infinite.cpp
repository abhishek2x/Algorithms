/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int binaryPlay(vector<int> a, int l, int h, int key){
    while(l<=h){
        int mid = l + (h-l)/2;
        if(a[mid] == key){
            return mid;
        } else if(a[mid] < key){
            l = mid+1;
        } else {
            h = mid-1;
        }
    }
    return -1;
}

int main(){

    ios :: sync_with_stdio(false);
    cin.tie(0);

    vector<int> inf = {1, 2, 3, 4, 5, 6, 7 ,8 , 9, 10};
    int key = 4;

    int l = 0, h = 1, mid;
    while(inf[h] < key){
        h = h*2;
    }
    // cout << h << "\t";
    cout << binaryPlay(inf, l, h, key);
    return 0;
}