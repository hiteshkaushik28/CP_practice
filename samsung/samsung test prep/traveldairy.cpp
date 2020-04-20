#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#define debug(x) cout<<x<<endl
using namespace std;

int arr[1010][1010];
struct point{
    int x,y;
};
struct queue{
    int front, rear;
    int capacity;
    struct point *array;
};
 struct queue *createqueue(){
     struct queue *q = (struct queue *)malloc(sizeof(struct queue));
     q->capacity = 1000000;
     struct point *array = (struct point *)malloc(sizeof(struct point)*q->capacity);
     q->front = q->rear = -1;
     q->array = array;
     return q;
 }
 bool isemptyqueue(struct queue *q){
     return q->front == -1;
 }
 bool isfullqueue(struct queue *q){
     return (q->rear + 1)%q->capacity == q->front;
 }
struct point front(struct queue *q){
    return q->array[q->front];
}
 void enqueue(struct queue *q, int x1, int x2){
     if(isfullqueue(q)){
         cout<<"Memory Error"<<endl;
         exit(0);
     }
     q->rear = (q->rear+1)%q->capacity;
     q->array[q->rear].x = x1;
     q->array[q->rear].y = x2;
     if(q->front == -1)
        q->front = q->rear;
 }
 struct point dequeue(struct queue *q){
     if(isemptyqueue(q)){
        cout<<"Empty Queue"<<endl;
        return {0,0};
     }
     struct point data = q->array[q->front];
     if(q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front+1)%q->capacity;
    return data;
 }
 int cnt = 0;
 int visited[1010][1010];
 int depth[1010][1010];
 int dirx[] = {0, 1, 0, -1};
 int diry[] = {-1, 0, 1, 0};
 int n,m;
 int mx = 0;
 struct queue *q = createqueue();
 bool isvalid(int x, int y){
     return x>=0 && x<n && y>=0 && y<m;
 }
 int ans = 0;
 void bfs(){
     while(!isemptyqueue(q)){
         //debug(x1);
         bool flag = false;
         while(!(front(q).x ==-1 && front(q).y==-1)){
            struct point u = dequeue(q);
            int f1 = u.x;
            int f2 = u.y;
            // debug(f1);
            // debug(f2);
            for(int i=0;i<4;i++){
                if(isvalid(f1+dirx[i],f2+diry[i])  && arr[f1+dirx[i]][f2+diry[i]]==1 ){
                    if(!flag) ans++;
                    enqueue(q, f1+dirx[i],  f2+diry[i]);
                    arr[f1+dirx[i]][f2+diry[i]] = 2;
                    flag = true;
                }
            }
         }
        //debug(2);
        //debug(3);
        dequeue(q);

         if(!isemptyqueue(q)){
             enqueue(q,-1,-1);
         }
     }
     
 }
 int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //memset(depth, 0, sizeof(depth));
            //memset(visited, 0, sizeof(visited));
            if(arr[i][j]==2){
                enqueue(q, i,j);
            }
        }
    }
    //debug(1);
    enqueue(q,-1,-1);
    bfs();
    int f = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1){
                f = -1;
                break;
            }
        }
        //cout<<endl;
    }
    if(f==-1)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
    //cout<<mx<<endl;
 }