#include <iostream>
using namespace std;

// int fa(int);
int fb(int);

// int fa(int n)
// {
//    if(n<=1)
//       return 1;
//    else
//       return n*fb(n-1);
// }
int fb(int n)
{
   if(n<=1)
      return 1;
   else
      return n*fb(n-1);
}
int main()
{
   int num=5;
   cout<<fb(num);
   return 0;
}