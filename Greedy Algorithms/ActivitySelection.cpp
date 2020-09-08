#include <bits/stdc++.h>
using namespace std;

void giveMaxpossibility(int* s, int* f, int n){
    
    int i = 0;

    cout << i << " ";
    for (int j = 1; j < n; j++)
    {
        if(s[j] >= f[i]){
            cout << j << " ";
            i = j;
        }
    }
}

int main(){

    ios :: sync_with_stdio(false);
    cin.tie(0);

    int s[] =  {1, 3, 0, 5, 8, 5}; 
    int f[] =  {2, 4, 6, 7, 9, 9}; 

    // since f is already 
    // else we have done 
    // sort(f, f+f.length());

    giveMaxpossibility(s, f, 6);

    return 0;

}