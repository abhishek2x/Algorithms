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

int main(){

    ios :: sync_with_stdio(false);
    cin.tie(0);

    string s = "ABC";
    int len = s.length();

    showPermutations(s, 0, len);

    return 0;
}