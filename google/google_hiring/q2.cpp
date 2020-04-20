#include <iostream>
#include <vector>
#include <queue>
#include<stdio.h>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj_list;

public:
    Graph(int V)
    {
        this->V = V;
        adj_list.resize(V+1);
    }

    void add_edge(int u, int v)
    {
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int BFT(int src_node)
    {
        int distance = -1;
        queue<int> q;
        q.push(src_node);
        vector<bool> visited(V+1, false);
        while (!q.empty())
        {
            ++distance;
            int q_len = q.size();
            for (int i = 0; i < q_len; ++i)
            {
                int u = q.front(); q.pop();
                visited[u] = true;
                for (auto v_itr = adj_list[u].begin(); v_itr != adj_list[u].end(); ++v_itr)
                {
                    if (!visited[*v_itr])
                        q.push(*v_itr);
                }
            }
        }
        return distance;
    }
};

int main()
{
    // freopen("task2-test-input.txt", "r", stdin);
    // freopen("out2_actual.txt", "w", stdout);
    int T;
    cin >> T;

    for (int tt = 1; tt <= T; ++tt)
    {
        int V;
        cin >> V;

        Graph g(V);
        int u, v;
        for (int edge = 1; edge <= V-1; ++edge) {
            cin >> u >> v;
            g.add_edge(u, v);
        }
        int min_distance = V;
        for (int node = 1; node <= V; ++node)
            min_distance = min(g.BFT(node), min_distance);
        
        cout << "Case #" << tt << ": " << min_distance << endl;
    }
    return 0;
}
