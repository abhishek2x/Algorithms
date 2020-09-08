/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{

    ios ::sync_with_stdio(false);
    cin.tie(0);

    vector<string> s;
    s.push_back("1.1.0");
    s.push_back("1.2.1");
    s.push_back("0.9.1");
    s.push_back("1.3.4");
    s.push_back("1.1.2");
    s.push_back("1.1.2.2.3");
    s.push_back("9.3");

    sort(s.begin(), s.end());

    for (auto &&i : s)
    {
        cout << i << endl;
    }

    return 0;
}