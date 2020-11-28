/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){

    ios :: sync_with_stdio(false);
    cin.tie(0);

    vector<int> a = {1, 3, 2, 4, 6, 5, 7, 9, 8, 10};
    int ele = 1;

    int s=0, e=a.size()-1, mid;
    while(s <= e){
        mid = s+(e-s)/2;
        if(a[mid] == ele){
            cout << mid;
            break;
        }
        if(mid-2 >= 0){
            if(a[mid-2] == ele){
                cout << mid-2;
                break;
            }
        }
        if(mid+2 <= a.size()-1){
            if(a[mid+2] == ele){
                cout << mid+2;
                break;
            }
        }

        if(a[mid] <= ele){
            s = mid+1;
        } else {
            e = mid-1;
        }
    }

    return 0;
}
