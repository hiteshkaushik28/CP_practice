#include<iostream>
#include<cstring>
using namespace std;
int t, n;
int x[20], y[20];
int dp[20][1 << 12];

int dist(int i, int j)
{
    int sum = 0;
    sum += ((x[i] > x[j]) ? x[i] - x[j] : x[j] - x[i]);
    sum += ((y[i] > y[j]) ? y[i] - y[j] : y[j] - y[i]);
    return sum;
}
int calc(int pos, int mask)
{
    if(pos == 0 && mask == 0) return 0;
    if(pos == 0 && mask != 0) return 1e9;

    int &ret = dp[pos][mask];
    if(ret != -1) return ret;
    ret = 1e9;
    for(int i = n; i>= 0; --i)
    {
        if(mask & (1 << i))
        {
            int d = dist(pos, i);
            ret = min(ret, calc(i, mask ^ (1 << i)) + d);
        }
    }
    return ret;
}

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> x[0] >> y[0];
        cin >> x[n + 1] >> y[n + 1];
        for(int i = 1; i <= n; ++i)
            cin >> x[i] >> y[i];
        memset(dp, -1, sizeof(dp));
        int mask = (1 << (n + 1)) - 1;
        cout << calc(n + 1, mask) << endl;
    }   
}