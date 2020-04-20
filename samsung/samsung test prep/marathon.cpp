#include <iostream>
using namespace std;
int ab[5][2];

int time(int E, int D){
    int max = 99999;
    int dp[D+1][E+1];
    for(int j=0;j<=E;j++)
        dp[0][j] = 0;

    for(int i=1;i<=D;i++)
        for(int j=1;j<=E;j++)
            dp[i][j] = max;

    for(int i=1;i<=D;i++)
    {
        for(int j=1;j<=E;j++)
        {
            for(int k=0;k<5;k++)
                if(j>=ab[k][1] && dp[i][j]>dp[i-1][j-ab[k][1]] + ab[k][0])
                    dp[i][j] = dp[i-1][j-ab[k][1]] + ab[k][0];
        }
    }
    int p=max;
    for(int j=0;j<=E;j++){
        if(dp[D][j]<p)
            p = dp[D][j];
    }
    return p;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int E, D;
        cin>>E>>D;
        for(int i=0;i<5;i++){
            int a, b;
            cin>>a>>b>>ab[i][1];
            ab[i][0] = a*60 + b;
        }
        int tt = time(E, D);
        cout<<tt/60<<" min"<<tt%60<<" sec"<<"\n";
    }
}