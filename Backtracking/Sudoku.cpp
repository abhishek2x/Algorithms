#include <bits/stdc++.h>
using namespace std;
#define N 9

bool checkRow(int g[N][N], int r, int n){

    for (int i = 0; i < N; i++){
        if(g[r][i] == n)
            return true;
    }
    return false;
}

bool checkColumn(int g[N][N], int c, int n){

    for (int i = 0; i < N; i++){
        if(g[i][c] == n)
            return true;
    }
    return false;
}

bool checkBox(int g[N][N], int r, int c, int n){

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(g[i+r][j+c] == n)
                return true;
        }
    }
    return false;
}

bool isPossible(int g[N][N], int i, int j, int num){
    
    return !checkRow(g, i, num) && !checkColumn(g, j, num)
            && !checkBox(g, i-i%3, j-j%3, num) && g[i][j] == 0;
}

bool FindUnassignedLocation(int g[N][N], int &i, int &j){

    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            if(g[i][j] == 0)
                return true;
        }
    }
    return false;
}

bool solveSudoku(int g[N][N]){

    int row;
    int col;

    if(!FindUnassignedLocation(g, row, col))
        return true;

    for (int i = 1; i <= 9; i++)
    {
        if(isPossible(g, row, col, i))
        {
            g[row][col] = i;
            
            // Recursion
            if(solveSudoku(g))
                return true;
            
            // Backtracking
            g[row][col] = 0;
        }
    }
    return false;
}

void printSudoku(int s[N][N]){

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << s[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main(){

    ios :: sync_with_stdio(false);
    cin.tie(0);
    
    // 0 means unassigned cells  
    int grid[N][N] = { {3, 0, 6, 5, 0, 8, 4, 0, 0},  
                       {5, 2, 0, 0, 0, 0, 0, 0, 0},  
                       {0, 8, 7, 0, 0, 0, 0, 3, 1},  
                       {0, 0, 3, 0, 1, 0, 0, 8, 0},  
                       {9, 0, 0, 8, 6, 3, 0, 0, 5},  
                       {0, 5, 0, 0, 9, 0, 6, 0, 0},  
                       {1, 3, 0, 0, 0, 0, 2, 5, 0},  
                       {0, 0, 0, 0, 0, 0, 0, 7, 4},  
                       {0, 0, 5, 2, 0, 6, 3, 0, 0}  };  

    
    cout << "Before Solving : \n\n";
    printSudoku(grid);

    if(solveSudoku(grid)){
        cout << "\nAfter Solving Sudoku\n";
        printSudoku(grid);
    } else{
        cout << "Can't be Solved";
    }

    return 0;
}
