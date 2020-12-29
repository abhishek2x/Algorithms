#include <iostream>
using namespace std;

void inc(int n)
{
    if(n == 1)
    cout<< n <<endl;
    else 
    {
        inc(n-1);
        cout<<n<<endl;
    }
}

void dec(int n)
{
    if(n == 1)
    cout << 1;
    else
    {
        cout<<n<<endl;
        dec(n-1);
    }
}

int main()
{
    int n;
    cout << "Enter a number " << endl;
    cin >> n;
    cout << "Printing in increasing order " << endl;
    inc(n);
    cout << "Printing in decreasing ordeer " << endl;
    dec(n);
    return 0;
}