#include <iostream>
using namespace std;

int dp[1000][5];
char mat[10000][5];
int move_[][2]={{1,0},{1,-1},{1,1}};
int ans = 0;
int add, kadhapos, row, u,v;
int t,h;

void solve(){
    for(kadhapos=h-1; kadhapos>0 || h<5;--kadhapos){
        ans = 0;
        for(int i=0;i<h+1;i++){
            for(int j=0;j<5;j++){
                dp[i][j] = -99999;
            }
        }
        dp[h][2] = 0;
        for(row=h-1;row>=0;--row){
            for(int j=0;j<5;j++){
                if(mat[row][j]=='R')
                    add=-1;
                else if(mat[row][j]=='S')
                    add=1;
                else add=0;
                if(kadhapos-row<5 && add==-1)
                    add=0;
                for(int k=0;k<3;k++){
                    u = row+move_[k][0];
                    v = j+move_[k][1];
                    if(v>=0 && v<5)
                        dp[row][j] = max(dp[row][j], dp[u][v]+add);
                }
            }
        }
        for(int i=0;i<5;i++)
            ans = max(dp[0][i], ans);
        if(h<5)
            break;
    }
    cout<<ans<<endl;
}

int main(){
    cin>>t;
	while(t--){
		int h;
		cin>>h;
		for(int i=0;i<h;++i){
			for(int j=0;j<5;++j){
				cin>>mat[i][j];
			}
		}
		solve();
	}
	return 0;
}