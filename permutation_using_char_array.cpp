#include <bits/stdc++.h>
using namespace std;
void gen(char *inp, char res[], int idx, int taken, int mask, int &n)
{
	if(taken == n)
	{
		for(int i = 0; i < n; ++i) cout << res[i];
		cout << endl;
		return;
	}
	for(int i = 0; i < n; ++i)
	{
		if((mask & (1 << i)) == 0)
		{
			res[idx] = inp[i];
			gen(inp, res, idx + 1, taken + 1, (mask | (1 << i)), n);
		}
	}
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		char *inp = "abc";
		char res[n];
		gen(inp, res, 0, 0, 0, n);
	}
	return 0;
}