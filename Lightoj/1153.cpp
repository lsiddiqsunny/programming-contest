#include<bits/stdc++.h>
using namespace std;
#define mx 105
int g[mx][mx],rgraph[mx][mx];
int n,source,sink,m;
int vis[mx],par[mx];
bool bfs()
{
    memset(vis,0,sizeof vis);
    //memset(par,0,sizeof par);
    queue< int> Q;
    vis[source]=1;
    Q.push(source);
    par[source]=source;
    bool isPath= false;


    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        if(u==sink)
        {
            isPath=true;
            break;
        }
        for(int i=1; i<=n; i++)
        {
            if(vis[i]==0 && rgraph[u][i]>0)
            {
                par[i]=u;
                vis[i]=1;
                                Q.push(i);


            }
        }


    }

    return isPath;
}
int Ford_Fulkerson()
{

    int max_flow=0;
    while(bfs())
    {
        int v=sink;
        int path_flow = INT_MAX;
        for (; v != source; v = par[v])
        {
            int  u = par[v];
            path_flow = min(path_flow, rgraph[u][v]);
        }
        v = sink;
        for (; v != source; v = par[v])
        {
            int u = par[v];
            rgraph[u][v] -= path_flow;
            rgraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;

}
int main()
{
    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {
        memset(par,0,sizeof par);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++) rgraph[i][j]=0;
        }
        scanf("%d%d%d%d",&n,&source,&sink,&m);
        for(int i=0; i<m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            rgraph[u][v]+=w;
            rgraph[v][u]+=w;
        }
        printf("Case %d: %d\n",cs,Ford_Fulkerson());


    }
}

