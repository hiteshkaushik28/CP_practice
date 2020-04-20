#include <iostream>
using namespace std;

int n, h, v;
int banana[20];
int mat[20][500];
int m1,c1,r1;
int m2,c2,r2;
int final_min_cost;

void score(int init_start, int rem, int cost, int used){
    if(cost>final_min_cost)
        return;
    if(used == n){
        if(cost<final_min_cost)
            final_min_cost = cost;
        return;
    }
    for(int i=init_start;i<=(v-2*(rem-1));i++){
        if(used == 0)
            cost+=banana[i];
        else
            cost+=banana[i] + (m1*m1+m2*m2)*(i-(init_start - 2));
        score(i+2, rem-1, cost, used+1);
    }
}

void tunneling_cost(){
    for(int i=1;i<=v;i++){
        int min = 99999;
        int k1,k2;
        for(k1=1;k1<=h;k1++){
            k2=h-k1;
            int cost=0;
            for(int j=1;j<=k1;j++)
                cost+=mat[i][j]*c1;
            for(int j=h;j>k1;j--)
                cost+=mat[i][j]*c2;
            if(k1>k2)
                cost+=(k1-k2)*r1;
            else if(k2>k1)
                cost+=(k2-k1-1)*r2;
            if(min>=cost)
                min = cost;
        }
        banana[i] = min;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>h>>v;
        for(int i=0;i<20;i++)
            for(int j=0;j<20;j++)
                mat[i][j]=0;
        for(int i=1;i<=v;i++)
            for(int j=1;j<=h;j++)
                cin>>mat[i][j];
        for(int i = 0;i<20;i++)
            banana[i]=0;
        cin>>c1>>r1>>m1;
        cin>>c2>>r2>>m2;
        final_min_cost = 999999;
        tunneling_cost();
        score(1, n, 0, 0);
        cout<<final_min_cost<<"\n";
    }
}