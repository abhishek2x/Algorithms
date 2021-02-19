#include <bits/stdc++.h>
using namespace std;

void getMatch(string txt, string ptn) {
    int N = txt.length(); 
    int M = ptn.length(); 
 
	// <F2>cout << M  << " : " << N; 

    for (int i = 0; i <= N - M; i++) { 
        int j;  
       
        for (j = 0; j < M; j++) 
            if (txt[i + j] != ptn[j]) 
                break; 
  
        if (j == M)  
            cout << "Pattern found at index "
                 << i << endl; 
    } 
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
	string txt = "AABAACAADAABAAABAA"; 
    string ptn = "AABA"; 


	getMatch(txt, ptn);
	
	return 0;
}
