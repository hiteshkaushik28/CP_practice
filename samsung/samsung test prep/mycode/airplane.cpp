#include<iostream>
using namespace std;
int a[13][5];
int b[5][5];

void detonate(int row)
{
    for(int i = row; i > row - 5; --i)
    {
        for(int j = 0; j < 5; ++j)
        {
            b[row - i][j] = 0;
            if(i >= 0 && a[i][j] == 2)
            {
                b[row - i][j] = 2;
                a[i][j] = 0;
            }    
        }
    }
}

void undetonate(int row)
{
    for(int i = row; i > row - 5; --i)
    {
        for(int j = 0;j < 5; ++j)
        {
            if(i >= 0 && b[row - i][j] == 2)
                a[i][j] = 2;
        }
    }
}

void getMax(int pos, int curr_coins, int row, int &curr_max)
{
    if(pos < 0 || pos > 4 || curr_coins < 0) return;
    if(a[row][pos] == 2) curr_coins -= 1;
    else if(a[row][pos] == 1) curr_coins += 1;
    if(row == 0)
    {
        if(curr_coins > curr_max) curr_max = curr_coins;
        return;
    }
    getMax(pos + 1, curr_coins, row - 1, curr_max);
    getMax(pos - 1, curr_coins, row - 1, curr_max);
    getMax(pos, curr_coins, row - 1, curr_max);
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < 5; ++j)
                cin >> a[i][j];
        int res = -1;
        for(int row = n - 1; row >= 0; --row)
        {
            int temp_res = -1;
            detonate(row);
            getMax(2, 0, n - 1, temp_res);
            if(temp_res > res) res = temp_res;
            undetonate(row);
        }
        cout << endl << (res < 0 ? -1 : res)<< endl;
    }
    return 0;
}