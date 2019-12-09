include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if(a * m > b)
    {
        int remain = (n % m) * a;
        if(remain > b) cout << (n / m) * b + b;
        else cout << (n / m) * b + remain;
    }
    else cout << n * a;
}

