#include <iostream>
using namespace std;

int req[9][4];
int maxprofit;
int D,E,F, d,e, N;

void score(int step, int count, int cpus, int mem, int boards, int profit){
    if(count == 3 || step==N+1){
        if((profit + cpus*d + mem*e)>maxprofit)
            maxprofit = profit + cpus*d + mem*e;
        return ;
    }
    score(step+1, count, cpus, mem, boards, profit);

    int j = step;
    if((req[j][0]*d + req[j][1]*e)< req[j][3]){
        int la = cpus, lb = mem, lc = boards, sm = profit;
        while((req[j][0]<=la) && (req[j][1]<=lb) && (req[j][2]<=lc)){
            la = la - req[j][0];
            lb = lb - req[j][1];
            lc = lc - req[j][2];
            sm += req[j][3];
            score(step+1, count+1, la,lb, lc, sm);
        }
    }

    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int count = 0;
        cin>>D>>E>>F>>d>>e;
        cin>>N;
        for(int j=1;j<=N;j++)
            cin>>req[j][0]>>req[j][1]>>req[j][2]>>req[j][3];
        maxprofit = 0;
        score(1,0, D,E, F,0);
        cout<<maxprofit<<endl;
    }
}