// 4
// 021
// 312
// 4
// 221
#include<bits/stdc++.h>
using namespace std;
#define forn(i, a, b) for(int i = a; i < b; ++i)
int main()
{
    int t;
    cin >> t;
    forn(tt, 1, t + 1)
    {
        string s;
        cin >> s;
        int n = s.length();
        string res = "";
        int open = 0;
        int pre = 0;
        forn(i, 0, n)
        {
            int digit = s[i] - '0';
            if(digit > pre)
            {
                while(open != digit)
                {
                    res += '(';
                    ++open;
                }
            }
            else if(digit < pre)
            {
                while(open != digit)
                {
                    res += ')';
                    --open;
                }
            }
            res += s[i];
            pre = digit;
        }
        forn(i, 0, open) res += ')';
        cout << "Case #" << tt << ": " << res << endl;
    }
    return 0;
}