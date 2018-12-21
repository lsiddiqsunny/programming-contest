#include<bits/stdc++.h>
using namespace std;

int tree[505][4*505];
void update(int node, int l, int r,int i,int x,int val)
{
    if(l>x or r<x)return;
    if(l==x and r==x)
    {
        tree[i][node]=val;
        return;
    }
    else
    {
        int mid = (l +r) / 2;

        update(2*node, l, mid,i,x,val);

        update(2*node+1, mid+1, r,i,x,val);

        tree[i][node] = max(tree[i][2*node], tree[i][2*node+1]);
    }
}
int query(int node, int start, int end, int l, int r,int i)
{
    if(r < start or end < l)
    {

        return INT_MIN;
    }
    if(l <= start and end <= r)
    {
        return tree[i][node];
    }
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r,i);
    int p2 = query(2*node+1, mid+1, end, l, r,i);
    return max(p1, p2);
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {
        memset(tree,-1,sizeof tree);
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=1; i<=n; i++)
        {
            for(int  j=1; j<=n; j++)
            {
                int x;
                scanf("%d",&x);
                update(1,1,n,i,j,x);
                //printf("%d ",x);
            }
            //cout<<endl;
        }
        printf("Case %d:\n",cs);
        while(q--)
        {
            int l,r,s,l1,r1;
            scanf("%d%d%d",&l,&r,&s);
            l1=l+s-1,r1=r+s-1;
            int ans=INT_MIN;
            for(int i=l; i<=l1; i++)
            {
                ans=max(ans,query(1,1,n,r,r1,i));
            }
            printf("%d\n",ans);

        }
    }

}
