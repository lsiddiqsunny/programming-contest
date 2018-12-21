#include<bits/stdc++.h>
using namespace std;
long long tree[4*100005],lazy[400005];

void updateRange(int node, int start, int end, int l, int r,long long int val)
{
    if(lazy[node] != -1)
    {

        tree[node] = (end - start + 1) * lazy[node];
        if(start != end)
        {
            lazy[node*2] = lazy[node];
            lazy[node*2+1] = lazy[node];
        }
        lazy[node] = -1;
    }
    if(start > end or start > r or end < l)
        return;
    if(start >= l and end <= r)
    {
        tree[node] = (end - start + 1) * val;
        if(start != end)
        {
            lazy[node*2] = val;
            lazy[node*2+1] = val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);
    updateRange(node*2 + 1, mid + 1, end, l, r, val);
    tree[node] = tree[node*2] + tree[node*2+1];
}

long long  queryRange(int node, int start, int end, int l, int r)
{
    if(start > end or start > r or end < l)
        return 0;
    if(lazy[node] != -1)
    {

        tree[node] = (end - start + 1) * lazy[node];
        if(start != end)
        {
            lazy[node*2] = lazy[node];
            lazy[node*2+1] = lazy[node];
        }
        lazy[node] = -1;
    }
    if(start >= l and end <= r)
        return tree[node];
    int mid = (start + end) / 2;
    long long  int p1 = queryRange(node*2, start, mid, l, r);
    long long  int p2 = queryRange(node*2 + 1, mid + 1, end, l, r);
    return (p1 + p2);
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        memset(tree,0,sizeof tree);

        memset(lazy,-1,sizeof lazy);

        printf("Case %d:\n",cs);
        while(q--)
        {
            int type;
            scanf("%d",&type);
            if(type==1)
            {
                int i,j;
                long long val;
                scanf("%d%d%lld",&i,&j,&val);
                updateRange(1,0,n-1,i,j,val);
            }
            else
            {
                int i,j;
                long long val;
                scanf("%d%d",&i,&j);
                val=queryRange(1,0,n-1,i,j);
                long long element=(long long)(j-i+1),gcd;
                gcd=__gcd(val,element);
                val/=gcd,element/=gcd;
                if(element==1)
                {

                    printf("%lld\n",val);
                }
                else printf("%lld/%lld\n",val,element);
            }


        }

    }

}
