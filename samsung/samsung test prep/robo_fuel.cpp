#include <iostream>
using namespace std;
#define SPOT 10
int arr[10];
int vis[10];
int n, mnm;
#define RIGHT 1
#define LEFT -1
#define GAS 1
#define DIESEL 2
#define NOTHING 0

void fill(int step, int dir, int fuel, int quantity, int count, int leftcars){
    //cout<<count<<endl;
    if(count == mnm)
        return;
    if(step == 0){
        fill(1, RIGHT, GAS, 2, count+1, leftcars);
        return;
    }
    if(step == SPOT-1){
        fill(SPOT-2, LEFT, DIESEL, 2, count+1, leftcars);
        return;
    }
    if(arr[step] == 0)
        fill(step+dir, dir, fuel, quantity, count, leftcars);

    if(arr[step] == fuel && !vis[step] && quantity>0){
        vis[step] = 1;
        if(leftcars == 1){
            vis[step] = 0;
            //cout<<count<<endl;
            if(count<mnm)
                mnm = count;
            return;
        }
        fill(step+dir, dir, fuel, quantity-1, count+1, leftcars-1);
        fill(step-dir, -(dir), NOTHING, 0, count+1, leftcars-1);
        vis[step] = 0;
        fill(step+dir, dir, fuel, quantity, count+1, leftcars);
    }
    else
        fill(step+dir, dir, fuel, quantity, count+1, leftcars);

}

void reset(int a[]){
    for(int i=0;i<10;i++){
        a[i] = 0;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        reset(vis);
        reset(arr);
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>arr[i];
        mnm = 99999;
        fill(0, RIGHT, GAS, 2, 0, n);
        //cout<<mnm<<endl;
        //reset(vis);
        // for(int i=1;i<=n;i++)
        //     cout<<vis[i]<<" ";
        fill(0, RIGHT, NOTHING, 2, 0, n);
        cout<<mnm<<endl;
    }
    
}