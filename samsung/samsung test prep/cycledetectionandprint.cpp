#include <iostream>
using namespace std;

int adj[100][100];
int status[10];
int parent[10];
int n,m;
bool cycle;

int arr[10];

void printcycle(int in, int des){
    if(in == des){
        arr[des] = 1;
        for(int i=0;i<10;i++){
            if(arr[i]==1)
                cout<<i<<" ";
        }
         return;
    }
    arr[in] = 1;
    printcycle(parent[in], des);
}

void dfsutil(int vert){
    status[vert] = 0;
    for(int i=0;i<n;i++){
        if(adj[vert][i]==1 && cycle == false){
            parent[i]=vert;
            if(status[i]==-1)
                dfsutil(i);
            else if(status[i]==0){
                cycle = true;
                printcycle(vert, i);
                return ;
            }
        }
    }
    status[vert] = 1;
}

void solve(){
    for(int i=0;i<10;i++){
        status[i] = -1;
        parent[i] = -1;
    }
    cycle = false;
    for(int i=0;i<n;i++){
        if(status[i] == -1){
            parent[i] = -1;
            dfsutil(i);
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int j=0;j<m;j++){
            int u,v;
            cin>>u>>v;
            adj[u][v] = 1;
        }
        solve();
    }
}