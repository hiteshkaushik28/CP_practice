#include<iostream>
using namespace std;

int D, E, F, d, e, n, t, res;
int arr[9][4];

void solve(int model_no, int model_cnt, int cpu, int mem, int board, int profit)
{
    // if we have taken 3 models or we have seen all the models, then update the answer
    if(model_cnt == 3 || model_no == n + 1)
    {
        if((profit + cpu * d + mem * e) > res)
            res = profit + cpu * d + mem * e;
        return;
    }

    // dont take this model, go to next one
    solve(model_no + 1, model_cnt, cpu, mem, board, profit);

    // include this model
    if((arr[model_no][0] * d + arr[model_no][1] * e) < arr[model_no][3])
    {
        int c = cpu, m = mem, b = board, p = profit;
        
        // make as many products as possible
        while(arr[model_no][0] <= c && arr[model_no][1] <= m && arr[model_no][2] <= b)
        {
            c -= arr[model_no][0];
            m -= arr[model_no][1];
            b -= arr[model_no][2];
            p += arr[model_no][3];
            solve(model_no + 1, model_cnt + 1, c, m, b, p);
        }
    }
    
}
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> D >> E >> F >> d >> e;
        cin >> n;
        for(int i = 1; i <= n; ++i)
        {
            cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
        }
        res = 0;
        solve(1, 0, D, E, F, 0);
        cout << "######## : " << res << endl;
    }
    return 0;
}