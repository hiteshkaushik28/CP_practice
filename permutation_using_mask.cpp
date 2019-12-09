#include<bits/stdc++.h>
using namespace std;

void gen(int n, int mask, string s)
{
    if(n == 0 && mask == 0) cout << s << endl;
    if(n == 0 && mask != 0) return;
    for(int i = n; i >= 0; --i)
    {
        if(mask & (1 << i))
        {
            gen(i, mask ^ (1 << i), s + to_string(i));
        }
    }
}
int main()
{
    int n = 5;
    int mask = (1 << (n + 1)) - 1;
    gen(n, mask, "");
    return 0;
}