#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        bool even = false, odd = false;
        for(int i = 0; i < n; ++i)
        {
            cin >> v[i];
            if(v[i] & 1) odd = odd || true;
            else even = even || true;
        }
        if(even && odd) cout << "NO";
        else cout << "YES";
        cout << "\n";
    }
}