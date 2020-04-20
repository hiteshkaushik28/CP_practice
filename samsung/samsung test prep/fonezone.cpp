#include <iostream>
#include <cstring>
using namespace std;

#define size 101

int traversed[size][size];
int visited[size][size];
int map_[size][size];
int cctype[100001];
int ccsize[100001];
int neighbor[10001][10001];
int neigh[][2] = {{1,0},{0,1},{0,-1},{-1,0}};
int t, cc=0,n,m;

void calculate(int u, int type, int &noofcctype, int &noofelementoftypeneigh){
    for(int i=1;i<=cc;i++){
        if(i!=u && neighbor[u][i]==1 && cctype[i]==type){
            noofelementoftypeneigh+=ccsize[i];
            noofcctype++;
        }
    }
}

void dfs(int u, int v, int n, int m, int cc){
    traversed[u][v]=1;
    for(int i=0;i<4;i++){
        int x = u + neigh[i][0], y=v+neigh[i][1];
        if(x>=0 && y>=0 && x<n && y<m){
            if(visited[x][y]==0 && map_[x][y]==cctype[cc] && traversed[x][y]==0){
                visited[x][y] = cc;
                ccsize[cc]++;
                dfs(x,y,n,m,cc);
            }
        }
    }
}

int main(){
    cin>>t;
    while(t--){
        //cout<<"#"<<t<<endl;
        cc=0;
        memset(visited,0,sizeof(visited));
		memset(map_,0,sizeof(map_));
		memset(neighbor,0,sizeof(neighbor));
        cin>>n>>m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>map_[i][j];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0){
                    cc++;
                    visited[i][j]=cc;
                    ccsize[cc] = 1;
                    cctype[cc] = map_[i][j];
                    memset(traversed,0,sizeof(traversed));
                    dfs(i,j,n,m,cc);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<4;k++){
                    int x = i+neigh[k][0], y = j+neigh[k][1];
                    if(x>=0 && y>=0 && x<n && y<m){
                        neighbor[visited[i][j]][visited[x][y]]=1;
                    }
                }
            }
        }
        int deductcc=0;
        for(int i=1;i<=cc;i++){
            //cout<<ccsize[i]<<" ";
            if(cctype[i]==0){
                int maxnofelementstypeneigh=-1, maxnoofccoftype=-1, noofelementsoftypeneigh, noofcctype;
                for(int type=1;type<6;type++){
                    noofelementsoftypeneigh=0;
                    noofcctype=0;
                    calculate(i, type, noofcctype, noofelementsoftypeneigh);
                    if(noofelementsoftypeneigh>=maxnofelementstypeneigh){
                        maxnofelementstypeneigh=noofelementsoftypeneigh;
                        maxnoofccoftype=noofcctype;
                    }
                }
                if(maxnofelementstypeneigh>0){
                    deductcc+=maxnoofccoftype;
                    //cout<<maxnoofccoftype<<endl;
                }
            }
        }
        //cout<<endl;
        //cout<<cc<<endl;
        cout<<cc-deductcc<<"\n";
    }
    return 0;
}