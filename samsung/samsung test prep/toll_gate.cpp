#include <iostream>
using namespace std;
#define debug(x) cout<<x<<"\n";
int n, cost[50], people[50];
int min_cost = 10000007;
void dfs(int ind, int three_life, int two_life, int one_life, int price){
    //debug(ind)
    if(price>min_cost)
        return;
    int avl_men = three_life  + two_life + one_life;
    if(ind == n-1){
        if(avl_men<people[ind])
            price+=cost[ind];
        if(price<min_cost)
            min_cost = price;
        return;
    }  
    dfs(ind+1, three_life, two_life, one_life, price+cost[ind]);
    dfs(ind+1, three_life+people[ind], two_life, one_life, price + 2*cost[ind]);

    if(avl_men>=people[ind]){
        int rem_2_life = 0;
        int rem_1_life = 0;
        if(people[ind]>=(two_life+one_life))
            three_life = avl_men - people[ind];
        if(people[ind]>=one_life)
            two_life = people[ind]-one_life>=two_life?0:two_life-people[ind]+one_life;
        dfs(ind+1, 0, three_life, two_life, price);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>people[i]>>cost[i];
        dfs(0,0,0,0, 0);
        cout<<min_cost<<"\n";
        min_cost = 10e7;
    }
}