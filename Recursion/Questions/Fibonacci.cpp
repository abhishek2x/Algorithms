#include<iostream>
using namespace std;

int fibo(int num)
{
    if(num==1||num==2)
        return 1;
    else
        return (fibo(num-1)+fibo(num-2));  // recursive call
}

int main()
{
    int i,n;
    cout<<"Enter the required term: ";
    cin>>n;
    cout<<"First "<<n<<" fibonacci numbers are"<<endl;
    for (i=1; i<=n; i++)
        cout<<fibo(i)<<endl;
    return 0;
}