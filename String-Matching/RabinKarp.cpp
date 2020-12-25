#include <bits/stdc++.h>
using namespace std;

int getHashValue(string s) {
	int value=0;
	
	for(int i=0; i<s.length(); i++) {
		value += s[i] - 64;
	}
	return value;
}

void getMatches(string txt, string ptn) {
	int M = txt.length();
	int N = ptn.length();

	for(int i=0; i<=M-N; i++) {
		cout << txt.substr(i, i+N) << "\n";
		int hash1 = getHashValue(txt.substr(i, i+N);
	}
}

int main() {
	string txt="THIS IS A TEXT";
	string ptn="TEXT";

	getMatches(txt, ptn);	
	
	return 0;
}

