#include<iostream>
using namespace std;

int t, m, n, start_x, start_y, l, res;
int arr[1005][1005], visited[1005][1005];
int pipes[8][4] = {{0, 0, 0, 0}, 
                   {1, 1, 1, 1},
                   {0, 1, 0, 1},
                   {1, 0, 1, 0},
                   {0, 1, 1, 0},
                   {0, 0, 1, 1},
                   {1, 0, 0, 1},
                   {1, 1, 0, 0}};
int nbr[4][2] = {{0, -1},
                 {-1, 0},
                 {0, 1},
                 {1, 0}};
struct node
{
    int dx, dy, level;
    node* next;
    node(int x, int y, int d)
    {
        dx = x;
        dy = y;
        level = d;
        next = NULL;
    }
};

struct queue
{
    node* front, *rear;
};

struct queue* createqueue()
{
    queue* q = new queue;
    q->front = q->rear = NULL;
    return q; 
}

void enqueue(queue* q, int x, int y, int d)
{
    node* n = new node(x, y, d);
    if(q->rear)
        q->rear->next = n;
    q->rear = n;
    if(!q->front) q->front = q->rear;
}

struct node* dequeue(queue* q)
{
    if(!q->front) return NULL;
    node* tmp = q->front;
    if(q->front == q->rear)
        q->front = q->rear = NULL;
    else
        q->front = q->front->next;
    return tmp;
}

queue* Q = createqueue();

bool isvalid(int r, int c)
{
    return (r >= 1 && r <= m && c >= 1 && c <= n);
}
void solve()
{
    while(Q->front)
    {
        node* nn = dequeue(Q);
        int r = nn->dx;
        int c = nn->dy;
        int depth = nn->level;
        if(depth < l) res++;
        for(int i = 0; i < 4; ++i)
        {
            if(pipes[arr[r][c]][i])
            {
                int rr = r + nbr[i][0];
                int cc = c + nbr[i][1];
                if(isvalid(rr, cc) && !visited[rr][cc] && pipes[arr[rr][cc]][(i + 2) % 4])
                {
                    visited[rr][cc] = 1;
                    enqueue(Q, rr, cc, depth + 1);
                }
            }
        }
    }
}
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> m >> n >> start_x >> start_y >> l;
        start_x++;
        start_y++;
        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                cin >> arr[i][j];
                visited[i][j] = 0;
            }
        }
        res = 0;
        if(arr[start_x][start_y])
        {
            visited[start_x][start_y] = 1;
            enqueue(Q, start_x, start_y, 0);
            solve();
        }
        cout << res << endl;
    }
    return 0;
}