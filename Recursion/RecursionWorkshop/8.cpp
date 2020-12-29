//queen
#include <iostream>
using namespace std;

int a[7][7];
bool visited[7][7];
int result = 0;

bool isSafe(int n, int i, int j)
{
    return i >= 0 and j >= 0 and i < n and j < n and a[i][j] == 0 and visited[i][j] == false;
}

void ratMaze(int n, int i, int j)
{
    if (i == n - 1 and j == n - 1)
    {
        result++;
        return;
    }
    visited[i][j] = true;
    // work

    if (isSafe(n, i - 1, j) == true)
        ratMaze(n, i - 1, j);

    if (isSafe(n, i + 1, j) == true)
        ratMaze(n, i + 1, j);

    if (isSafe(n, i, j - 1) == true)
        ratMaze(n, i, j - 1);

    if (isSafe(n, i, j + 1) == true)
        ratMaze(n, i, j + 1);

    visited[i][j] = false;
}

int main()
{
    int n = 7;
    cout << "Enter 1's and 0's int the maze";
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cin >> a[i][j];
            visited[i][j] = false;
        }
    }
    return 0;
}
