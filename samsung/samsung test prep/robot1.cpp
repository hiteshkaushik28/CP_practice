#include <iostream>
using namespace std;

int n;
int arr[101][5];
int dir, len;
int x11, y11, x12, y12, dir1, x21, y21, x22, y22, dir2;

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            arr[i][0] = arr[i-1][2];
            arr[i][1] = arr[i-1][3];
            cin>>dir>>len;
            if(dir == 1){
                arr[i][2] = arr[i][0];
                arr[i][3] = arr[i][1] + len;
                arr[i][4] = 1;
            }
            else if(dir == 2){
                arr[i][2] = arr[i][0];
                arr[i][3] = arr[i][1] - len;
                arr[i][4] = 1;
            }
            else if(dir == 3){
                arr[i][2] = arr[i][0] + len;
                arr[i][3] = arr[i][1];
                arr[i][4] = 0;
            }
            else if(dir == 4){
                arr[i][2] = arr[i][0] - len;
                arr[i][3] = arr[i][1];
                arr[i][4] = 0;
            }
        }
        int inter = 101;
        int over = 101;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                x11 = arr[i][0];
                y11 = arr[i][1];
                x12 = arr[i][2];
                y12 = arr[i][3];
                dir1= arr[i][4];
                x21 = arr[j][0];
                y21 = arr[j][1];
                x22 = arr[j][2];
                y22 = arr[j][3];
                dir2 = arr[j][4];
                if(dir1!=dir2){
                    if(dir2){
                        if( (x11<x22 && x22<x12 && y21<y11 && y22>y11) || (x11<x22 && x22<x12 && y11<y21 && y11>y22) || (x12<x21 && x11>x21 && y11>y21 && y11<y22) || (x12<x21 && x11>x21 && y11<y21 && y11>y22) ){
                            if(j<inter)
                                inter = j;
        
                        }
                    }
                    else{
                        if((x21<x11 && x22>x11 && y21>y11 && y21<y12) || (x21<x11 && x22>x11 && y21<y11 && y21>y12) || (x12>x21 && x22>x21 && y21>y11 && y21<y12) || (x12>x21 && x22>x21 && y21>y11 && y21<y11 && y21>y12)){
                            if(j<inter)
                                inter = j;
                        }
                    }
                }
                else{
                    if(!dir1){
                        if(y11==y21 && ( (x11<x21 && x21<x12) || (x12<x21 && x21<x11) || (x11<x22 && x22<x12) || (x12<x22 && x22<x11) || (x21<x11 && x11<x22)|| (x22<x11 && x11<x21) || (x21<x12 && x12<x22) || (x22<x12 && x12<x21))){
                            if(j<over)
                                over = j;
                        }
                    }
                    else{
                        if( x11==x21 && ( (y11<y21 && y21<y12) || (y12<y21 && y21<y11) || (y11<y22 && y22<y12) || (y12<y22 && y22<y11)
										|| (y21<y11 && y11<y22) || (y22<y11 && y11<y21) || (y21<y12 && y12<y22) || (y22<y12 && y12<y21) ) ){
											if(j<over)
												over=j;
										}
                    }
                }
            }
        }
        if(inter == 101 && over == 101)
            cout<<-1<<"\n";
        else if(inter<over)
            cout<<inter<<"\n";
        else
            cout<<over<<"\n";
    }
}