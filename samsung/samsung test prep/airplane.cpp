#include <iostream>
using namespace std;
int graph[13][5];
int temp[5][5];
int maxcoins;

void detonate(int row){
    for(int i=row; i>row-5;i--){
        for(int j=0; j<5;j++){
            temp[row-i][j] = 0;
            if(i>=0 && graph[i][j]==2){
                temp[row-i][j] = 2;
                graph[i][j] = 0;
            }
        }
    }
}

void undetonate(int row){
    for(int i=row;i>row-5;i--){
        for(int j=0;j<5;j++){
            if(i>=0 && temp[row-i][j]==2)
                graph[i][j] = 2;
        }
    }
}

void getmaxcoins(int pos, int coins, int row){
    if(pos<0 || pos>4 || coins<0)
        return;
    if(graph[row-1][pos]==2)
        coins-=1;
    else if(graph[row-1][pos]==1)
        coins+=1;
    if(row == 1){
        if(coins>maxcoins)
            maxcoins = coins;
        return;
    }
    else{
        getmaxcoins(pos+1, coins, row-1);
        getmaxcoins(pos-1, coins, row-1);
        getmaxcoins(pos, coins, row-1);
    }
}

int main(){
    int t;
    cin>>t;
    for(int test=1; test<=t;test++){
        int row;
        cin>>row;
        for(int i=0; i<row;i++){
            for(int j=0;j<5;j++){
                cin>>graph[i][j];
            }
        }
        for(int i=0;i<5;i++)
            graph[row][i] = 0;
        graph[row][2] = 3;
        maxcoins = -1;
        for(int j=row-1;j>0;j--){
            detonate(j);
            getmaxcoins(2,0, row);
            undetonate(j);
        }
        cout<<"#"<<test<<" "<<maxcoins<<"\n";
    }
}