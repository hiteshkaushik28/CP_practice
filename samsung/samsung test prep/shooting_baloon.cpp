#include <iostream>
using namespace std;
int baloon[12];

int score(int left, int right, int p){
    int max_score = 0;
    for(int j=left+1;j<right;j++){
        int cur_score = 0;
        cur_score = score(left, j, p) + score(j, right, p);
        if(left == 0 && right == p)
            cur_score+=baloon[j];
        else
            cur_score+=baloon[left]*baloon[right];
        if(cur_score>max_score)
            max_score = cur_score;
    }
    return max_score;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        baloon[0] = 1;
        baloon[n+1] = 1;
        for(int i=1;i<=n;i++)
            cin>>baloon[i];
        cout<<score(0, n+1, n+1)<<"\n";
    }
}