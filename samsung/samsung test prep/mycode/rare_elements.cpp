/*Test cases
5
5 2
4 3
3 4
1 1 0 0 0
1 1 0 0 0
1 1 1 1 1
1 1 1 0 1
1 1 1 1 1
8 2
5 6
6 4
1 1 1 1 1 1 0 0
1 1 1 1 1 1 1 0
1 1 0 1 0 1 1 0
1 1 1 1 0 1 1 0
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
10 3
8 2
5 3
7 1
0 0 0 1 1 1 1 1 1 0
1 1 1 1 1 1 1 1 1 0
1 0 0 1 0 0 0 0 1 0
1 1 1 1 1 1 1 1 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 0 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
15 4
11 15
15 9
1 2
14 3
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 1 0 0 0 1 1 1 1 1 1 1 0 1
0 0 1 1 1 1 1 1 1 1 1 1 1 1 1
20 4
13 6
20 4
1 2
17 16
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0

Output
#1 1
#2 2
#3 2
#4 12
#5 15
*/
#include<iostream>
using namespace std;

int t, row, col, rare;
int matrix[20][20], visited[20][20], cost[20][20], rare_loc[5][2];
int nbr[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

struct node
{
    int dx, dy, cost;
    node* next;
    node(int x, int y, int c)
    {
        dx = x;
        dy = y;
        cost = c;
        next = NULL;
    }
};

struct queue
{
    node* front, *rear;
};

queue* createqueue()
{
    queue* q = new queue;
    q->front = q->rear = NULL;
    return q;
}
void enqueue(queue* q, int x, int y, int c)
{
    node* n = new node(x, y, c);
    if(q->rear)
        q->rear->next = n;
    q->rear = n;
    if(!q->front) q->front = q->rear;
}

node* dequeue(queue* q)
{
    if(!q->front) return NULL;
    node* tmp = q->front;
    if(q->front == q->rear)
        q->front = q->rear = NULL;
    else
        q->front = q->front->next;
    return tmp;
}

void reset()
{
    for(int i = 0; i < 20; ++i)
    {
        for(int j = 0; j < 20; ++j)
        {
            visited[i][j] = 0;
        }
    }
}

bool isvalid(int r, int c)
{
    return (r >= 0 && r < row && c >= 0 && c < col && !visited[r][c] && matrix[r][c]);
}

int bfs(int x, int y)
{
    queue* Q = createqueue();
    int ans = 0;
    visited[x][y] = 1;
    enqueue(Q, x, y, 0);
    while(Q->front)
    {
        node* nn = dequeue(Q);
        int r = nn->dx;
        int c = nn->dy;
        int cost = nn->cost;
        if(matrix[r][c] == 2 && ans < cost) ans = cost;
        for(int i = 0; i < 4; ++i)
        {
            int rr = r + nbr[i][0];
            int cc = c + nbr[i][1];
            if(isvalid(rr, cc))
            {
                visited[rr][cc] = 1;
                enqueue(Q, rr, cc, cost + 1);
            }
        }
    }
    return ans;
}

int solve()
{
    for(int i = 0; i < rare; ++i)
    {
        int x = rare_loc[i][0];
        int y = rare_loc[i][1];
        matrix[x][y] = 2;
    }
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            if(matrix[i][j])
            {
                reset();
                cost[i][j] = bfs(i, j);
            }
        }
    }

    int min_cost = (int)1e9;
    for(int i = 0; i < 20; ++i)
        for(int j = 0; j < 20; ++j)
            if(cost[i][j] != -1 && cost[i][j] < min_cost)
                min_cost = cost[i][j];
    return min_cost;
}

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> row >> rare;
        col = row;
        for(int i = 0; i < rare; ++i)
            cin >> rare_loc[i][0] >> rare_loc[i][1];

        for(int i = 0; i < row; ++i)
            for(int j = 0; j < col; ++j)
                cin >> matrix[i][j];
        for(int i = 0; i < 20; ++i)
            for(int j = 0; j < 20; ++j)
                cost[i][j] = -1;

        int res = solve();
        cout << "###########" << res << endl;
    }
    return 0;
}