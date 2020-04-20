#include <bits/stdc++.h>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;
#define opt ios_base::sync_with_stdio(0)
#define lli long long int
#define ulli unsigned long long int
#define I int
#define S string
#define D double
#define rep(i,a,b) for(i=a;i<b;i++)
#define repr(i,a,b) for(i=a;i>b;i--)
#define in(n) scanf("%lld",&n)
#define in2(a,b) scanf("%lld %lld",&a,&b)
#define in3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define out(n) printf("%lld\n",n)
#define inu(a) scanf("%lld",&a)
#define outu(a) printf("%llu",a)
#define ins(s) scanf("%s",&s)
#define outs(s) printf("%s",s)
#define mod 1000000007
#define inf 100000000000000
typedef long long       ll;
typedef pair<lli,lli>  plli;
typedef vector<lli>     vlli;
typedef vector<ulli>    vulli;
typedef vector<ll>      vll;
typedef vector<string>  vs;
typedef vector<plli>     vplli;
#define MM(a,x)  memset(a,x,sizeof(a));
#define ALL(x)   (x).begin(), (x).end()
#define P(x)       cerr<<"{"#x<<" = "<<(x)<<"}"<<endl;
#define P2(x,y)       cerr<<"{"#x" = "<<(x)<<", "#y" = "<<(y)<<"}"<<endl;
#define P3(x,y,z)  cerr<<"{"#x" = "<<(x)<<", "#y" = "<<(y)<<", "#z" = "<<(z)<<"}"<<endl;
#define P4(x,y,z,w)cerr<<"{"#x" = "<<(x)<<", "#y" = "<<(y)<<", "#z" = "<<(z)<<", "#w" = "<<(w)<<"}"<<endl;
#define PP(x,i)     cerr<<"{"#x"["<<i<<"] = "<<x[i]<<"}"<<endl;
#define TM(a,b)     cerr<<"{"#a" -> "#b": "<<1000*(b-a)/CLOCKS_PER_SEC<<"ms}\n";
#define UN(v)    sort(ALL(v)), v.resize(unique(ALL(v))-v.begin())
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define sz() size()
#define nl cout<<"\n"
#define MX1 100005
#define MX2 1000005
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
lli dx[]={0,0,-1,1,-1,-1,1,1};
lli dy[]={1,-1,0,0,1,-1,-1,1};
lli power(lli a,lli b)
    {
    lli value;
    if(b==0)
        {
        return 1;
    }
    else if(b%2==0)
        {
        value=power(a,b/2)%mod;
        return(value*value)%mod;
    }
    else
        {
        value=power(a,b/2)%mod;
        return ((a*value)%mod*(value))%mod;
    }
}
struct node
{
    lli sum,prefix,suffix,ans;
};
node tree[400005];
lli a[100004],max_start_here[100005],max_end_here[100005],max_pre[100005],max_suf[100005],b[100005];
node combine(node n1,node n2)
{
    node temp;
    if(n1.sum==-inf)
    {
        return n2;
    }
    if(n2.sum==-inf)
    {
        return n1;
    }
    temp.sum=n1.sum+n2.sum;
    temp.prefix=max(n1.prefix,n1.sum+n2.prefix);
    temp.suffix=max(n2.suffix,n2.sum+n1.suffix);
    temp.ans=max(n1.ans,max(n2.ans,n1.suffix+n2.prefix));
    return temp;
}
void build(lli n,lli s,lli e)
{
    if(s==e)
    {
        tree[n].prefix=a[s];
        tree[n].sum=a[s];
        tree[n].suffix=a[s];
        tree[n].ans=a[s];
    }
    else
    {
        lli mid=(s+e)/2;
        build(2*n,s,mid);
        build(2*n+1,mid+1,e);
        tree[n]=combine(tree[2*n],tree[2*n+1]);
    }
}
node query(lli n,lli s,lli e,lli l,lli r)
{
    if(s>e or e<l or s>r)
    {
        return {-inf,-inf,-inf,-inf};
    }
    if(s>=l and e<=r)
    {
        return tree[n];
    }
    lli mid=(s+e)/2;
    node n1=query(2*n,s,mid,l,r);
    node n2=query(2*n+1,mid+1,e,l,r);
    node ne=combine(n1,n2);
    return ne;
}
int main()
{
        #ifndef ONLINE_JUDGE
     //   freopen("input09.txt","r",stdin);
     //   freopen("output09.txt","w",stdout);
        #endif*/
    opt;
    lli t;
    cin >> t;
    while(t--)
    {
        lli n,i,q;
        cin>>n;
        rep(i,1,1+n)
        {
            cin>>a[i];
            b[i]=a[i];
        }
        rep(i,1,1+n)
        {
            b[i]=b[i-1]+a[i];
        }
        max_end_here[1]=a[1];
        rep(i,2,1+n)
        {
            max_end_here[i]=max(a[i],max_end_here[i-1]+a[i]);
        }
        max_start_here[n]=a[n];
        repr(i,n-1,0)
        {
            max_start_here[i]=max(a[i],a[i]+max_start_here[i+1]);
        }
        max_pre[1]=max_end_here[1];
        rep(i,2,1+n)
        {
            max_pre[i]=max(max_pre[i-1],max_end_here[i]);
        }
        max_suf[n]=max_start_here[n];
        repr(i,n-1,0)
        {
            max_suf[i]=max(max_suf[i+1],max_start_here[i]);
        }
        build(1,1,n);
        lli res = INT_MIN;
        string op = "NONE";
        lli max_so_far = INT_MIN;
        lli max_ending_here = 0;
        for (int i = 1; i <= n; i++)
        {
            max_ending_here = max(max_ending_here + a[i], (lli)0);
            max_so_far = max(max_ending_here, max_so_far);
        }
        res = max_so_far;
        for(int itr = 1; itr <= n; ++itr)
        {
            lli l,r;
            l = 1, r = itr;
            // cin>>l>>r;
            node n1=query(1,1,n,l,r);
            if(l==1 and r==n)
            {
                if(res < n1.ans)
                {
                    res = n1.ans;
                    op = "OPERATION1";
                }
                // res = n1.ans;
                // cout<<n1.ans<<endl;
            }
            else if(l==1)
            {
                lli ans=n1.ans;
                ans=max(ans,n1.prefix+max_start_here[r+1]);
                ans=max(ans,max_suf[r+1]);
                if(res < ans)
                {
                    res = ans;
                    op = "OPERATION1";
                }
                // res = ans;
                // cout<<ans<<endl;
            }
            else if(r==n)
            {
                lli ans=n1.ans;
                ans=max(ans,n1.suffix+max_end_here[l-1]);
                ans=max(ans,max_pre[l-1]);
                if(res < ans)
                {
                    res = ans;
                    op = "OPERATION1";
                }
                // res = ans;
                // cout<<ans<<endl;
            }
            else
            {
                lli ans=n1.ans;
                ans=max(ans,n1.prefix+max_start_here[r+1]);
                ans=max(ans,n1.suffix+max_end_here[l-1]);
                ans=max(ans,n1.sum+max(0LL,max_start_here[r+1])+max(0LL,max_end_here[l-1]));
                ans=max(ans,max_pre[l-1]);
                ans=max(ans,max_suf[r+1]);
                if(res < ans)
                {
                    res = ans;
                    op = "OPERATION1";
                }
                // res = ans;
                // cout<<ans<<endl;
            }
        }

        for(int itr = 2; itr <= n; ++itr)
        {
            lli l,r;
            l = itr, r = n;
            // cin>>l>>r;
            node n1=query(1,1,n,l,r);
            if(l==1 and r==n)
            {
                if(res < n1.ans)
                {
                    res = n1.ans;
                    op = "OPERATION2";
                }
                // res = max(res, n1.ans);
                // cout<<n1.ans<<endl;
            }
            else if(l==1)
            {
                lli ans=n1.ans;
                ans=max(ans,n1.prefix+max_start_here[r+1]);
                ans=max(ans,max_suf[r+1]);
                if(res < ans)
                {
                    res = ans;
                    op = "OPERATION2";
                }
                // res = max(res, ans);
                // cout<<ans<<endl;
            }
            else if(r==n)
            {
                lli ans=n1.ans;
                ans=max(ans,n1.suffix+max_end_here[l-1]);
                ans=max(ans,max_pre[l-1]);
                if(res < ans)
                {
                    res = ans;
                    op = "OPERATION2";
                }
                // res = max(res, ans);
                // cout<<ans<<endl;
            }
            else
            {
                lli ans=n1.ans;
                ans=max(ans,n1.prefix+max_start_here[r+1]);
                ans=max(ans,n1.suffix+max_end_here[l-1]);
                ans=max(ans,n1.sum+max(0LL,max_start_here[r+1])+max(0LL,max_end_here[l-1]));
                ans=max(ans,max_pre[l-1]);
                ans=max(ans,max_suf[r+1]);
                if(res < ans)
                {
                    res = ans;
                    op = "OPERATION2";
                }
                // res = max(res, ans);
                // cout<<ans<<endl;
            }
        }
        cout << res << " " << op << endl;
    }
}