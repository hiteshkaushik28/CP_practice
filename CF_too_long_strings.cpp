#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string s, res = "";
        cin >> s;
        if(s.length() <= 10) res = s;
        else
        {
            res += s[0] + to_string(s.length() - 2) + s.back();
        }
        cout << res << endl;
    }
    return 0;
}