#include <iostream>
using namespace std;
const int D = 8;

bool canPlace(int board[D][D], int n, int r, int c){
    return
        c>=0 && c<n &&
        r>=0 && r<n &&
        board[r][c] == 0;
}

bool SolveKnightMover(int board[D][D], int n, int move_no, int curRow, int curCol){
    if(move_no == n*n){
        return true;
    }

    int rowDir[] = {+2, +1, -1, -2, -2, -1, +1, +2};
    int colDir[] = {+1, +2, +2, +1, -1, -2, -2, -1};
    for (int curDir = 0; curDir < n; ++curDir){

        int nextRow = curRow + rowDir[curDir];
        int nextCol = curCol + colDir[curDir];
        
        if(canPlace(board, n, nextRow, nextCol) == true){
            // Place the knight
            board[nextRow][nextCol] = move_no + 1;
            bool isSuccessful = SolveKnightMover(board, n, move_no + 1, nextRow, nextCol);
    
            if(isSuccessful == true) return true;
    
            board[nextRow][nextCol] = 0;  // erase the board(backtracking)
        }
    }
    return false;
}

void printBoard(int board[D][D], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << "\t";
        }
        cout << endl;    
    }

}    

int main(){
    int board[D][D] = {0};
    int n; cin >> n;

    board[0][0] = 1;
    bool ans = SolveKnightMover(board, n, 1, 0, 0);
    if(ans == true){
        // my function will able to solve it
        printBoard(board, n);
    }
    else{
        cout << "Sorry Man! Can't visit your Board";
    }
}
