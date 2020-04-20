#include<bits/stdc++.h>
using namespace std;
#define INT_MAX 999999999
int N,H,V,S[20][510],rcost[20],c[2],r[2],m[2],mincost=INT_MAX;

void findNormalCost()
{
    int cost;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<H;j++)
        {
            cost=0;
            for(int k=0;k<j;k++)
                cost+=c[0]*S[i][k];
            for(int k=j;k<H;k++)
                cost+=c[1]*S[i][k];
            if(j>H-j)
                cost+=(j-H+j-1)*r[0];
            else if(H-j>j)
                cost+=(H-j-j-1)*r[1];
            if(cost<rcost[i])
                rcost[i]=cost;
        }
    }
}

int findMinCost(int n,int r,int cost,int prev)
{
    if(r==0)
        mincost=cost;
    else if(n<r)
        return mincost;
    else{
        if((cost+rcost[n-1]+((prev-n)*(m[0]*m[0]+m[1]*m[1])))<mincost)
            findMinCost(n-2,r-1,cost+rcost[n-1]+((prev-n)*(m[0]*m[0]+m[1]*m[1])),n);
        findMinCost(n-1,r,cost,n-1);
    }
    return mincost;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        mincost=INT_MAX;
        cin>>N>>H>>V;
        for(int i=0;i<V;i++)
        {
            rcost[i]=INT_MAX;
            for(int j=0;j<H;j++)
                cin>>S[i][j];
        }
        for(int i=0;i<2;i++)
            cin>>c[i]>>r[i]>>m[i];
        findNormalCost();
        int mincost=findMinCost(V,N,0,V);
        cout<<mincost<<endl;
    }
}

