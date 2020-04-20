#include <stdio.h>
#define INF 999999
#define MAX_SIZE 51
int chessmap[MAX_SIZE][MAX_SIZE];
int rowsize = 0;
int colsize = 0;
int Answer = 0;
int start_x = 0;
int start_y = 0;
int end_x = 0;
int end_y = 0;


void traverse(int i, int j, int counter)
{
    if ((i < 1) || (j < 1) || (i > rowsize) || (j > colsize))
        return;
        
    if ((i == end_x) && (j == end_y))
    {
        if (counter < Answer)
            Answer = counter;
        return;
    }

    if (counter > Answer)
        return;

    if (chessmap[i][j] > 0)
    {
        if (chessmap[i][j] > counter)
            chessmap[i][j] = counter;
        else
            return;
    }

    chessmap[i][j] = counter;

    traverse(i + 2, j + 1, counter + 1);
    traverse(i + 2, j - 1, counter + 1);

    traverse(i - 2, j + 1, counter + 1);
    traverse(i - 2, j - 1, counter + 1);

    traverse(i + 1, j + 2, counter + 1);
    traverse(i - 1, j + 2, counter + 1);

    traverse(i + 1, j - 2, counter + 1);
    traverse(i - 1, j - 2, counter + 1);

    return;
}

int main(void)
{
    int tc, T;
    int i, j;
    scanf("%d", &T);
    for (tc = 0; tc < T; tc++)
    {
        rowsize = 0;
        colsize = 0;
        Answer = INF;
        start_x = 0;
        start_y = 0;
        end_x = 0;
        end_y = 0;

        for (i = 0; i < MAX_SIZE; i++)
        {
            for (j = 0; j < MAX_SIZE; j++)
            {
                chessmap[i][j] = 0;
            }
        }
        
        scanf("%d", &rowsize);
        scanf("%d", &colsize);

        scanf("%d %d", &start_x, &start_y);
        scanf("%d %d", &end_x, &end_y);

        traverse(start_x, start_y, 0);

        printf("%d \n", Answer);
    }
    return 0;
}
