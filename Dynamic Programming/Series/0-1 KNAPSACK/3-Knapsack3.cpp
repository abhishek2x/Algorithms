/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int t[101][1001];

int BottomUp(int wts[], int prices[], int N, int W){

    int dp[101][1001] = {0};

    for (int i = 0; i <= N; i++){
        for (int j = 0; j <= W; j++){       //j -> weights of dp[1]'th element
            
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else{
                int inc = 0, exc = 0;
                
                // If we include the item
                if(j >= wts[i-1]){
                    inc = prices[i-1] + dp[i-1][j - wts[i-1]];
                }

                // If we exclude the item
                exc = 0 + dp[i-1][j];

                dp[i][j] = max(inc, exc);
            }
        }
    }
    return dp[N][W];
}


int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  memset(t, -1, sizeof(t));
  
  int values[] = {60, 100 ,120};
  int weights[] = {10, 20, 30};
  int W = 50;

  cout << BottomUp(weights, values, 3, W);
  return 0;
}
