#include <bits/stdc++.h>
using namespace std;

void showPermutations(string s, int l, int end){

    if(l == end-1){
        cout << s << endl;
    }

    else{

        for (int i = l; i < end; i++){
            // swapping
            swap(s[l], s[i]);

            // recursion
            showPermutations(s, l+1, end);

            // backtracking
            swap(s[i], s[l]);
        }
    }
}

