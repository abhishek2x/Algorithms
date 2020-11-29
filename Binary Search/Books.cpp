/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// to check if value at mid is considerable
bool isValid(vector<int> a, int mid, int k, int n){
    int mx=1, sum=0;
    for (int i = 0; i < n; i++)
    {
        if(sum+a[i] <= mid){
            sum += a[i];
        } else {
            sum=a[i];
            mx++;
        }
    }
    // cout << mx << "\n\n";
    if(mx == k) return true;
    else return false;
}

int main(){

    ios :: sync_with_stdio(false);
    cin.tie(0);

    vector<int> v = {10, 20, 30, 40};
    int students = 2;

    // if(students > v.size() return -1)
    
    // Storing sum and max
    int end=0, start=INT_MIN;
    for (int i = 0; i < v.size(); i++){
        end += v[i];
        if(v[i] > start) start = v[i];
    }

    int mid ,res;
    while(start <= end){
        mid = start + (end-start)/2;
        // cout << start << " " << end << " " << mid << "\n"; 
        if(isValid(v, mid, students, v.size())){
            res = mid;
            end = mid-1;
        } else {
            start = mid+1;
        }
    }
    cout << res;
    return 0;
}