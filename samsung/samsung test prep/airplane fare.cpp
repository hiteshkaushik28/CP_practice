#include <stdio.h>
int input[15][15];
int G_cost = 0xFFFFFF;
int visited[15];

int calculate(int in, int n_cities, int cities_covered, int local_cost)
{
    int i, j;

    if (cities_covered >= n_cities && input[in][1])
    {
        if (local_cost + input[in][1] < G_cost)
        {
            G_cost = local_cost + input[in][1];
        }
        return 1;
    }

    if (local_cost > G_cost) return 1;


    for (j = 1; j <= n_cities; j++)
    {
        if (input[in][j] && !visited[j] && in != j)
        {
            visited[j] = 1;
            calculate(j, n_cities, cities_covered + 1, local_cost + input[in][j]);
            visited[j] = 0;

        }
    }

}

int main(void)
{
    int tc, T, i, j, fare;
    int num_cities = 0;

    scanf("%d", &T);
    for (tc = 0; tc < T; tc++)
    {
        G_cost = 0xFFFF;
        scanf("%d", &num_cities);

        for (i = 1; i <= num_cities; i++)
        {
            for (j = 1; j <= num_cities; j++)
            {
                scanf("%d", &fare);
                input[i][j] = fare;
            }
        }
        visited[1] = 1;
        calculate(1, num_cities, 1, 0);
        printf("%d\n", G_cost);
    }
    return 0;//Your program should return 0 on normal termination.
}
