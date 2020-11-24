#include <bits/stdc++.h>
using namespace std;
#define N 8

int ifPossible(int x, int y, int n, int b[N][N]){
    return 
        x >= 0 && y >= 0 &&
        x < n && y < n &&
        b[x][y] == 0;
}

int placeKnight(int x, int y, int turns, int n, int b[N][N])
{
    // Base Case
    if(turns == n*n){
        return 1;
    }

    int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 }; 
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 }; 


    for (int i = 0; i < n; i++)
    {
        int next_x = x + xMove[i];
        int next_y = y + yMove[i];

        if(ifPossible(next_x, next_y, n, b))
        {
            b[next_x][next_y] = turns;
            
            // Recursive Case
            if(placeKnight(next_x, next_y, turns+1, n, b) == 1)
                return 1;

            // Backtracking
            else
                b[next_x][next_y] = 0;
        }
    }
    return 0;
}

void printBoard(int b[N][N], int n){

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

    int n;
    cin >> n;
    
    int board[N][N] = {8};

    cout << "Board Before Placement\n\n";
    printBoard(board, n);

    board[0][0] = 1;

    if(placeKnight(0, 0, 2, n, board) == 1){

    cout << "Board After Placement\n\n";
    printBoard(board, n);
    }
    else {
        cout << "Can't be placed";
    }

    return 0;
}