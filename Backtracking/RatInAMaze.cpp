#include <bits/stdc++.h>
using namespace std;

#define D 4

bool ifPossible(int x, int y, int m[D][D], int n){
    return x >= 0 && y >= 0 &&
           x < n && y < n &&
           m[x][y] == 1;
}

bool solveMaze(int x, int y, int m[D][D], int n){

    // base case
    if(x == n-1 && y == n-1)
        return true;
    else
    {
        int x_dir[] = {0, 1};
        int y_dir[] = {1, 0};

        for (int i = 0; i < 2; i++)
        {
            int next_x = x + x_dir[i];
            int next_y = y + y_dir[i];

            if(ifPossible(next_x, next_y, m, n)){
                m[next_x][next_y] = 5;  // ->demo no. 5

                // Recursion
                if(solveMaze(next_x, next_y, m, n))
                    return true;
                else
                    m[next_x][next_y] = 0; //  backtracking
            }
        }
    }   
    return  0;
}

void printMaze(int m[D][D], int n){

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << m[i][j] << "\t";
        }
        cout << "\n";
    }
}

void printMazeSoln(int m[D][D], int n){

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i == 0 && j == 0)
            cout << "5" << "\t";
            else if(m[i][j] == 5)
            cout << m[i][j] << "\t";
            else cout << "\t";
        }
        cout << "\n";
    }
}
int main(){

    ios :: sync_with_stdio(false);
    cin.tie(0);

    int n = 4;

    int maze[D][D] = { { 1, 1, 1, 0 }, 
                       { 1, 1, 1, 1 }, 
                       { 1, 1, 0, 1 }, 
                       { 0, 0, 0, 1 } }; 

    cout << "Maze before Solving \n\n";
    printMaze(maze, n);
    
    if(solveMaze(0, 0, maze, n)){
        cout << "\nMaze after Solving \n\n";
        maze[0][0] = 5;
        printMazeSoln(maze, n);
    }

    else {
        cout << "Can't be solved";
    }

    return 0;
}