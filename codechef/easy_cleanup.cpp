#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
//typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
//typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
//typdef unsigned long long int uint64;


int main()
{
	#ifndef ONLINE_JUDGE
		//freopen("input.txt","r",stdin);
		//freopen("output.txt","w",stdout);
	#endif
		// **** code goes here ****
		int t,n,m,i,j;
		vector<int>v1(1001,0);
		vector<int>v2(1001);
		vector<int>v3(1001,0);

		cin>>t;
		while(t--)
		{
			cin>>n>>m;
			for(i=1;i<=m;i++)
				cin>>v2[i];
			for(i=1;i<=m;i++)
				v1[v2[i]]++;

			j=1;

			for(i=1;i<=n;i++)	
			{
				if(v1[i]==0)
					v3[j++]=i;
			}

			for(i=1;i<=(n-m);i+=2)
			{
				if(v3[i])
					cout<<v3[i]<<" ";
				else 
					cout<<" ";
			}

			cout<<"\n";

			for(i=2;i<=(n-m);i+=2)
			{
				if(v3[i])
					cout<<v3[i]<<" ";
				else 
					cout<<" ";
			}	
			cout<<"\n";		
			fill(v3.begin(), v3.end(),0);
			fill(v1.begin(), v1.end(),0);
		}
	return 0;
}