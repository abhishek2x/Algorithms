//subset
#include <iostream>
using namespace std;

void game(string s1,string s2)
{
    if(s1.size() == 0)
    {
        cout<<s2<<endl;
        return;
    }
    
    char ch = s1[0];
    string r = s1.substr(1);
    game(r, s2+ch);
    game(r, s2);
    return;
}
int main()
{
    game("abcd", "");
    return 0;
}
