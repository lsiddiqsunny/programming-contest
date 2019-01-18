#include<bits/stdc++.h>
using namespace std;
#define mx 350
int g[mx][mx],rgraph[mx][mx];
int source,sink,node,n,m;
int vis[mx],par[mx];
void addEdge(int st, int en)
{
    for(int i=0; i<n; i = i + 6)
    {
        rgraph[st][i+en+m] = 1;
    }
}
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
    map<string,int> h;
    h["XXL"] = 0;
    h["XL"] = 1;
    h["L"] = 2;
    h["M"] = 3;
    h["S"] = 4;
    h["XS"] = 5;
    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {
        memset(par,0,sizeof par);
        for(int i=0; i<mx; i++)
        {
            for(int j=0; j<mx; j++) rgraph[i][j]=0;
        }

        scanf("%d",&n);
        n=n*6;

        scanf("%d",&m);
        for(int i=0; i<m; i++)
        {
            string s;
            cin>>s;
            int x=h[s];
            addEdge(i,x);
            cin>>s;
            x=h[s];
            addEdge(i,x);
        }
        source=n+m,sink=n+m+1,node=n+m+2;
        for(int i=0; i<m; i++)rgraph[source][i]=1;
        for(int i=m; i<m+n; i++)rgraph[i][sink]=1;
         cout<<m<<endl;
        if(int(Ford_Fulkerson())==m)
            printf("Case %d: YES\n",cs);
        else  printf("Case %d: NO\n",cs);


    }
}



