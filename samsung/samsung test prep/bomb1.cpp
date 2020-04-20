#include <iostream>
using namespace std;

int map[16][13];
int cmap[16][13];
int n,w,h;
int ans=9999999;
int dx[] = {0,-1, 0 , 1};
int dy[] = {-1, 0, 1 , 0};

bool issafe(int x, int y){
    return x>=0 && x<h && y>=0 && y<w;
}

void bomb(int x, int y){
    int tmp = map[x][y];
    map[x][y] = -1;
    for(int k=1;k<tmp;k++){
        for(int i = 0;i<4;i++){
            int tmpx = x + k*dx[i];
            int tmpy = y + k*dy[i];
            if(issafe(tmpx, tmpy))
                bomb(tmpx, tmpy);
        }
    }
}

void reconstruct(){
    for(int j=0;j<w;j++){
        for(int i=0;i<h;i++){
            if(map[i][j]==-1){
                int tmp = i;
                for(int k=i-1;k>=0;k--){
                    map[i--][j] = map[k][j];
                    map[k][j] = 0;
                }
                i = tmp;
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(map[i][j] == -1) map[i][j] = 0;
        }
    }
}

void calculaterem(){
    int count  = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(map[i][j]!=0) count++;
        }
    }
    if(count < ans) ans = count;
}

void solve(int count){
    if(count == 0){
        // cout<<endl;
        // for(int i=0;i<h;i++){
        //     for(int j=0;j<w;j++){
        //         cout<<map[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        calculaterem();
        //cout<<ans<<endl;
        //restore_orig();
        return ;
    }
    // cout<<endl;
    // for(int i=0;i<h;i++){
    //     for(int j=0;j<w;j++){
    //         cout<<map[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=0;i<w;i++){
        for(int j=0;j<h;j++){
            if(map[j][i]!=0){
                int tmp[h][w];
                for(int k1=0;k1<h;k1++)
                    for(int k2=0;k2<w;k2++)
                        tmp[k1][k2] = map[k1][k2];
                bomb(j,i);
                reconstruct();
                solve(count-1);
                for(int k1=0;k1<h;k1++)
                    for(int k2=0;k2<w;k2++)
                        map[k1][k2] = tmp[k1][k2];
                //restore_orig();
                break;
            }
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>w>>h;
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
                cin>>map[i][j];
        solve(n);
        cout<<ans<<endl;
    }
    return 0;
}