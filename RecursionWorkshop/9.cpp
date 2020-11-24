#include <iostream>
using namespace std;

int F[51];
int fact(int n)
{
    if(F[1] != -1)
        return F[n];
    F[n] = fact(n-1) + fact(n-2);
    return F[n];
}

int main()
{
    int n ;
    for (int i = 0; i < 51; i++)
    {
        F[i] = -1;
    }
    F[0] = 0;
    F[1] = 1;
    cout << " Enter a number : ";
    cin >> n;
    int result = fact(n);
    cout << result;
}
