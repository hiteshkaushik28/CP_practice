#include <iostream>
using namespace std;
int graph[100][100];
int n;
int vis[100][100];
int color[100][100];
int value[6];
int final_color[100];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1,-1,0,0};

bool issafe(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}

void dfs2(int x, int y){
    color[x][y] = 1;
    value[graph[x][y]] = value[graph[x][y]] + 1;

    for(int i = 0;i<4;i++){
        int n_x = x + dx[i];
        int n_y = y + dy[i];
        if(issafe(n_x, n_y) && color[n_x][n_y] == 0 && graph[n_x][n_y] == graph[x][y])
            dfs2(n_x,n_y);
    }
}
void dfs1(int x, int y){
    vis[x][y] = 1;
    for(int i=0;i<4;i++){
        int n_x = x + dx[i];
        int n_y = y + dy[i];
        if(issafe(n_x, n_y) && vis[n_x][n_y]==0 && graph[n_x][n_y]==0)
            dfs1(n_x, n_y);
    }

    for(int i=0;i<4;i++){
        int n_x = x + dx[i];
        int n_y = y + dy[i];
        if(issafe(n_x, n_y) && graph[n_x][n_y] != 0 && color[n_x][n_y] == 0)
            dfs2(n_x, n_y);
    }
}

void filling(int x, int y, int val){
    graph[x][y] = val;
    vis[x][y] = 1;
    for(int i=0;i<4;i++){
        int n_x = x + dx[i];
        int n_y = y + dy[i];
        if(issafe(n_x, n_y) && vis[n_x][n_y] == 0 && graph[n_x][n_y] == 0)
            filling(n_x, n_y, val);
    }
}

void calc(int x,int y, int val){
    vis[x][y] = 1;
    for(int i=0;i<4;i++){
        int n_x = x + dx[i];
        int n_y = y + dy[i];
        if(issafe(n_x, n_y) && vis[n_x][n_y] == 0 && graph[n_x][n_y] == val)
            calc(n_x, n_y, val);
    }
}

void init_val(){
    for(int i=0;i<6;i++)
        value[i] = 0;
}

void init_color(){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            color[i][j] = 0;
}

void init_vis(){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            vis[i][j] = 0;
}

void init_fin(){
    for(int i=0;i<100;i++)
        final_color[i] = 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i= 0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>graph[i][j];
        init_vis();
        init_fin();

        int ind = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                init_color();
                init_val();
                int final_max = 0;
                int final_max_i = 5;
                if(graph[i][j] == 0 && vis[i][j] == 0){
                    dfs1(i,j);
                    for(int k = 0;k<6;k++){
                        if(value[k]>= final_max){
                            final_max = value[k];
                            final_max_i = k;
                        }
                    }
                    final_color[ind++] = final_max_i;
                }
            }
        }
        init_vis();
        int ind_f = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][j] == 0 && vis[i][j] == 0 && ind_f<=ind)
                    filling(i, j, final_color[ind_f++]);
            }
        }
        init_vis();
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(vis[i][j]==0){
                    count++;
                    calc(i, j, graph[i][j]);
                }
            }
        }
        cout<<count<<endl;
    }
}