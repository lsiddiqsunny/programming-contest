#include<bits/stdc++.h>
using namespace std;

long long mod=1000000007;
long long  tree[400005],lazy[400005];
long long int  a[100005];
int  n;
int m;
long long sum,big,total,add;
int l1,r1;
        long long k;
void build(int node, int start, int end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node] = a[start];
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
        tree[node]%=mod;
    }
}
void updateRange(int node, int  start, int end, int  l, int r, long long val)
{
    if(lazy[node] != -1)
    {

        tree[node] =(tree[node]%mod+ ((end - start + 1)%mod * lazy[node]%mod)%mod)%mod;
        if(start != end)
        {
            if(lazy[node*2]!=-1)
            lazy[node*2] += lazy[node];
            else lazy[node*2] = lazy[node];
            lazy[node*2]%=mod;
            if(lazy[node*2+1]!=-1)
            lazy[node*2+1] += lazy[node];
            else lazy[node*2+1] = lazy[node];
            lazy[node*2+1]%=mod;
        }
        lazy[node] = -1;
    }
    if(start > end or start > r or end < l)
        return;
    if(start >= l and end <= r)
    {
        tree[node] =(tree[node]%mod+( (end - start + 1)%mod * val%mod)%mod)%mod;
        if(start != end)
        {
            if(lazy[node*2]!=-1)
            {
                lazy[node*2] += val;
            }
            else
                lazy[node*2] = val;

            if(lazy[node*2+1]!=-1)
            {
                lazy[node*2+1] += val;
            }
            else
                lazy[node*2+1] = val;
            lazy[node*2]%=mod;
            lazy[node*2+1]%=mod;
        }
        return;
    }
    int  mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);
    updateRange(node*2 + 1, mid + 1, end, l, r, val);
    tree[node] = tree[node*2]%mod + tree[node*2+1]%mod;
    tree[node]%=mod;
}

long long  queryRange(int node, int start,int end,int l, int r)
{
    if(start > end or start > r or end < l)
        return 0;
    if(lazy[node] != -1)
    {

        tree[node] =(tree[node]%mod+ ((end - start + 1)%mod * lazy[node]%mod)%mod)%mod;
        if(start != end)
        {
            if(lazy[node*2]!=-1)
            lazy[node*2] += lazy[node];
            else lazy[node*2] = lazy[node];
            lazy[node*2]%=mod;
            if(lazy[node*2+1]!=-1)
            lazy[node*2+1] += lazy[node];
            else lazy[node*2+1] = lazy[node];
            lazy[node*2+1]%=mod;
        }
        lazy[node] = -1;

    }
    if(l <= start and end <= r)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    long long p1 = queryRange(node*2, start, mid, l, r);
    long long p2 = queryRange(node*2 + 1, mid + 1, end, l, r);
    return (p1%mod + p2%mod)%mod;
}
long long bigmod ( long long a, long long p, long long m ) //Sunny
{
    long long res = 1;
    long long x = a;
    while ( p )
    {
        if ( p & 1 ) //p is odd
        {
            res = ( res * x ) % m;
        }
        x = ( x * x ) % m;
        p = p >> 1;
    }
    return res;
}

typedef pair<long long int,long long  int> pii;
#define x first
#define y second

pii extendedEuclid(long long int a,long long  int b)   // returns x, y | ax + by = gcd(a,b)
{
    if(b == 0)
        return pii(1, 0);
    else
    {
        pii d = extendedEuclid(b, a % b);
        return pii(d.y, d.x - d.y * (a / b));
    }
}

int modularInverse(long long int a,long long  int n)
{
    pii ret = extendedEuclid(a, n);
    return ((ret.x % n) + n) % n;
}

int main()
{

    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        scanf("%lld",&a[i]);
     //   updateRange(1,0,n-1,i,i,a[i]*1LL);
    }
    build(1,0,n-1);


    scanf("%d",&m);
    while(m--)
    {

        scanf("%d%d%lld",&l1,&r1,&k);
        l1--;
        r1--;
        sum=queryRange(1,0,n-1,l1,r1);

        total=(r1-l1)+2LL;
        big=bigmod(total,k,mod);
        if(big<0)
        {
            big+=mod;
            big%=mod;
        }

         add=sum%mod*(big-1)%mod;

        if(add<0)
        {
            add+=mod;
            add%=mod;
        }

        add=(add*bigmod(total-1,mod-2,mod))%mod;

        updateRange(1,0,n-1,l1,r1,add);

    }
    for(long long i=0; i<n; i++)
    {
        printf("%lld ",queryRange(1,0,n-1,i,i));
    }
    printf("\n");
}
