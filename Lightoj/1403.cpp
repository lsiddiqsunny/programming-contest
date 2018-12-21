
#include<bits/stdc++.h>
using namespace std;
#define mx 1005
int inf =100000;
vector<int>rgraph[mx];
int nodes,source,sink;
int vis[mx],par[mx];
string s[205];
int dx[]= {1,-1,0,0};
int dy[]= {0,0,1,-1};
int m,n;

bool bmp(int u)
{
    int i;
    for(i=0; i<rgraph[u].size(); i++)
    {
        int v=rgraph[u][i];

        if(vis[v]) continue;
        vis[v]=1;
        if(par[v]==-1 || bmp(par[v]))
        {
            par[v]=u;
            return 1;
        }
    }
    return 0;
}
int solve()
{
    int ans=0,i;
    memset(par,-1,sizeof(par));
    for(i=1; i<=nodes; i++)
    {
        memset(vis,0,sizeof(vis));
        if(bmp(i)) ans+=1;
    }
    return (ans);
}

int main()
{
    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {

        memset(par,-1,sizeof par);
        for(int i=0; i<1005; i++)
        {
 rgraph[i].clear();
        }

        scanf("%d%d",&n,&m);

        for(int i=0; i<m ; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            rgraph[u].push_back(v);
        }
        nodes=n;




        int ans=solve();
        cout<<"Case "<<cs<<": "<<nodes-ans<<endl;

    }
}

