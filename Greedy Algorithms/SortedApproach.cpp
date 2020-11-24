//  BASIC GREEDY APPROACH
//      start[]  =  {10, 12, 20};
//      finish[] =  {20, 25, 30};
//  {0, 2} 

//      start[]  =  {1, 3, 0, 5, 8, 5};
//      finish[] =  {2, 4, 6, 7, 9, 9};
// {0, 1, 3, 4} 

#include <bits/stdc++.h>
using namespace std;

void printMaxActivities(int s[], int f[], int n){
    int activity = 0;
    cout << activity << " ";
    for (int i = 1; i < n; i++){
        if(s[i] >= f[activity]){
            cout << i << " ";
            activity++;
        }
    }
}

int main(){
    int s[] =  {1, 3, 0, 5, 8, 5}; 
    int f[] =  {2, 4, 6, 7, 9, 9}; 
    int n = sizeof(s)/sizeof(s[0]); 
    printMaxActivities(s, f, n); 
    return 0; 
}