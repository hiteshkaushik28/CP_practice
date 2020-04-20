/* *******TEST CASES ************
3
5
5 5 1 4 4 
4 0 2 4 2
5 0 0 2 0 
5 4 3 0 1
1 3 3 2 1
10
1 3 5 1 4 0 0 4 2 1
1 1 2 1 1 0 5 0 2 1
5 0 2 0 4 4 4 0 1 1
0 2 2 4 0 5 4 2 1 3
1 1 2 2 2 3 3 2 1 1
5 1 1 2 0 3 3 2 2 1
3 1 1 1 0 0 1 2 2 5
3 1 4 1 2 0 4 0 0 5
4 0 3 3 1 3 3 0 0 1
5 0 3 1 4 3 3 1 2 3
20
0 2 1 0 1 3 3 3 3 4 4 1 1 1 4 1 1 4 1 4
0 2 3 5 1 2 3 3 3 3 4 2 1 3 2 2 1 1 1 3
0 2 1 5 1 2 2 2 0 3 2 3 4 2 1 3 3 0 1 1
1 5 4 5 1 2 5 5 5 5 2 5 5 2 0 0 3 3 5 4
1 0 5 5 3 5 3 0 4 5 5 5 1 0 1 1 3 4 0 0
4 5 3 4 4 5 3 3 0 0 3 3 1 3 1 3 2 5 0 0
3 2 0 0 0 3 4 1 1 1 1 3 5 2 1 3 1 4 0 5
2 2 0 2 3 3 3 0 1 5 1 3 5 2 5 3 4 4 0 5
3 4 0 1 1 1 0 4 4 4 4 1 5 0 4 5 3 4 4 4
3 2 0 1 4 4 3 0 0 0 3 5 1 0 1 4 1 3 4 4
0 3 1 1 1 1 1 1 2 2 3 3 1 0 5 4 4 4 4 4
4 2 5 3 4 4 4 1 2 5 5 5 4 1 1 1 4 1 0 5
4 2 5 1 4 2 5 2 0 1 5 2 4 1 4 1 1 0 0 0
1 2 3 0 1 4 2 2 4 1 1 0 4 4 4 5 4 1 0 0
3 2 0 1 1 1 2 1 3 1 0 4 1 4 4 2 4 3 3 0
3 3 5 4 1 1 1 1 3 2 4 4 4 4 4 3 3 3 3 4
4 3 1 1 1 1 1 1 1 3 2 2 0 5 4 4 4 5 0 0
3 3 2 0 5 0 3 3 1 3 2 4 0 4 0 4 4 2 4 4
1 4 4 3 4 5 2 4 4 4 4 4 0 5 0 4 0 3 1 0
5 4 4 5 2 3 3 0 0 5 2 4 3 3 2 3 4 4 5 0

OUTPUT:
#1: 11
#2: 31
#3: 130
*/

#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;

int t, m;
int grid[100][100];
int store[100][100];
bool visited[100][100];
int nbr[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isvalid(int i, int j)
{
    return (i >= 0 && i < m && j >= 0 && j < m);
}

int second_dfs(int r, int c)
{
    visited[r][c] = 1;
    int count = 1;
    for(int i = 0; i < 4; ++i)
    {
        int rr = r + nbr[i][0];
        int cc = c + nbr[i][1];
        if(isvalid(rr, cc) && !visited[rr][cc] && grid[rr][cc] == grid[r][c])
            count += second_dfs(rr, cc);
    }
    return count;
}
int first_dfs(int r, int c, int famous[])
{
    visited[r][c] = 1;
    for(int i = 0; i < 4; ++i)
    {
        int rr = r + nbr[i][0];
        int cc = c + nbr[i][1];
        if(isvalid(rr, cc) && !visited[rr][cc] && grid[rr][cc] >= 1 && grid[r][c] <= 5)
        {
            famous[grid[rr][cc]] += second_dfs(rr, cc);
        }
    }
    for(int i = 0; i < 4; ++i)
    {
        int rr = r + nbr[i][0];
        int cc = c + nbr[i][1];
        if(isvalid(rr, cc) && !visited[rr][cc] && !grid[rr][cc])
            famous[first_dfs(rr, cc, famous)]++;
    }
    int model = 5, count = famous[5];
    for(int i = 4; i > 0; --i)
    {
        if(famous[i] > count)
        {
            count = famous[i];
            model = i;
        }
    }
    store[r][c] = model;
    grid[r][c] = -1;
    return model;
}

void third_dfs(int r, int c)
{
    visited[r][c] = 1;
    for(int i = 0; i < 4; ++i)
    {
        int rr = r + nbr[i][0];
        int cc = c + nbr[i][1];
        if(isvalid(rr, cc) && !visited[rr][cc] && grid[rr][cc] == grid[r][c])
            third_dfs(rr, cc);
    }
}
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> m;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < m; ++j)
                cin >> grid[i][j];

        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(!grid[i][j])
                {
                    memset(visited, 0, sizeof(visited));
                    int famous[6] = {0};
                    first_dfs(i, j, famous);
                }
            }
        }

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < m; ++j)
                if(grid[i][j] == -1) grid[i][j] = store[i][j];

        int res = 0;
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(!visited[i][j])
                {
                    res++;
                    third_dfs(i, j);
                }
            }
        }
        cout << "\n" << res;
    }
    return 0;
}