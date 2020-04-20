#include <iostream>
using namespace std;
int arr[110][110];
int path[110];
int v, e;

bool issafe(int k, int pos){
    if(arr[path[pos-1]][k] == 0)
        return false;
    for(int i=0;i<pos;i++)
        if(path[i] == k)
            return false;
    return true;
}

bool hamcycleutil(int pos){
    if(pos == v){
        if(arr[path[pos-1]][path[0]] == 1)
            return true;
        else
            return false;
    }
    for(int i=1;i<v;i++){
        if(issafe(i, pos)){
            path[pos] = i;
            if(hamcycleutil(pos+1))
                return true;
            path[pos] = -1;
        }
    }
    return false;
}
void printsol(){
    for(int i = 0;i<v;i++)
        cout<<path[i]<<" ";
    cout<<path[0]<<"\n";
}
bool hamcycle(){
    for(int i=0;i<v;i++)
        path[i] = -1;
    path[0] = 0;
    if(hamcycleutil(1) == false)
        return false;
    printsol();
    return true;
}
void reset(){
    for(int i=0;i<100;i++)
        for(int j = 0;j<100;j++)
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
            arr[b][a] = 1;
        }
        if(!hamcycle())
            cout<<"No Hamcycle"<<endl;
    }
}