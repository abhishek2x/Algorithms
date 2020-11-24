#include <bits/stdc++.h>
using namespace std;

#define D 8

bool isPossible(int board[D][D], int row, int col, int n){

    int i, j; 
  
    // Check this row 
    for (i = 0; i < col; i++) 
        if (board[row][i]) 
            return false; 
  
    // Check upper diagonal 
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j]) 
            return false; 
  
    // Check lower diagonal 
    for (i = row, j = col; j >= 0 && i < n; i++, j--) 
        if (board[i][j]) 
            return false; 
  
    return true; 
}

bool placeQ(int b[D][D], int col, int n)
{
    // base case
    if(col >= n){
        return true;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            
            if(isPossible(b, i, col, n)){

                b[i][col] = 1;
                if(placeQ(b, col+1, n) == true)
                    return true;
                else
                    b[i][col] = 0;
            }
        }
    }
    return false;
}

void printMat(int b[D][D], int n){

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << b[i][j] << "\t";
        }
        cout << endl;
    }
}

int main(){

    ios :: sync_with_stdio(false);
    cin.tie(0);

    int n = 4;
    int board[D][D];
    
    // Initialize
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            board[i][j] = 0;
        }
    }
    
    if(placeQ(board, 0, n)){
        cout << "\n Solution Matrix : \n\n";
        printMat(board, n);
    } else{
        cout << "Solution Not Possible";
    }

    return 0;
}
