#include <iostream>
using namespace std;

int arr[100][100];
int n_arr[100][100];
int m, n, k, ans;

void solve(){
    int n_sz = 0;
    if(k%2 == 0){
        for(int i=0;i<m;i++){
            int n_z = 0;
            for(int j=0;j<n;j++){
                if(!arr[i][j])
                    n_z++;
            }
            if(n_z%2==0 && n_z<=k){
                for(int j=0;j<n;j++)
                    n_arr[n_sz][j] = arr[i][j];
                n_sz++;
            }
        }
    }
    else{
        for(int i=0;i<m;i++){
            int n_z = 0;
            for(int j=0;j<n;j++){
                if(!arr[i][j])
                    n_z++;
            }
            if(n_z%2==1 && n_z<=k){
                for(int j=0;j<n;j++)
                    n_arr[n_sz][j] = arr[i][j];
                n_sz++;
            }
        }
    }
    for(int i=0;i<n_sz;i++){
        int count = 1;
        for(int j=i+1;j<n_sz;j++){
            int flag = 1;
            for(int k=0;k<n;k++){
                if(n_arr[i][k]!=n_arr[j][k]){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1)
                count++;
        }
        if(count>ans)
            ans = count;
    }
}
void reset(){
    for(int i = 0;i<100;i++)
        for(int j=0;j<100;j++)
            arr[i][j] = 0;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        reset();
        ans = -99999;
        cin>>m>>n>>k;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                cin>>arr[i][j];
        solve();
        cout<<ans<<"\n";
    }
}