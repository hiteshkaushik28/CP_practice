#include<queue>
#include<vector>
#include<iostream>
using namespace std;

void util()
{
    int arr[4][4] = {{1,3,5,7},
                    {2,4,6,7},
                    {1,3,8,9},
                    {10,13,15,17}};
    int index[4] = {0};
    vector<int> res;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    for(int i = 0; i < 4; ++i)
    {
        Q.push({arr[i][0], i});
    }

    while(!Q.empty())
    {
        pair<int, int> p = Q.top();
        Q.pop();
        res.push_back(p.first);
        index[p.second]++;
        if(index[p.second] < 4) 
            Q.push({arr[p.second][index[p.second]], p.second});
    }

    for(auto it:res)
        cout << it << "\n";
}

int main()
{
    util();
    return 0;
}