#include <iostream>
using namespace std;

int matrix[100][100];
int vis[100][100];
int row, col;
int row_n[4] = {1, -1, 0, 0};
int col_n[4] = {0, 0, 1, -1}; // remember

bool issafe(int r, int c){
    return r>0 && r<=row && c>0 && c<=col; 
}

bool possible(int dst_r, int dst_c, int level){
    //cout<<dst_r<<" "<<dst_c<<endl;
    if(dst_r == row)
        return true;
    for(int k = 0; k<(2+2*level);k++){
        int t_r, t_c;
        if(k<4){
            t_r = dst_r + row_n[k];
            t_c = dst_c + col_n[k];
        }
        else{
            t_c = dst_c;
            t_r = dst_r +(k/2)*row_n[k%2]; //remember
        }
        if(issafe(t_r, t_c)){
            if(matrix[t_r][t_c]==1 && vis[t_r][t_c] == 0){
                //cout<<t_r<<" "<<t_c<<endl;
                vis[t_r][t_c] = 1;
                if(possible(t_r, t_c, level))
                    return true;
            }
        }
    }
    return false;
}

void init(){
    for(int i=0;i<=row; i++)
        for(int j=0;j<=col;j++)
            vis[i][j] = 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>row>>col;
        for(int i=1;i<=row;i++)
            for(int j=1;j<=col;j++)
                cin>>matrix[i][j];
        int ans = 0;
        int dst_r, dst_c;
        cin>>dst_r>>dst_c;
        dst_r+=1;
        dst_c+=1;
        int level = 1;
        if(dst_r!=row){
            while(level!=row){
                init();
                if(possible(dst_r, dst_c,level)){
                    ans = level;
                    break;
                }
                level++;
            }
        }
        cout<<ans<<"\n";
    }
}