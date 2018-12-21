#include<bits/stdc++.h>
using namespace std;
#define mx 205
int inf =100000;
int g[mx][mx],rgraph[mx][mx];
int nodes,source,sink;
int vis[mx],par[mx];
struct candicate
{
    int height,age,div;
};

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
        for(int i=0; i<nodes; i++)
        {
            if(vis[i]==0 && rgraph[u][i]>0)
            {//cout<<i<<endl;
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
        for(int i=0; i<205; i++)
        {
            for(int j=0; j<205; j++) rgraph[i][j]=0;
        }
        int m,n;
        scanf("%d%d",&m,&n);
        candicate cands[(m+n)];
        for(int i=0; i<(m+n); i++)
        {
            int x,y,z;
            scanf("%d%d%d",&cands[i].height,&cands[i].age,&cands[i].div);
        }
        for(int i=0; i<m; i++)
        {
            for(int j=m; j<(m+n); j++)
            {
                if(abs(cands[i].height-cands[j].height)>12) continue;
                if(abs(cands[i].age-cands[j].age)>5) continue;
                if(cands[i].div!=cands[j].div) continue;
                rgraph[i][j]=1;
               // cout<<"here"<<endl;
               // rgraph[j][i]=1;
            }
        }
        source=n+m,sink=n+m+1;
        nodes=n+m+2;
        for(int i=0; i<m; i++)
        {
            rgraph[source][i]=1;


        }
        for(int i=m;i<(m+n);i++)
         rgraph[i][sink]=1;

        int ans=Ford_Fulkerson();
        cout<<"Case "<<cs<<": "<<ans<<endl;

    }
}

