#include<bits/stdc++.h>
using namespace std;
#define mx 1005
int money[mx];
vector<int> g[mx];
int vis[mx];
int total,co;

void dfs(int s)
{
    co++;
    total+=money[s];
    vis[s]=1;
    for(int i=0; i<g[s].size(); i++)
    {
        int v=g[s][i];
        if(vis[v]==0)
        {
            dfs(v);
        }
    }

}
int main()
{
    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {
        for(int i=1; i<mx; i++)
        {
            g[i].clear();
            vis[i]=0;
            money[i]=0;
        }
        int n,m;
        int now=0;
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&money[i]);
            now+=money[i];
        }
        for(int i=0; i<m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int flag=true;
        // set<int>s;
        now=now/n;
        for(int i=1; i<=n; i++)
        {
            if(vis[i]==0)
            {
                total=0;
                co=0;
                dfs(i);
                //now=total;
                if(total%co!=0)
                    flag=false;
                else
                {
                    if(total/co!=now)
                    {
                        flag=false;
                    }
                }


            }
            if(!flag)
                break;
        }

        printf("Case %d: ",cs);
        if(flag)
        {
            printf("Yes\n");
        }
        else
            printf("No\n");
    }
}
