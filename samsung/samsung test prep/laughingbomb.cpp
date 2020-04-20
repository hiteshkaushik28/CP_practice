#include <stdio.h>
#define MAX_SIZE 101
int citymap[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int Answer;
int row_size = 0;
int col_size = 0;
int bomb_row, bomb_col;

void traverse(int row, int col, int cur_value)
{
    if ((row < 1) || (row > row_size) || (col < 1) || (col > col_size))
        return;

    if (citymap[row][col] == 0)
        return;
        
    if (visited[row][col])
    {
        if(citymap[row][col] > cur_value)
        {
            citymap[row][col] = cur_value;
        }
        else
        {
            return;
        }
    }
    else
    { 
        visited[row][col] = 1;
        citymap[row][col] = cur_value;
    }

    traverse(row, col+1, cur_value + 1);
    traverse(row+1, col, cur_value + 1);
    traverse(row, col-1, cur_value + 1);
    traverse(row-1, col, cur_value + 1);

    return;
}

int main(void)
{
    int tc, T;

    int i, j;

    scanf("%d", &T);
    for (tc = 0; tc < T; tc++)
    {
        row_size = 0;
        col_size = 0;

        bomb_row = 0;
        bomb_col = 0;

        for (i = 0; i < MAX_SIZE; i++)
        {
            for (j = 0; j < MAX_SIZE; j++)
            {
                citymap[i][j] = 0;
                visited[i][j] = 0;
            }
        }

        Answer = 0;

        scanf("%d", &col_size);
        scanf("%d", &row_size);


        for (i = 1; i <= row_size; i++)
        {
            for (j = 1; j <= col_size; j++)
            {
                scanf("%d", &citymap[i][j]);
            }
        }

        scanf("%d %d", &bomb_col, &bomb_row);
        citymap[bomb_row][bomb_col] = 1;
        traverse(bomb_row, bomb_col,1);
        

        
        for (i = 1; i <= row_size; i++)
        {
            for (j = 1; j <= col_size; j++)
            {
                if (Answer < citymap[i][j])
                    Answer = citymap[i][j];
            }
            
        }

        printf("%d \n", Answer);
    }

    return 0;
}
