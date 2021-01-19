/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

long getSequenceSum(int i, int j, int k) {
  long ans = 0;
  for (int p = k; p < j; p++){
    ans+=p;
  }
  ans *= 2;
  ans += j;
  for (int p = i; p < k; p++){
    ans+=p;
  }
  
  return ans;
}

int main(){

  cout << getSequenceSum(5, 9, 6);

  return 0;
}