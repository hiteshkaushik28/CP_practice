#include <iostream>
#include <vector>
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
        for(int i = 0; i < n; ++i) cin >> v[i];
        bool flag = false;
        for(int i = 0; i < n; ++i)
            for(int j = i + 2; j < n; ++j)
                if(v[i] == v[j]) flag = true;
        flag ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}