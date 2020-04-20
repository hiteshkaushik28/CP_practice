#include <iostream>
using namespace std;

int adj[13][13];
int X[13];
int Y[13];
int W[5];
int V;
int visited[13];
int key[13];
int ans;

int getmin(){
    int min = 100000;
    int min_vertex;
    int i;
    for(i = 1;i<=V;i++){
        if(min>key[i] && visited[i]==0){
            min = key[i];
            min_vertex = i;
        }
    }
    return min_vertex;
}

int dijkstra(){
    int i;
    for(i=1;i<=V;i++)
        key[i]=100000;
    key[1]=0;
    for(int i=1;i<=V;i++){
        int u = getmin();
        visited[u]=1;
        for(int v=1;v<=V;v++){
            if(adj[u][v] && key[u]+adj[u][v]<key[v])
                key[v] = key[u] + adj[u][v];
        }
    }
    return key[2];
}

int interstellar(){
    for(int i=1;i<=V+1;i++){
        for(int j=1;j<=V+1;j++){
            adj[i][j] = ((X[i]-X[j])>0?X[i]-X[j]:X[j]-X[i]) + ((Y[i]-Y[j])>0?Y[i]-Y[j]:Y[j]-Y[i]);
            adj[j][i] = adj[i][j];
        }
    }
    int j=0;
    for(int i=3;i<V;){
        adj[i][i+1] = W[j];
        adj[i+1][i] = W[j++];
        i+=2;
    }
    return dijkstra();
}

int main(){
    int i=1;
    int n;
    cin>>n;
    cin>>X[i]>>Y[i++];
    cin>>X[i]>>Y[i++];
    V = 2*n+2;
    int k=0;
    for(int j=1;j<=n;j++){
        cin>>X[i]>>Y[i++];
        cin>>X[i]>>Y[i++]>>W[k++];
    }
    i=1;
    int j=2;
    int s_d = ((X[i]-X[j])>0?X[i]-X[j]:X[j]-X[i]) + ((Y[i]-Y[j])>0?Y[i]-Y[j]:Y[j]-Y[i]);
    cout<<s_d<<endl;
    if (n==0)
        ans = s_d;
    else
        ans = interstellar();
    cout<<ans<<"\n";
    return 0;   
}