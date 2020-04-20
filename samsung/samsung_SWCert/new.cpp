#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SZ 32000  
 
char intToChar(int num) 
{
  return (num + '0');
}

int charToInt(char c) 
{
  return (c - '0');
}

void add_zeros(char* a, int n)
{
  int lena = strlen(a);
  for (int i = lena - 1 + n; i >= n; --i)
  {
    a[i] = a[i - n];
  }
  a[lena + n] = 0;
  for (int i = 0; i < n; ++i)
  {
    a[i] = '0';
  }
}
 
void remove_zeros(char* a)
{
  int lena = strlen(a);
  int ind = 0;
  while (ind < lena && a[ind] == '0')
  {
    ++ind;
  }
  for (int i = ind; i < lena; ++i)
  {
    a[i - ind] = a[i];
  }
  a[lena - ind] = 0;
}
 
void add(char* a, char* b, char* res)
{
  int lena = strlen(a);
  int lenb = strlen(b);
 
  if (lena < lenb)
  {
    char *tmp = a;
    a = b;
    b = tmp;
    int t = lena;
    lena = lenb;
    lenb = t;
  }
 
  int toAdd = 0;
  for (int inda = lena - 1, indb = lenb - 1; inda >= 0; --inda, --indb)
    {
        int x = a[inda] - '0';
        int y = indb >= 0 ? b[indb] - '0' : 0;
 
        int cur = x + y + toAdd;
 
        if (cur >= 10)
        {
          toAdd = 1;
          cur -= 10;
        }
        else
        {
          toAdd = 0;
        }
 
        res[inda] = cur + '0';
    }
 
  if (toAdd == 1)
  {
    add_zeros(res, 1);
    res[0] = '1';
  }
}

void sub(char* a, char* b, char* res)
{
  int lena = strlen(a);
  int lenb = strlen(b);
 
  int toSub = 0;
  for (int inda = lena - 1, indb = lenb - 1; inda >= 0; --inda, --indb)
  {
    int x = a[inda] - '0';
    int y = indb >= 0 ? b[indb] - '0' : 0;
 
    if (toSub == 1)
    {
      x--;
    }
    int cur;
    if (x < y)
    {
      cur = x + 10 - y;
      toSub = 1;
    }
   else
   {
      cur = x - y;
      toSub = 0;
   }
 
    res[inda] = cur + '0';
  }
}

void karatsubaDivide(char* a, int n)
{
  int lena = strlen(a);
  if (lena == 1 && a[0] == '0')
  {
    return;
  }
  for (int i = lena; i < lena + n; ++i)
  {
    a[i] = '0';
  }
  a[lena + n] = 0;
}
 
char* memAlloc(int len)
{
  char *res = (char*)malloc(len * sizeof(char));
  memset(res, 0, len);
  return res;
}
 
void pad_zero(char* a, char* b)
{
  int lena = strlen(a);
  int lenb = strlen(b);
  int n = (lena > lenb ? lena : lenb);
  add_zeros(a, n - lena);
  add_zeros(b, n - lenb);
}
 
void multiply(char* inp1, char* inp2, char* res)
{
  pad_zero(inp1, inp2);
  int len = strlen(inp1);
  if (len == 1)
  {
    int prod = charToInt(inp1[0]) * charToInt(inp2[0]);
    if (prod < 10)
    {
      res[0] = intToChar(prod);
    }
    else
    {
        res[0] = intToChar(prod / 10);
        res[1] = intToChar(prod % 10);
    }
  }
  else
  {
    char* xleft = memAlloc(len);
    char* xright = memAlloc(len);
    char* yleft = memAlloc(len);
    char* yright = memAlloc(len);
 
    int rightSize = len / 2;
    int leftSize = len - rightSize;
 
    strncpy(xleft, inp1, leftSize);
    strcpy(xright, inp1 + leftSize);
    strncpy(yleft, inp2, leftSize);
    strcpy(yright, inp2 + leftSize);
    int maxl = 3 * len;
    char* P1 = memAlloc(maxl);
    char* P2 = memAlloc(maxl);
    char* P3 = memAlloc(maxl);
 
    multiply(xleft, yleft, P1);
    multiply(xright, yright, P2);
 
    char* tmp1 = memAlloc(maxl);
    char* tmp2 = memAlloc(maxl);
    add(xleft, xright, tmp1);
    add(yleft, yright, tmp2);
    multiply(tmp1, tmp2, P3);
    sub(P3, P1, P3);
    sub(P3, P2, P3);
    karatsubaDivide(P3, rightSize);
    karatsubaDivide(P1, 2 * rightSize);
    add(P1, P2, res);
    add(res, P3, res);
    remove_zeros(res);
 
    free (xleft);
    free (xright);
    free (yleft);
    free (yright);
    free (tmp1);
    free (tmp2);
    free (P1);
    free (P2);
    free (P3);
  }
}

void read_blank()
{
  char tmp;
  scanf("%c", &tmp);
}

int main()
{
  freopen("inp.txt", "r", stdin);
  int t;
  char blank;
  scanf("%d", &t);
  read_blank();
  char inp1[SZ], inp2[SZ];
  for(int tt = 1; tt <= t; ++tt)
  {
    read_blank();
    scanf("%s", inp1);
    read_blank();
    scanf("%s", inp2);

    char* res = memAlloc(SZ);
    multiply(inp1, inp2, res);
    printf("#%d %s", tt, res);
    if(tt < t) printf("\n\n");
  }
  return 0;
}