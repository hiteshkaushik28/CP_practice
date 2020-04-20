#include <iostream>
using namespace std;
int arr[110][110];
int vis[110];
int rec[110];
int parent[110];
int v, e;
int k=0;

void print(int in, int des){
    if(in == des)
        cout<<in<<" ";
    else{
        print(parent[in], des);
        cout<<in<<" ";
    }
}

bool iscyclicutil(int s){
    if(!vis[s]){
        vis[s] = true;
        rec[s] = true;
        for(int i=0;i<v;i++){
            if(arr[s][i]){
                parent[i] = s;
                if(arr[s][i] && !vis[i] && iscyclicutil(i)){
                    //parent[k++] = i;
                    return true;
                }
                else if(arr[s][i] && rec[i]){
                    //parent[k++] = i;
                    //printcycle(s, i);
                    print(s,i);
                    return true;
                }
            }
        }
    }
    rec[s] = false;
    return false;
}

bool hascycle(){
    for(int i=0;i<v;i++){
        vis[i] = 0;
        rec[i] = 0;
        parent[i] = -1;
    }
    for(int i=0;i<v;i++){
        if(iscyclicutil(i)){
            //parent[k++] = i;
            return true;
        }
    }
    return false;
}

void reset(){
    for(int i=0;i<110;i++)
        for(int j=0;j<110;j++)
            arr[i][j] = 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        reset();
        cin>>v>>e;
        for(int i=0;i<e;i++){
            int a,b;
            cin>>a>>b;
            arr[a][b] = 1;
            //arr[b][a] = 1;
        }
        if(hascycle()){
            cout<<endl;
            cout<<"Has Cycle"<<endl;
            // int k1 = 0;
            // for(int i = 0;i<k;i++){
            //     parent[k1++] = parent[i];
            //     //cout<<parent[i]<<" ";
            //     if(parent[i] == parent[0] && i!=0)
            //         break;
            // }
            // for(int i=k1-1;i>=0;i--)
            //     cout<<parent[i]<<" ";
        }
        else
            cout<<"No cycle"<<endl;
        //cout<<endl;
    }
}