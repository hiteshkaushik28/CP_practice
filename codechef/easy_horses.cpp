#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef unsigned long long int ll;

ll sign(ll p, ll q)
{
	if(p>=q)
		return (p-q);
	else
		return -(p-q);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		//freopen("output.txt","w",stdout);
	#endif
		// **** code goes here ****
		vector<ll>v(5000);
		ll min,temp;
		min=INT_MAX;
		int t,n,i=0;
		cin>>t;
		//cout<<t<<"\n";
		while(t--)
		{
			cin>>n;
			//cout<<n<<"\n";
			for(i=0;i<n;i++)
				cin>>v[i];
			sort(v.begin(),v.begin()+n);
			for(i=0;i<n-1;i++)
			{
				temp=sign(v[i],v[i+1]);
				if(temp<min)
					min=temp;
			}
			cout<<min<<"\n";
			min=INT_MAX;
		}
	return 0;
}