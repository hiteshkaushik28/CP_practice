#include <iostream>
using namespace std;
char arr[100][100];
int sz[100][100];
int tmp[100][100];
int n,m;
//#define min(a,b) a>b?b:a
void reset(int a[][100]){
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            a[i][j] = 0;
}
int solve(){
    for(int i=0;i<n;i++){
        if(arr[i][0] == '_' || arr[i][0]=='?')
            sz[i][0] = 1;
        else
            sz[i][0] = 0;
    }
    for(int i=0;i<m;i++){
        if(arr[0][i] == '_' || arr[0][i]=='?')
            sz[0][i] = 1;
        else
            sz[0][i] = 0;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(arr[i][j] == '_' || arr[i][j]=='?'){
                //cout<<i<<" "<<j<<"\n";
                sz[i][j] = min(min(sz[i][j-1], sz[i-1][j]),sz[i-1][j-1])+1;
            }
            else 
                sz[i][j] = 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            tmp[i][j] = -1;
            //cout<<sz[i][j]<<" ";
        //cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x = sz[i][j];
            //if(arr[i][j]=='_'){
                for(int k1 = i-x+1;k1<=i;k1++)
                    for(int k2 = j-x+1;k2<=j;k2++)
                        tmp[k1][k2] = x;
            //}
        }
    }
    int mn = 99999999;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            if(mn>tmp[i][j] && tmp[i][j]!=-1 && arr[i][j]=='_')
                mn = tmp[i][j];
            //cout<<tmp[i][j]<<" ";
        //cout<<endl;
    }
    return mn;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        //reset(arr);
        reset(sz);
        reset(tmp);
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        cout<<solve()<<"\n";
        //cout<<endl;
    }
    return 0;
}