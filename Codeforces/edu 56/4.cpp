#include<bits/stdc++.h>
using namespace std;
#define mx 300005
vector<int>g[mx];
long long mod=998244353;
long long w,b;
int vis[mx];
long long P[300010];

long long bigmod ( long long a, long long p )
{
    long long res = 1;
    long long x = a;
    while ( p )
    {
        if ( p & 1 ) //p is odd
        {
            res = ( res * x ) % mod;
        }
        x = ( x * x ) % mod;
        p = p >> 1;
    }
    return res;
}
bool ok=true;
void  dfs(int s)
{

    if(vis[s]==1)
    {
        w++;
    }
    else
        b++;
    for(int i=0; i<g[s].size(); i++)
    {

        int u=g[s][i];
        if(vis[u]==vis[s])
        {
            ok=false;
            return;
        }
        if(vis[u]==-1)
        {
            vis[u]=1^vis[s];
            dfs(u);
        }
    }

}

int main()
{
    P[0] = 1;
    for(int i = 1; i <= 300000; i++) {
        P[i] = P[i-1] << 1;
        P[i] %= mod;
    }

    int t;
    scanf("%d",&t);
    while(t--)
    {

        ok=true;

        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            g[i].clear();
            vis[i]=-1;
        }
        int u,v;
        w=0;
        b=0;

        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        long long ans=1LL;
        for(int i=1; i<=n; i++)
        {
            w=0,b=0;
            if(vis[i]==-1)
            {
                vis[i]=1;
                dfs(i);

                if(ok)
                {

                    ans=ans*(P[w]+P[b]);

                    ans%=mod;
                }
                else
                    ans=0;

            }
        }

        printf("%lld\n",ans);



    }

}
