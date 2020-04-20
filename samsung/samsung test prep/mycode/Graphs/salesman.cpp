#include <iostream>
using namespace std;

int n,m;
int arr[110][110];
int vis[110][110];
int dp[110][110];
int mov_x[4] = {0, 1, 0, -1};
int mov_y[4] = {1, 0, -1, 0};
void reset(int a[][110]){
    for(int i=0;i<110;i++)
        for(int j=0;j<110; j++)
            a[i][j]=0;
}

bool issafe(int x, int y){
    return x>=0 && y>=0 && x<n && y<m;
}
int traverse(int x, int y){
    //cout<<x<<" "<<y<<endl;
    if(!issafe(x, y) || arr[x][y]==0)
        return 0;
    //cout<<x<<" "<<y<<endl;
    if(vis[x][y])
        return -1;
    if(dp[x][y]>0)
        return dp[x][y];
    vis[x][y] = 1;
    int step = arr[x][y];
    int mxval = 0;
    for(int i = 0;i<4;i++){
        int val = traverse(x+step*mov_x[i], y + step*mov_y[i]);
        if(val == -1)
            return -1;
        if(mxval<val)
            mxval = val;
    }
    vis[x][y] = 0;
    return dp[x][y] = mxval+1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        reset(dp);
        reset(vis);
        reset(arr);
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cin>>arr[i][j];
        }
        cout<<traverse(0, 0)<<"\n";
    }

}