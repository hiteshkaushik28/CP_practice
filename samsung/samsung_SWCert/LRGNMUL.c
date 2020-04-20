#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

char *inp1, *inp2;
int *res;
#define SZ 32000
int main()
{
    freopen("inp.txt", "r", stdin);
    int t;
    char c;
    scanf("%d", &t);
    scanf("%c", &c);
    inp1 = (char*)malloc(SZ * sizeof(char));
    inp2 = (char*)malloc(SZ * sizeof(char));
    for(int tt = 1; tt <= t; ++tt)
    {
        int itr1 = 0;
        while(1)
        {
            scanf("%c", &c);
            if(c == '\n' || c == '\0' || c == '\r') break;
            else inp1[itr1++] = c;
        }
        inp1[itr1] = '\0';
        int itr2 = 0;
        while(1)
        {
            scanf("%c", &c);
            if(c == '\n' || c == '\0' || c == '\r') break;
            else inp2[itr2++] = c;
        }
        inp2[itr2] = '\0';

        res = (int*)malloc((itr1 + itr2) * sizeof(int));
        memset(res, 0, sizeof(int)* (itr1 + itr2));

        for(int i = itr1 - 1; i >= 0; --i)
        {
            for(int j = itr2 - 1; j >= 0; --j)
            {
                res[i + j + 1] += (inp1[i]  - '0') * (inp2[j] - '0');
                res[i + j] += res[i + j + 1] / 10;
                res[i + j + 1] %= 10;
            }
        }

        int idx = 0;
        for(int i = 0; i < itr1 + itr2; ++i)
        {
            if(res[i] == 0) continue;
            idx = i;
            break;
        
        }
        printf("#%d ", tt);
        for(int i = idx; i < itr1 + itr2; ++i) printf("%d", res[i]);
        printf("\n");
        free(res);
    }
    free(inp1);
    free(inp2);
    return 0;
}