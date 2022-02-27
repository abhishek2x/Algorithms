/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int letsSearch(vector<int> arr, int l, int h, int x){
    if(l>h){
        return -1;
    }
    int mid = (l+h)/2;
    if(arr[mid] == x){
        return mid;
    } else if(arr[mid] > x){
        return letsSearch(arr, l, mid-1, x);
    } else return letsSearch(arr, mid+1, h, x);
}

int main(){

    ios :: sync_with_stdio(false);
    cin.tie(0);

    vector<int> v = {5, 6, 7, 8, 9, 1, 2, 3};
    int l, r, mid, x=7;
    l = 0;
    r = v.size()-1;
    int minIndex;

    // PART-1: Find lowest element

    while(l<=r){
        mid = (r+l)/2;
        if(v[mid]<v[mid-1] && v[mid]<v[mid+1]){
            minIndex = mid;
            break;
        }
        else if(v[mid] < v[r]){
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }

    cout << "Smallest Element at: " << minIndex << "\n";

    // PART-2: Apply BS on two subarrays

    if(letsSearch(v, 0, minIndex-1, x) != -1){
        cout << "Number " << x << " found at: " << letsSearch(v, 0, minIndex-1, x);
    } else {
        cout << "Number " << x << " found at: " << letsSearch(v, minIndex, r, x);
    }

    return 0;
}
