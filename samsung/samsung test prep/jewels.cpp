#define MAXN 11
#include<stdio.h>
int N;
int map[MAXN][MAXN];
int visited[MAXN][MAXN];

int num_jewels;

int path[MAXN][MAXN];

void traverse(int x, int y, int jewel_cnt)
{
    int i, j;
    if (x<1 || x>N || y<1 || y>N || map[x][y] == 1 || visited[x][y])
        return;

    if (y == N && x == N)
    {
        if (num_jewels <= jewel_cnt)
        {
            num_jewels = jewel_cnt;

            //Take a snapshot of the path
            for (i = 1; i <= N; i++)
            {
                for (j = 1; j <= N; j++)
                {
                    if (visited[i][j] == 3)
                        path[i][j] = 3;
                    else
                        path[i][j] = map[i][j];
                }
            }
            path[x][y] = 3;
        }
        return;
    }

    visited[x][y] = 3;
    if (map[x - 1][y] == 2)
        traverse(x - 1, y, jewel_cnt + 1);
    else
        traverse(x - 1, y, jewel_cnt);
    if (map[x + 1][y] == 2)
        traverse(x + 1, y, jewel_cnt + 1);
    else
        traverse(x + 1, y, jewel_cnt);
    if (map[x][y - 1] == 2)
        traverse(x, y - 1, jewel_cnt + 1);
    else
        traverse(x, y - 1, jewel_cnt);
    if (map[x][y + 1] == 2)
        traverse(x, y + 1, jewel_cnt + 1);
    else
        traverse(x, y + 1, jewel_cnt);
    visited[x][y] = 0;
}

int main(void)
{
    int tc, T;

    //freopen("pick_jewel.txt","r",stdin);
    setbuf(stdout, NULL);
    scanf("%d", &T);

    for (tc = 0; tc<T; tc++)
    {
        int i, j;
        scanf("%d", &N);
        for (i = 1; i <= N; i++)
        {
            for (j = 1; j <= N; j++)
            {
                scanf("%d", &map[i][j]);
                path[i][j] = map[i][j];
                visited[i][j] = 0;
            }
        }
        num_jewels = 0;
        traverse(1, 1, 0);

        for (i = 1; i <= N; i++)
        {
            for (j = 1; j <= N; j++)
            {
                printf("%d ", path[i][j]);
            }
            printf("\n");
        }
        printf("%d\n\n", num_jewels);
    }
    return 0;
}
