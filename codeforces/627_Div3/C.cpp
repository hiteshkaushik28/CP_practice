#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int ans = 1;
        int start = -1;
        for(int i = 0; i < s.length(); ++i)
        {
            if(s[i] == 'R')
            {
                if(i - start >= ans)
                    ans = i - start;
                start = i;
            }
        }
        ans = max(ans, (int)s.length() - start);
        cout << ans << endl;
    }
    return 0;
}