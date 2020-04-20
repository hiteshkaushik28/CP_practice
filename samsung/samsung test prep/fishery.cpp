#include <iostream>
using namespace std;
int gate[3];
int fisher[3];
int n;
int visited[61];
int final_dist = 999999;

void score(int fish, int dist, int pos, int gatevisited[]){
    int k = 0;
    while(fish){
        if((pos+k)<=n and visited[pos+k] == 0){
            visited[pos+k] = 1;
            dist += k+1;
            fish--;
        }
        else if((pos-k)>0 && visited[pos-k]==0){
            visited[pos-k] = 1;
            dist+=k+1;
            fish--;
        }
        else
            k++;
    }
    int count =0;
    for(int i=0;i<3;i++){
        if(gatevisited[i]==1)
            count++;
    }
    if(count == 3){
        if(dist<final_dist)
            final_dist = dist;
            return;
    }

    for(int i=0;i<3;i++){
        int tmp[61];
        for(int j=0;j<61;j++){
            tmp[j] = visited[j];
        }
        gatevisited[i] = 1;
        score(fisher[i], dist, gate[i], gatevisited);
        gatevisited[i] = 0;
        for(int j = 0; j<61;j++)
            visited[j] = tmp[j];
    }

    if((pos-k)>0 && visited[pos-k] == 0 && (pos+k)<=n && visited[pos+k]==1){
        visited[pos-k] = 1;
        visited[pos+k] = 0;
        for(int i=0;i<3;i++){
            int temp[61];
            if(gatevisited[i]==0){
                for(int j=0;j<61;j++)
                    temp[j] = visited[j];
                gatevisited[i] = 1;;
                score(fisher[i], dist, gate[i], gatevisited);
                gatevisited[i] = 0;
                for(int j=0;j<61;j++)
                    visited[j] = temp[j];
            }
        }
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<3;i++)
            cin>>gate[i]>>fisher[i];
        int gatevisited[3] = {0};
        for(int i = 0;i<3;i++){
            for(int j=0;j<61;j++)
                visited[j] = 0;
            if(gatevisited[i] == 0){
                gatevisited[i] = 1;
                score(fisher[i],0,gate[i], gatevisited);
                gatevisited[i] = 0;
            }
        }
        cout<<final_dist<<"\n";
        final_dist = 9999999;
    }
}