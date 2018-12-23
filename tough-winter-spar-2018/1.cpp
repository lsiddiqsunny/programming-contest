#include<bits/stdc++.h>

using namespace std;



int A[100005];
long long tree[100005*4];
long long lazy[100005*4];
 int mod=1000000000+7;

long long modpow(long long base, long long power,int mod)
{
    long long result=1;
    while(power>0)
    {
        if(power%2==1)
            result=(result*base)%mod;
        power/=2;
        base=(base*base)%mod;
    }
    return result;
}

int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}
int modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);

        int res = (x%m + m) % m;
        return res;

}
void build(int node, int start, int end)
{
    if(start==end)
    {
        tree[node]=A[start];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(start+end)/2;
    build(left,start,mid);
    build(right,mid+1,end);
    tree[node]=tree[left]+tree[right];
}

void updateRange (int node, int start, int end, int i, int j, long long x)
{
    if(i>end || j<start)
        return;
    if(start>=i && end<=j)
    {
        tree[node]=(tree[node]+((end-start+1)*x)%mod)%mod;
        lazy[node]=(lazy[node]+x)%mod;
        return;
    }
    int left=node<<1;
    int right=left+1;
    int mid=(start+end)>>1;
    updateRange(left,start,mid,i,j,x);
    updateRange(right,mid+1,end,i,j,x);
    tree[node]=((tree[left]+tree[right])%mod+ ((end-start+1)*lazy[node])%mod)%mod;

}
long long queryRange(int node, int start, int end, int i, int j, long long carry)
{
    if(i>end || j<start)
        return 0;
    if(start>=i && end<=j)
        return (tree[node]+ (carry*(end-start+1))%mod)%mod;
    int left=node<<1;
    int right=left+1;
    int mid=(start+end)>>1;
    long long p1=queryRange(left,start,mid,i,j,(carry+lazy[node])%mod);
    long long p2=queryRange(right,mid+1,end,i,j,(carry+lazy[node])%mod);
    return (p1+p2)%mod;
}
int main()
{
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>A[i];

    build(1,0,n-1);

    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int l,r;
        long long  k;
        cin>>l>>r>>k;

        long long s=queryRange(1,0,n-1,l-1,r-1,0);
        int N=r-l+2;
        long long p=modpow(N,k,mod)-1;
        int q=modInverse(N-1,mod);

        long long x= (p*q)%mod;
        x=(s*x)%mod;
        updateRange(1,0,n-1,l-1,r-1,x);
    }

    for(int i=0;i<n;i++){
        cout<<queryRange(1,0,n-1,i,i,0)<<" ";

    }
    cout<<endl;
}
