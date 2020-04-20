#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int h, d;
        cin>>h>>d;
        int time[6], himpact[6], a, b;
        for(int i=0;i<5;i++){
            cin>>a>>b>>himpact[i];
            time[i] = a*60+b;
        }
        int dp[h+2][d+2];
        for(int i=0;i<=h;i++)
            dp[i][0]=0;
        for(int i=1;i<=d;i++)
            dp[0][i] = -1;
        for(int i = 1;i<=d;i++){
            for(int j=1;j<=h;j++){
                int time_ = 999999, cur_time=99999;
                for(int k=0;k<5;k++){
                    if(j-himpact[k]>=0 && dp[j-himpact[k]][i-1]!=-1){
                        cur_time = time[k] + dp[j-himpact[k]][i-1];
                        if(cur_time<time_)
                            time_ = cur_time;
                    }
                }
                if(time_!=999999)
                    dp[j][i] = time_;
                else dp[j][i] = -1;
            }
        }
        cout<<dp[h][d]<<endl;
    }
    return 0;
}