#include <iostream>
using namespace std;

int friends(int n)
{
    if (n==1 or n==2)
    return n;

    int f1 = friends(n-1);
    int f2 = friends(n-2);

    return f1 + (n-1)*f2;
}
int main()
{
    cout << friends(3);
	return 0;
}
