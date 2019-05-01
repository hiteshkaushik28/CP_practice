void LCS(string &s1, string &s2)
{
    int n1 = s1.length();
    int n2 = s2.length();
    int dp[n1][n2] = {0}; // this will fill matrix with all 0's
    
    for(int i = 1; i < n1; ++i)
    {
        for(int j = 1; j < n2; ++j)
        {
            if(s1[i] == s2[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << "\n" << dp[n1-1][n2-1] << "\n";
}
