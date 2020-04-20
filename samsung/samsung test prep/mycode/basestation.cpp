#include<iostream>
#include<stdbool.h>
#include<climits>
using namespace std;

int t, m, n;
int arr[100][100];
bool visited[100][100];
int nbh[6][2] = {{1, -1}, {-1, 1}, {2, 0}, {-2, 0}, {-1, -1}, {1, 1}};

bool valid(int i, int j)
{
    return (i >= 0 && i < 2*m && j >= 0 && j < n);
}
void chain_dfs(int r, int c, int curr, int depth, int &res)
{
    if(depth == 4)
        res = max(res, curr);
    else
    {
        visited[r][c] = true;
        for(int i = 0; i < 6; ++i)
        {
            int rr = r + nbh[i][0];
            int cc = c + nbh[i][1];
            if(valid(rr, cc) && !visited[rr][cc])
                chain_dfs(rr, cc, curr + arr[rr][cc], depth + 1, res);
        }
        visited[r][c] = false;
    }
}

int y_shape(int i, int j)
{
    if(valid(i - 1, j - 1) && valid(i - 1, j + 1) && valid(i + 2, j))
        return (arr[i][j] + arr[i - 1][j - 1] + arr[i - 1][j + 1] + arr[i + 2][j]);
    return -1;
}

int inverted_y_shape(int i, int j)
{
    if(valid(i + 1, j - 1) && valid(i + 1, j + 1) && valid(i - 2, j))
        return (arr[i][j] + arr[i + 1][j - 1] + arr[i + 1][j + 1] + arr[i - 2][j]);
    return -1;
}
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> m >> n;
        for(int i = 0; i < 2*m; i += 2)
        {
            int k = i;
            for(int j = 0; j < n; ++j)
            {
                cin >> arr[k][j];
                k = (k == (i + 1) ? i : i + 1);
            }
        }
        for(int i = 0; i < 2*m; ++i) for(int j = 0; j < n; ++j) visited[i][j] = false;

        int res = INT_MIN;
        for(int i = 0; i < 2*m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(arr[i][j])
                {
                    chain_dfs(i, j, arr[i][j], 1, res);
                    res = max(res, y_shape(i, j));
                    res = max(res, inverted_y_shape(i, j));
                }
            }
        }
        cout << endl << res;
    }
    return 0;
}