#include  <bits/stdc++.h>
using namespace std;

const int D = 8;

bool isPossible(int board[D][D], int n, int r, int c){
    return 
        r >= 0 && r < n &&
        c >= 0 && c < n &&
        board[r][c] == 0;
}

bool Kn(int board[D][D], int n, int move_no, int CurRow, int CurCol){

    if(move_no == n*n){
        return true;
    }

    int rowDir[] = {+2, +1, -1, -2, -2, -1, +1, +2};
    int colDir[] = {+1, +2, +2, +1, -1, -2, -2, -1};

    for (int i = 0; i < 8; i++)
    {
        int r = CurRow + rowDir[i];
        int c = CurCol + colDir[i];

        bool m = isPossible(board, n, r, c);

        if(m == true){
            board[r][c] = move_no+1;
            bool p = Kn(board, n, move_no+1, r, c);

            // Backtracking
            if( p == true) return true;
                board[r][c] = 0;
        }

    }
    return false;
}

void printBoard(int v[D][D], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main(){

    int n; cin >> n;
    int board[D][D] = {0};

    bool k = Kn(board, n, 1, 0, 0);

    if(k == true){
        printBoard(board, n);
    }
    else
    {
        cout << "Not Possible";
    }
    
    return 0;
}