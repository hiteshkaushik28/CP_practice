#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

char *inp1, *inp2;
char *res;
#define SZ 32000
int main()
{
    freopen("inp.txt", "r", stdin);
    int t;
    char c, blank;
    scanf("%d", &t);
    scanf("%c", &blank);
    inp1 = (char*)malloc(SZ * sizeof(char));
    inp2 = (char*)malloc(SZ * sizeof(char));
    for(int tt = 1; tt <= t; ++tt)
    {
        int itr1 = 0;
        scanf("%c", &blank);
        scanf("%s", inp1);
        itr1 = strlen(inp1);
    
        int itr2 = 0;
        scanf("%c", &blank);
        scanf("%s", inp2);
        itr2 = strlen(inp2);

        res = (char*)malloc((itr1 + itr2) * sizeof(char));
        for(int i = 0; i < (itr1 + itr2); ++i) res[i] = '0';

        for(int i = itr1; i >= 1; --i)
        {
            int carry = 0;
            for(int j = itr2; j >= 1; --j)
            {
                int sum = (inp1[i - 1]- '0') * (inp2[j - 1] - '0'); 
                sum += res[i + j - 1] - '0';
                sum += carry;
                res[i + j - 1] = (sum % 10) + '0';
                carry = sum / 10;
            }
            res[i - 1] = carry + '0';
        }

        int idx = 0;
        for(int i = 0; i < (itr1 + itr2); ++i)
        {
            if(res[i] == '0') continue;
            idx = i;
            break;
        
        }
        printf("#%d ", tt);
        for(int i = idx; i < (itr1 + itr2); ++i) printf("%c", res[i]);
        if(tt < t) printf("\n\n");
    }

    return 0;
}