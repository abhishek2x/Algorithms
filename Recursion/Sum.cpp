#include <iostream>
using namespace std;

int Sum(int n)
{
    static int sum = 0;
    if(n == 1)
    return 1;
    else
    {
        sum  = n + Sum(n-1);
    }
    return sum;
}

int main()
{
    int n;
    cout << "Enter a number "<<endl;
    cin >> n;
    int S = Sum(n);
    cout << "The sum upto n is : "<<S;
    return 0;
}