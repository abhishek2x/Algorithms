// Tower of hanoi

/*!
* Copyright (c) 2020 Abhishek Srivastava

n = 4

Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
Move disk 4 from A to B
Move disk 1 from C to B
Move disk 2 from C to A
Move disk 1 from B to A
Move disk 3 from C to B
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int;

void TowerPlay(int n, char source, char destination, char helper) {
  if(n == 1) {
    cout << "Move disk 1 from " << source << " to " << destination << endl;
    return;
  }

  TowerPlay(n-1, source, helper, destination);
  cout << "Move disk " << n << " from " << source << " to " << destination << endl;

  TowerPlay(n-1, helper, destination, source);  
}

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  TowerPlay(4, 'A', 'B', 'C');
  return 0;
}