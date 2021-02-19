#include <bits/stdc++.h>
using namespace std;

int getHashValue(string s) {
	int value=0;
	
	for(int i=0; i<s.length(); i++) {
		value += s[i] - 64;
	}
	return value;
}

bool compare(string s1, string s2){
	for(int i=0;i<s1.length(); i++){
		if(s1[i] != s2[i])
			return false;
	}
	return true;
}

void getMatches(string txt, string ptn) {
	int M = txt.length();
	int N = ptn.length();
	int hash2 = getHashValue(ptn);

	for(int i=0; i< M; i++) {
		// cout << txt.substr(i, N) << "\n";
		int hash1 = getHashValue(txt.substr(i, i+N));
		// cout << hash1 << " = " << hash2 << "\n";

		if(hash1 == hash2)
			if(compare(txt.substr(i, i+N), ptn))
				cout << "Found at: " <<  i << "\n";
	}
}

int main() {
	string txt="THIS IS A TEXT";
	string ptn="TEXT";

	getMatches(txt, ptn);	
	
	return 0;
}

