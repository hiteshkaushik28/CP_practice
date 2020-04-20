#include <iostream>
using namespace std;
struct point{
    int x,y;
};
int mov[][2]={{0,-1}, {0,1}, {1,0}, {-1,0}};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        point *start = new point[n];
        point *end = new point[n];
        start[0].x = 0;
        start[0].y = 0;
        for(int i=0;i<n;i++){
            int dir, dis;
            cin>>dir>>dis;
            if(i==0){
                end[i].x = start[i].x+dis*mov[dir-1][0];
                end[i].y = start[i].y+dis*mov[dir-1][1];
            }
            else{
                start[i].x = end[i-1].x;
                start[i].y = end[i-1].y;
                end[i].x = end[i-1].x+ dis*mov[dir-1][0];
                end[i].y = end[i-1].y+dis*mov[dir-1][1];
            }
        }
        int track=-1,idx=-1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                // cout<<start[i].x<<" "<<start[i].y<<endl;
                // cout<<start[j].x<<" "<<start[j].y<<endl;
                if(start[j].x == end[j].x && start[i].y == end[i].y){
                    if((start[i].x<start[j].x && end[i].x>start[j].x) || (start[j].x>end[i].x && start[j].x<start[i].x)){
                        if((start[i].y>start[j].y && start[i].y<end[j].y) || (start[j].y>end[j].y && start[i].y<start[j].y)){
                            track = i+1;
                            idx = j;
                            break;
                        }
                    }
                 }
                else if(start[j].y==end[j].y && start[i].x==end[i].x){
                    if ((start[i].x>start[j].x && start[i].x<end[j].x) || (start[i].x>end[j].x && start[i].x<start[j].x) )
					{
						if((start[j].y>start[i].y && start[j].y<end[i].y) || (start[j].y>end[i].y && start[j].y<start[i].y) )
						{
							track=i+1;
							idx=j;
							break;
						}
					}
                }
                else if(start[i].y == end[i].y  && start[j].y == end[j].y && start[j].y == start[i].y){
                   // cout<<"hi"<<endl;
                    if((start[i].x>=start[j].x && end[i].x<=end[j].x) || (start[j].x>=start[i].x && end[j].x<=end[i].x)){
                        track = i+1;
                        idx = j;
                        break;
                    }
                }
                else if(start[i].x == end[i].x  && start[j].x == end[j].x && start[j].x == start[i].x){
                    //cout<<"hi"<<endl;
                    if((start[i].y>=start[j].y && end[i].y<=end[j].y) || (start[j].y>=start[i].y && end[j].y<=end[i].y)){
                        track = i+1;
                        idx = j;
                        break;
                    }
                }
            }
            if(track!=-1)
                break;
        }
        cout<<track<<endl;
    }
}