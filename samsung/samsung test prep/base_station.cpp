#include <iostream>
using namespace std;

int row, col;
int graph[20][20];
int vis[20][20];
int final_ans = -999999;
int odd_col[6] = {1,1,0,-1,-1,0};
int odd_row[6] = {0,1,1,1,0,-1};
int even_col[6] = {1,0,-1,-1,0,1};
int even_row[6] = {0,1,0,-1,-1,-1};

bool issafe(int r, int c){
    return r>=0 && r<row && c>=0 && c<col;
}

void dfs(int row1, int col1, int count, int total){
    if(count == 0){
        if(total>final_ans)
            final_ans = total;
        return;
    }
    if(col1%2==0){
        for(int i=0;i<6;i++){
            int temp_row = row1 + even_row[i];
            int temp_col = col1 + even_col[i];
            if(issafe(temp_row, temp_col) && vis[temp_row][temp_col]==0){
                vis[temp_row][temp_col] = 1;
                dfs(temp_row, temp_col, count-1, total + graph[temp_row][temp_col]);
                dfs(row1, col1, count-1, total+graph[temp_row][temp_col]);  //Considers all neighbours
                vis[temp_row][temp_col] = 0;
            }
        }
    }
    else{
        for(int i=0;i<6;i++){
            int temp_row = row1 + odd_row[i];
            int temp_col = col1 + odd_col[i];
            if(issafe(temp_row, temp_col) && vis[temp_row][temp_col]==0){
                vis[temp_row][temp_col] = 1;
                dfs(temp_row, temp_col, count-1, total + graph[temp_row][temp_col]);
                dfs(row1, col1, count-1, total+graph[temp_row][temp_col]);
                vis[temp_row][temp_col] = 0;
            }
        }
    }
}

void reset(){
    for(int i=0;i<row;i++)
        for(int j = 0; j<col;j++)
            vis[i][j] = 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>row>>col;
        for(int i=0;i<row;i++){
            for(int j=;j<col;j++){
                cin>>graph[i][j];
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                for(int i=0;i<row;i++)
                    for(int j = 0; j<col;j++)
                        vis[i][j] = 0;
                vis[i][j] = 1;
                dfs(i, j, 3, graph[i][j]);
                vis[i][j] = 0;
            }
        }
        cout<<final_ans<<"\n";
        final_ans = -9999999;
    }
}