#include <iostream>
using namespace std;

int map[16][13];
int cmap[16][13];
int n,w,h;
int ans=99999;
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

void blast(int i, int j, int k, int l){
    if(i!=-1){
        for(int a=0;a<h;a++){
            if(map[a][i]!=0){
                bomb(a,i);
                reconstruct();
                break;
            }
        }
    }
    if(j!=-1){
        for(int a=0;a<h;a++){
            if(map[a][j]!=0){
                bomb(a,j);
                reconstruct();
                break;
            }
        }
    }
    if(k!=-1){
        for(int a=0;a<h;a++){
            if(map[a][k]!=0){
                bomb(a,k);
                reconstruct();
                break;
            }
        }
    }
    if(l!=-1){
        for(int a=0;a<h;a++){
            if(map[a][l]!=0){
                bomb(a,l);
                reconstruct();
                break;
            }
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

void make_dup(){
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++)
            if(map[i][j]!=0) cmap[i][j] = map[i][j];
    }
}

void restore_orig(){
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++)
            map[i][j] = cmap[i][j];
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
        for(int i=0;i<w;i++){
            if(n==1){
                make_dup();
                blast(i, -1, -1,-1);
                calculaterem();
                restore_orig();
                continue;
            }
            for(int j = 0;j<w;j++){
                if(n==2){
                    make_dup();
                    blast(i, j, -1,-1);
                    //cout<<endl;
                    // for(int k1=0;k1<h;k1++){
                    //     for(int k2=0;k2<w;k2++){
                    //         cout<<map[k1][k2]<<" ";
                    //     }
                    //     cout<<endl;
                    // }
                    calculaterem();
                    //cout<<ans<<endl;
                    restore_orig();
                    continue;
                }
                for(int k = 0;k<w;k++){
                    if(n==3){
                        make_dup();
                        blast(i, j, k,-1);
                        calculaterem();
                        restore_orig();
                        continue;
                    }
                    for(int l = 0;l<w;l++){
                        if(n==4){
                            make_dup();
                            blast(i, j, k,l);
                            calculaterem();
                            restore_orig();
                            continue;
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}