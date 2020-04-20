#include<iostream>
using namespace std;

int arr[100][100];
int store[100][100];
int t, m, n, k, ans;

void reset()
{
    ans = -9999999;
    for(int i = 0; i < 100; ++i)
        for(int j = 0; j < 100; ++j)
            arr[i][j] = store[i][j] = 0;
}

void solve()
{
    int rownum = 0;
    for(int i = 0; i < m; ++i)
    {
        int cnt = 0;
        for(int j = 0; j < n; ++j)
            if(!arr[i][j]) cnt++;

        if((k % 2 == 0 && cnt % 2 == 0) ||(k % 2 == 1 && cnt % 2 == 1) && cnt <= k)
        {
            for(int j = 0; j < n; ++j)
                store[rownum][j] = arr[i][j];
            rownum++;
        }
    }

    for(int i  = 0; i < rownum; ++i)
    {
        int count = 1;
        for(int j = i + 1; j < rownum; ++j)
        {
            bool flag = true;
            for(int itr = 0; itr < n; ++itr)
            {
                if(store[i][itr] != store[j][itr])
                {
                    flag = false;
                    break;
                }
            }
            if(flag) count++;
        }
        if(count > ans) ans = count;
    }
}
int main()
{
    cin >> t;
    while(t--)
    {
        reset();
        cin >> m >> n >> k;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                cin >> arr[i][j];

        solve();
        cout << ans << endl;
    }
    return 0;
}