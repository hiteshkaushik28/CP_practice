
#include<vector>
#include<iostream>
using namespace std;

int main()
{
    vector< vector<int> > vec(3, vector<int>(3,0));
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            // int temp;
            // cin>>temp;
            cin >> vec[i][j];
        }
    }

    for(int i = 0;i < 3;i++)
    {
        for(int j = i+1;j < 3 ;j++)
            swap(vec[i][j],vec[j][i]);
    }

    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}