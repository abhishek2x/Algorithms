#include <bits/stdc++.h>
using namespace std;
#define N 4

bool ifPossible(int m[N][N], int x, int y){
    if (x >= 0 && x < N && y >= 0 &&  
       y < N && m[x][y] != 0) 
        return true; 
  
    return false; 
}

bool solveMaze(int m[N][N], int x, int y, int ms[N][N])
{
    if(x == N-1 && y == N-1){
        ms[x][y] = 1;
        return true;
    }

    if(ifPossible(m, x, y))
    {
        ms[x][y] = 1;

        // recursion
        for (int k = 1; k <= m[x][y] && k < N; k++)
        {
            if(solveMaze(m, x+k, y, ms))
                return true;

            if(solveMaze(m, x, y+k, ms))
                return true;
            
        }
    
        // Backtracking
        ms[x][y] = 0;
        // since there is no loop/condition so we return false
        // Optional
        return false;
    }
    return false;
}

void printMaze(int m[N][N]){

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << m[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main(){

    ios :: sync_with_stdio(false);
    cin.tie(0);

    int maze[N][N] = { { 2, 1, 0, 0 }, 
                       { 3, 0, 0, 1 }, 
                       { 0, 1, 0, 1 }, 
                       { 0, 0, 0, 1 } }; 

    
    int mazeS[N][N] = {0};

    cout << "Original Matrix\n\n";
    printMaze(maze);
  
    if(solveMaze(maze, 0, 0, mazeS)) {
        cout << "\nSolved Matrix\n\n";
        printMaze(mazeS);
    } else cout << "No Solution";

    return 0;
}

