#include<cmath>
#include<climits>
#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

void check(int x, int cost, int &closest, int &total_cost)
{
    if(abs(x - cost) < closest)
    {
        closest = abs(x - cost);
        total_cost = cost;
    }
    else if(abs(x - cost) == closest && total_cost > cost)
    {
        total_cost = cost;
    }   
}

int main()
{
    // freopen("task1-test-input.txt", "r", stdin);
    // freopen("out1_actual.txt", "w", stdout);
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; ++tt)
    {
        int x, n, m;
        cin >> x >> n;
        vector<int> flavor_price(n);
        string flavor;
        int price;
        for(int i = 0; i < n; ++i)
        {
            cin >> flavor >> flavor_price[i];
        }

        cin >> m;
        vector<int> option_price(m);
        for(int i = 0; i < m; ++i)
        {
            cin >> flavor >> option_price[i];
        }


        int closest = INT_MAX, total_cost = 0;
        for(int i = 0; i < n; ++i)
        {
            int cost = flavor_price[i];
            check(x, cost, closest, total_cost);

            for(int j = 0; j < m; ++j)
            {
                int temp1 = cost + option_price[j];
                check(x, temp1, closest, total_cost);

                for(int k = j + 1; k < m; ++k)
                {
                    int temp2 = temp1 + option_price[k];
                    check(x, temp2, closest, total_cost);
                }
            }
        }
        cout << "Case #" << tt << ": " << total_cost << endl;
    }

    return 0;
}