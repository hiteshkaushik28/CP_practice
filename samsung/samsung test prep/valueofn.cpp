/* 
Problem - FIND VALUE OF n
given a function fn = a*n + b*n*log2(n) + c*n^3
and values of a, b, c, k where k is some fn find the value of n;

for example if a = 2, b = 1, c = 1;
f1 = 2 + 1 = 3;
f2 = 14 etc etc

so if test case is 

2 1 1 14
output should be 2;

*/


#include <iostream>
using namespace std;
long long ans=0, a,b,c,k;

long long log2int(int x){
    if (x == 1)
        return 0;
    return log2int(x/2) + 1;
}

long long solve(long long a, long long b, long long c, long long n){
    long long a1=0,b1=0,c1=0;
    if(a!=0)
        a1 = (long long)(((long long)a)*((long long) n));
    if(b!=0)
        b1 = (long long)(((long long)b)*((long long) n) * ((long long)log2int(n)));
    if(c!=0)
        c1 = (long long)(((long long)c)*((long long) n) * ((long long) n) * ((long long) n));
    long long res = a1 + b1 + c1;
    return res;
}

int main(){
    int t = 10;
    while(t--){
        cin>>a>>b>>c>>k;
        long long max_ = 10000000000000000007;
        long long min_ = 1;
        int flag = 0;
        while(min_<=max_){
            long long mid = min_ + (max_-min_)/2;
            long long res = solve(a, b, c, mid);
            if(res == k){
                ans = mid;
                break;
            }
            else if(res>k || res<0)
                max_ = mid -1;
            else if(res<k)
                min_ = mid+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}