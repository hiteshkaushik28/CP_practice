#include<bits/stdc++.h>
using namespace std;
int M = 1000000007;

int nbr[4][2] = {{2, 1}, {1, 2}, {2, -1}, {1, -2}};
int m, n;

bool check(int &r, int &c)
{
    return (c > 0 && r <= m && c <= n);
}

int util(int r, int c, vector<vector<vector<int>>> &dp, int odd_even)
{
    if(dp[r][c][odd_even] == -1)
    {
        dp[r][c][odd_even] = 0;
        for(int i = 0; i < 4; ++i)
        {
            int rr = r + nbr[i][0];
            int cc = c + nbr[i][1];
            if(check(rr, cc))
                dp[r][c][odd_even] = (dp[r][c][odd_even] % M + util(rr, cc, dp, odd_even ^ 1) % M) % M;
        }
        dp[r][c][odd_even] = (1 + dp[r][c][odd_even]) % M;
    }
    cout << "res (" << r << "," << c << "): " << dp[r][c][odd_even] << endl;
    return dp[r][c][odd_even];
}

int main()
{
    cin >> m >> n;
    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
    for(int i = 1; i <= n; ++i)
    {
        dp[m][i][0] = dp[m][i][1] = 0;
    }
    // even = 0, odd = 1
    for(int i = 2; i <= n; i += 2)
        util(1, i, dp, 1);

    int sum = 0;
    for(int i = 2; i <= n; i += 2)
    {
        sum = (sum % M + dp[1][i][1] % M) % M;
    }
    cout << sum << endl;
    return 0;
}