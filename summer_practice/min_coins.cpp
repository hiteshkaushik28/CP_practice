#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, s;
	cout << "Enter the number of coins : ";
	cin >> n;
	int coins[n] = {0};
	cout << "\nEnter " << n << " space separated coin values : \n";	
	for(int i = 0; i < n; ++i)
		cin >> coins[i];
	
	cout << "\nEnter the desired sum : ";
	cin >> s;
	int res[s + 1] = {0};

	res[0] = 0; // for constructing 0 sum, minimum coins are 0.

	// loop that runs over each state
	for(int i = 1; i <= s; ++i)
	{
		int minres = 100000000; // random large value

		// loop that runs over each coin
		for(int j = 0; j < n; ++j)
		{
			// check if that coin can be used for making current sum or not.
			if(coins[j] <= s && i - coins[j] >= 0)
			{
				// update minimum coins needed as minimum of the 2 quantities
				minres = min(minres, res[i - coins[j]] + 1);
			}
		}
		res[i] = minres; // final result for making res[i]
	}
	cout << "\nMinimum coins : " << res[s] << "\n";
	return 0;
}
