#include<iostream>
#include<climits>
using namespace std;

int t, n, nump;
int gate[4], fisher[4];
int visited[4];
int permutations[50];

int abs(int r)
{
    if(r >= 0) return r;
    return -r;
}

void gen_permute(int cnt, int num)
{
    if(cnt == 3)
        permutations[nump++] = num;
    else
    {
        for(int i = 1; i <= 3; ++i)
        {
            if(!visited[i])
            {
                visited[i] = 1;
                if(fisher[i] % 2 == 0)
                {
                    gen_permute(cnt + 1, num * 100 + i * 10 + 7);
                    gen_permute(cnt + 1, num * 100 + i * 10 + 9);
                }
                else
                {
                    gen_permute(cnt + 1, num * 100 + i * 10 + 8);
                }
                visited[i] = 0;
            }
        }
    }
    
}

void fill_spots(int gatenum, int b, int spots[])
{
    int num = fisher[gatenum];
    int loc = gate[gatenum];
    char bias;
    if(b == 7) bias = 'L';
    else if(b == 8) bias = 'N';
    else bias = 'R';
    while(num)
    {
        int l_index = -1, r_index = -1;
        for(int i = loc; i >= 1; --i)
        {
            if(spots[i] == -1)
            {
                l_index = i;
                break;
            }
        }
        for(int i = loc; i <= n; ++i)
        {
            if(spots[i] == -1)
            {
                r_index = i;
                break;
            }
        }

        int l_dist = abs(l_index - loc);
        int r_dist = abs(r_index - loc);
        if(l_index == -1 || r_dist < l_dist)
        {
            spots[r_index] = gatenum;
            num--;
            continue;
        }
        if(r_index == -1 || l_dist < r_dist)
        {
            spots[l_index] = gatenum;
            num--;
            continue;
        }
        if(l_dist == r_dist)
        {
            if(l_dist == 0)
            {
                spots[l_index] = gatenum;
                num--;
                continue;
            }
            if(num >= 2)
            {
                spots[l_index] = spots[r_index] = gatenum;
                num -= 2;
            }
            else if(num == 1)
            {
                if(bias == 'L')
                    spots[l_index] = gatenum;
                else
                    spots[r_index] = gatenum;
                num--;
            }
        }
    }
}
int calc_cost(int spots[])
{
    int cost = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(spots[i]==1)
        {
            cost += abs(i-gate[1])+1;
        }
        if(spots[i]==2){
            cost += abs(i-gate[2])+1;
        }
        if(spots[i]==3){
            cost += abs(i-gate[3])+1;
        }
    }
    return cost;
}
int eval(int num)
{
    int spots[n + 1];
    for(int i = 1; i <= n; ++i) spots[i] = -1;
    int arr[6] = {0};
    for(int i = 5; i >= 0; --i)
    {
        arr[i] = num % 10;
        num /= 10;
    }
    for(int i = 0; i < 6; i += 2)
    {
        fill_spots(arr[i], arr[i + 1], spots);
    }
    return calc_cost(spots);
}
int main()
{
    cin >> t;
    for(int c = 1; c <= t; ++c)
    {
        int res = 1e9;
        cin >> n;
        for(int i = 1; i <= 3; ++i)
        {
            cin >> gate[i] >> fisher[i];
        }
        for(int i = 1; i <= 3; ++i) visited[i] = 0;
        gen_permute(0, 0);
        for(int i = 0; i < nump; ++i)
        {
            int tmp = (int)eval(permutations[i]);
            res = min(res, tmp);
        }
        cout << "#" << c << " " << res << endl;
    }
    return 0;
}