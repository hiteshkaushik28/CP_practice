#include <iostream>
using namespace std;

int graph[11][11];
int path[11];
int vis[11];
int vert, edge;

bool dfs(int ind, int count){
    if(count == vert-1)
        return true;
    for(int i=0;i<vert;i++){
        if(graph[ind][i] && vis[i]==0){
            vis[i] = 1;
            if(dfs(i, count+1))
                return true;
            vis[i]=0;
        }
    }
}

void init(){
    for(int i=0;i<vert; i++)
        vis[i] =0;
}

bool solve(){
    for(int i=0;i<vert;i++){
        vis[i]=1;
        if(dfs(i, 0))
            return true;
        init();
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>vert>>edge;
        for(int i=0;i<edge;i++){
            int a,b;
            cin>>a>>b;
            graph[a-1][b-1]=1;
        }
        cout<<solve()<<"\n";
    }
}