#include<bits/stdc++.h>
using namespace std;

int arr[2001], presum[2001];
int main()
{
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        presum[i] = (i == 0) ? arr[i] : presum[i - 1] + arr[i];
    }
    vector<vector<int>> dp(n, vector<int>(-1));
    dp[0][0] = 0;
    for(int i = 1; i < n; ++i)
    {
        for(int j = 0; j <= i; ++j)
        {
            if(j == 0)
            {
                
            }
        }
    }
    return 0;
}