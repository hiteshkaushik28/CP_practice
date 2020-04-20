#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>  
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> b(n + 1), a(n + 1);
    for(int i = 1; i <= n; ++i) cin >> b[i];
    a[1] = b[1];
    long long prev_max = 0;
    cout << a[1] << " ";
    for(int i = 2; i <= n; ++i)
    {
        prev_max = max(prev_max, a[i - 1]);
        a[i] = b[i] + prev_max;
        cout << a[i] << " ";
    }
    return 0;
}