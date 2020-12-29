//maze problem
#include <iostream>
using namespace std;

int maze(int n, int m, int cr,int cc)
{
    if(n-1 == cr and m-1 == cc)
    return 1;

    if(cc >= m or cr >= n)
    return 0;

    int rightans = maze(n, m, cr, cc+1);
    int downans = maze(n, m, cr+1, cc);
    return rightans + downans;
}

int main()
{
    cout << maze(3,3,0,0);
    return 0;
}

