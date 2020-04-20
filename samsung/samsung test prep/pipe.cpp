#include <iostream>
using namespace std;

int m,n, x,y,l;
int mat[55][55];
int vis[55][55];
int level[55][55];
int val;
int mov[4][2] = {{0, -1}, {-1,0}, {0,1},{1,0}};
int pipes[8][4] = {{0,0,0,0}, {1,1,1,1}, {0,1,0,1}, {1,0,1,0}, {0,1,1,0}, {0,0,1,1}, {1,0,0,1}, {1,1,0,0}};
struct node{
    int data;
    struct node *next;
};

struct queue{
    node *front;
    node *rear;
};

struct node *newnode(int k){
    struct node *temp = new node;
    temp->data = k;
    temp->next = NULL;
    return temp;
}

struct queue* createqueue(){
    struct queue* q = new queue;
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(struct queue *q, int x){
    struct node* nn = newnode(x);
    if(q->rear)
        q->rear->next = nn;
    q->rear = nn;
    if(q->front == NULL)
        q->front = q->rear;
}

struct node *dequeue(struct queue *q){
    if(q->front==NULL)
        return NULL;
    struct node *tmp = q->front;
    if(q->front == q->rear){
        q->front = q->rear = NULL;
    }
    else
        q->front = q->front->next;
    return tmp;
}

struct queue* sx = createqueue();
struct queue* sy = createqueue();

bool isvalid(int x, int y){
    return (x>0 && y>0 && x<=m && y<=n);
}

void resetvisited(){
    for(int i=1;i<=m;i++)
        for(int j=0;j<=n;j++)
            vis[i][j] = 0;
}

void bfs(){
    while(sx->front!=NULL){
        struct node* tmpx = dequeue(sx);
        struct node* tmpy = dequeue(sy);
        int x1 = tmpx->data;
        int y1 = tmpy->data;
        cout << x1 << ", " << y1 << endl;
        int pipe = mat[x1][y1];
        int x2, y2;
        for(int i=0;i<4;i++){
            if(pipes[pipe][i] == 1){ //remember
                x2 = x1 + mov[i][0];
                y2 = y1 + mov[i][1];
                if(!vis[x2][y2] && isvalid(x2, y2) && pipes[mat[x2][y2]][(i+2)%4]==1){ // remember this line
                    level[x2][y2] = level[x1][y1] + 1;
                    if(level[x2][y2]<l){
                        val++;
                        vis[x2][y2] = 1;
                        enqueue(sx, x2);
                        enqueue(sy, y2);
                    }
                }
            }
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>m>>n>>x>>y>>l;
        x++;
        y++;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                cin>>mat[i][j];
                level[i][j] = 0;
            }
        }
        val = 0;
        resetvisited();
        if(mat[x][y]!=0){
            val++;
            vis[x][y] = 1;
            enqueue(sx, x);
            enqueue(sy, y);
            bfs();
        }
        cout<<val<<endl;
    }
}