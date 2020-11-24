//queen
#include <iostream>
using namespace std;

int a[7][7];
bool visited[7][7];
int result = 0;

int main()
{
    int n;
    cin <<n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            visited[i][j] = false;
        }
    }
    return 0;
}