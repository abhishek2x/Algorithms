// permutations
#include <iostream>
using namespace std;

void permut(string str, string osf)
{
    if (str.size() == 0)
    {
        cout << osf << endl;
        return;
    }

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        string r = str.substr(0, i) + str.substr(i + 1);
        permut(r, osf + ch);
    }
}

int main()
{
    permut("abc", "");
    return 0;
}
