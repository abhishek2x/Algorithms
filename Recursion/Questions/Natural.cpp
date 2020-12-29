#include <iostream>
using namespace std;

void natural(int n)
{
    if(n == 1)
    cout << n << endl;
    else
    {
        cout << n << endl;
        natural(n-1);
    }
}
int main()
{
    natural(50);
    return 0;
}