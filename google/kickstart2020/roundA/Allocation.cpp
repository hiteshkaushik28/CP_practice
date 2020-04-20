#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        int n, b;
        cin >> n >> b;
        vector<int> v(n);
        for(int j = 0; j < n; ++j) cin >> v[j];
        sort(v.begin(), v.end());
        int cnt = 0;
        int idx = 0;
        while(idx < n)
        {
            if(b - v[idx] >= 0)
            {
                b -= v[idx];
                cnt++;
                idx++;
            }
            else
            {
                break;
            }
        }
        cout << "Case #" << i << ": " << cnt << endl;
    }
    return 0;
}