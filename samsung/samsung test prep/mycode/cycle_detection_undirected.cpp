#include<iostream>
#include<cstring>
using namespace std;

int m, n;
int graph[100][100];
int visited[100];
int nodes[100], parent[100];
bool has_cycle = false;

void print_cycle(int u, int v)
{
    nodes[u] = 1;
    if(u == v)
    {
        for(int i = 1; i <= m; ++i)
            if(nodes[i] == 1)
                cout << i << " ";
    }
    else
    {
        print_cycle(parent[u], v);    
    }
}
void dfs_util(int u)
{
    visited[u] = 1;
    for(int v = 1; v <= m; ++v)
    {
        if(graph[u][v] && !has_cycle)
        {
            if(!visited[v])
            {
                parent[v] = u;
                dfs_util(v);
            }
            else if(v != parent[u])
            {
                has_cycle = true;
                print_cycle(u, v);
            }
        }
    }
}

void reset()
{
    has_cycle = false;
    memset(visited, 0, sizeof(visited));
    memset(nodes, 0, sizeof(nodes));
    for(int i = 1; i <= m; ++i) parent[i] = -1;
}
void detect_cycle()
{
    for(int i = 1; i <= m; ++i)
    {
        if(!visited[i])
        {
            reset();
            parent[i] = -1;
            dfs_util(i);
        }
    }
}
int main()
{
    cin >> m >> n;
    for(int i = 0; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    detect_cycle();
    return 0;
}