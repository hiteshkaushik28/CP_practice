#include<bits/stdc++.h>
using namespace std;
#define forn(i, a, b) for(int i = a; i < b; ++i)

int main()
{
    int t;
    cin >> t;
    forn(tt, 1, t + 1)
    {
        int n;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(3));
        forn(i, 0, n)
        {
            int a, b;
            cin >> a >> b;
            v[i] = {a, b, i};
        }
        sort(v.begin(), v.end());
        int prev_C = 0, prev_J = 0;
        string res(n, '.');
        forn(i, 0, n)
        {
            if(prev_J <= v[i][0])
            {
                res[v[i][2]] = 'J';
                prev_J = v[i][1];
            }
            else if(prev_C <= v[i][0])
            {
                res[v[i][2]] = 'C';
                prev_C = v[i][1];
            }
            else
            {
                res = "IMPOSSIBLE";
                break;
            }
        }
        cout << "Case #" << tt << ": " << res << endl;
    }
    return 0;
}