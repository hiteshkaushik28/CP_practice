#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; ++tt)
    {
        int n;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(n));
        vector<vector<int>> row(n, vector<int>(n + 1, false));
        vector<vector<int>> col(n, vector<int>(n + 1, false));
        int r_count = 0, c_count = 0, trace = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                cin >> v[i][j];
                if(i == j) trace += v[i][j];
                row[i][v[i][j]]++;
                col[j][v[i][j]]++;
            }
        }
        for(int i = 0; i < n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(row[i][j] > 1)
                {
                    r_count++;
                    break;
                }
            }
        }
        for(int i = 0; i < n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(col[i][j] > 1)
                {
                    c_count++;
                    break;
                }
            }
        }
        cout << "Case #" << tt << ": " << trace << " " << r_count << " " << c_count << endl;
    }
    return 0;
}