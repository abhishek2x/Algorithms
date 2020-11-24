// Print all possible paths from top left 
    // to bottom right of a mXn matrix

// To be understood

#include <bits/stdc++.h>
using namespace std;
#define N 8

void pathPrinter(int *mat, int i, int j, int m, int n, int *path, int pi) 
{ 
    // Reached the bottom of the matrix so we are left with 
    // only option to move right 
    if (i == m - 1) 
    { 
        for (int k = j; k < n; k++) 
            path[pi + k - j] = *((mat + i*n) + k); 
        for (int l = 0; l < pi + n - j; l++) 
            cout << path[l] << " "; 
        cout << endl; 
        return; 
    }
  
    // Reached the right corner of the matrix we are left with 
    // only the downward movement. 
    if (j == n - 1) 
    { 
        for (int k = i; k < m; k++) 
            path[pi + k - i] = *((mat + k*n) + j); 
        for (int l = 0; l < pi + m - i; l++) 
            cout << path[l] << " "; 
        cout << endl; 
        return; 
    } 
  
    path[pi] = *((mat + i*n) + j); 
  
    //  down 
    pathPrinter(mat, i+1, j, m, n, path, pi + 1); 
  
    //  right 
    pathPrinter(mat, i, j+1, m, n, path, pi + 1); 
  
    //  diagonal 
    // pathPrinter(mat, i+1, j+1, m, n, path, pi + 1); 
} 

int main(){

    ios :: sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    int matrix[m][n];
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    int *path = new int[m+n];
    pathPrinter(*matrix, 0, 0, m, n, path, 0);
    
    return 0;
}

// Examples :

// Input : 1 2 3
//         4 5 6
// Output : 1 4 5 6
//          1 2 5 6
//          1 2 3 6

// Input : 1 2 
//         3 4
// Output : 1 2 4
//          1 3 4

