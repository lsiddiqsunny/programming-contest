#include<bits/stdc++.h>
using namespace std;
#define mx 250
int g[mx][mx],rgraph[mx][mx];
int source,sink,node;
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
        for(int i=0; i<node; i++)
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
        for(int i=0; i<mx; i++)
        {
            for(int j=0; j<mx; j++) rgraph[i][j]=0;
        }
        int n;
        scanf("%d",&n);
        int a[n];
        for(int i=0; i<n; i++) scanf("%d",&a[i]);
        int m;
        scanf("%d",&m);
        int b[m];
        for(int i=0; i<m; i++) scanf("%d",&b[i]);
        source=n+m,sink=n+m+1,node=n+m+2;
        for(int i=0; i<n; i++)rgraph[source][i]=1;
        for(int i=n; i<m+n; i++)rgraph[i][sink]=1;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if(b[j]%a[i]==0) rgraph[i][n+j]=1;
            }
        printf("Case %d: %d\n",cs,Ford_Fulkerson());


    }
}


