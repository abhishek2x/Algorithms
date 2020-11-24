#include <iostream>
using namespace std;


int DigCnt(int n)
{
    static int c = 0;
    if (n == 0)
    return c;
    else
    {
        c++;
        DigCnt(n/10);
    }
}

int main()
{
    int num;
    cout << "Enter a number : ";
    cin >> num;
    int cnt = DigCnt(num);
    cout << cnt;
    return 0;
}
