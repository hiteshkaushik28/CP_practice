#include <stdio.h>
#define MAX_ROW 25
#define MAX_COL 25
int N;
int data[MAX_ROW][MAX_COL];
int visited[MAX_ROW][MAX_COL];
int max_star_count;
int num_constellation;

int traverse(int i, int j)
{
    int star_count = 0;

    if (i < 0 || j < 0 || i >= MAX_ROW || j >= MAX_COL)
        return 0;

    if ((data[i][j] == 0) || visited[i][j])
        return 0;

    visited[i][j] = 1;
    star_count++;

    star_count += traverse(i, j + 1);
    star_count += traverse(i + 1, j);
    star_count += traverse(i, j - 1);
    star_count += traverse(i - 1, j);

    return star_count;

}

int main(void)
{
    int test_case;
    int T;
    scanf("%d", &T);
    for (test_case = 0; test_case < T; test_case++)
    {
        int i, j, temp;
        int S, C;

        int star_count = 0;
    
        N = 0;
        num_constellation = 0;
        max_star_count = 0;
        for (i = 0; i < MAX_ROW; i++)
        {
            for (j = 0; j < MAX_COL; j++)
            {
                data[i][j] = 0;
                visited[i][j] = 0;
            }
        }

        scanf("%d", &N);

        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                scanf("%d", &temp);
                data[i][j] = temp;
            }
        }
 
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if ((data[i][j] == 1) && (!visited[i][j]))
                {
                    num_constellation++;
                    star_count += traverse(i, j);
                }

                if (star_count > max_star_count)
                    max_star_count = star_count;
  
                star_count = 0;
            }
        }

        S = max_star_count;
        C = num_constellation;

        printf("%d %d\n", C, S);

    }
    return 0;
}
