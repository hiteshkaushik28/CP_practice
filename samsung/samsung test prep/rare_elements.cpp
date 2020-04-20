#include <iostream>
using namespace std;

int pos[4][2];
int mat[20][20];
int graph[500][500];
int maxx = 99999;

int dx[4] = {1,0,-1,0};
int dy[4] = {0, 1, 0, -1};

int n, c, v;
int solve(){
    int ans = 999999;
    int dp[v+1][v+1];
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++)
            dp[i][j] = graph[i][j];
    }
    for(int k=1;k<=v;k++){
        for(int i=1;i<=v;i++){
            for(int j=1;j<=v;j++){
                if(dp[i][j] > dp[i][k] + dp[k][j])
                    dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int tmp=0;
            for(int k=0;k<c;k++){
                int dist = dp[(i-1)*n + j][(pos[k][0]-1)*n + pos[k][1]];
                if(dist>tmp)
                    tmp = dist;
            }
            if(tmp<ans)
                ans=tmp;
        }
    }
    return ans;
}

void init_mat(){
    for(int i=0;i<20;i++)
        for(int j=0;j<20;j++)
            mat[i][j]=0;
}

void init_graph(){
    for(int i=1;i<500;i++)
        for(int j=0;j<500;j++)
            graph[i][j] = 100000;
}

bool issafe(int x, int y){
    return x>0 && x<=n && y>0 && y<=n;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>c;
        for(int i=0;i<c;i++){
            cin>>pos[i][0]>>pos[i][1];
        }
        v=n*n;
        init_mat();
        for(int i=1;i<=n;i++){
            for(int j =1;j<=n;j++)
                cin>>mat[i][j];
        }
        init_graph();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                graph[(i-1)*n + j][(i-1)*n + j] = 1;
                if(mat[i][j]){
                    for(int k=0;k<4;k++){
                        int n_x = i+dx[k];
                        int n_y = j+dy[k];
                        if(mat[n_x][n_y] == 1 and issafe(n_x,n_y))
                            graph[(i-1)*n + j][(n_x-1)*n+n_y] = 1;
                    }
                }
            }
            cout<<solve()<<"\n";
        }
    }
}