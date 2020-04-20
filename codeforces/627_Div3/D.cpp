#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n), b(n), c(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i)
    {
        cin >> b[i];
        c[i] = a[i] - b[i];
    }
    sort(c.begin(), c.end());
    long long int ans = 0;
    for(int i = 0; i < n - 1; ++i)
    {
        int temp = (-1 * c[i]) + 1;
        auto itr = lower_bound(c.begin() + i + 1, c.end(), temp);
        ans += (c.begin() - itr) + n;
    }
    cout << ans;
    return 0;
}