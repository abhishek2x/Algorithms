// CPP program to find the gray sequence of n bits.
#include <iostream> 
#include <vector> 
using namespace std; 

void grayCodeUtil(vector<int>& res, int n, int& num) 
{ 
    
	if (n == 0) { 
		res.push_back(num); 
		return; 
	} 

	// ignore the bit. 
	grayCodeUtil(res, n - 1, num); 

	// invert the bit. 
	num = num ^ (1 << (n - 1)); 
	grayCodeUtil(res, n - 1, num); 
} 


vector<int> grayCodes(int n) 
{ 
	vector<int> res; 


	int num = 0; 
	grayCodeUtil(res, n, num); 

	return res; 
} 


int main() 
{ 

    ios :: sync_with_stdio(false);
    cin.tie(0);
    
	int n = 3; 

	vector<int> code = grayCodes(n); 
	for (int i = 0; i < code.size(); i++) 
		cout << code[i] << endl;	 

	return 0; 
} 
