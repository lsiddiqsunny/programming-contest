
#include<bits/stdc++.h>
using namespace std;
#define mx 5005
#define inf 1000000000
int dist[mx];
vector<pair<int,int> >g[mx];

bool check[mx][mx];
void bfs(int src)
{
    queue<int>q;
    q.push(src);
    dist[src]=0;

    while(!q.empty())
    {
        int   u = q.front();
        q.pop();
        int i;
        for( i=0; i< g[u].size() ; i++)
        {
            int  v = g[u][i].first;
            if(dist[v]>max(dist[u],g[u][i].second))
            {
                dist[v]=max(dist[u],g[u][i].second);
                q.push(v);
            }
        }
    }
}
int main()
{
    int test;
    cin>>test;
    for(int cs=1; cs<=test; cs++)
    {
        int n,m;
        cin>>n>>m;

        for(int i=0; i<mx; i++)
        {
            g[i].clear();

            dist[i]=inf;
            for(int j=0; j<mx; j++) check[i][j]=false;

        }
        int u,v,w;
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);

            if(check[u][v])
            {
                int j;
                for(j=0; g[u][j].first!=v; j++);



                    if(g[u][j].second>w)
                        g[u][j].second=w;
                       // cout<<g[u][j].second<<endl;;



            }
            else
            {
                g[u].push_back(make_pair(v, w));
                check[u][v]=true;
            }
            if(check[v][u])
            {
                int j;
                for(j=0; g[v][j].first!=u; j++);
                    if(g[v][j].second>w)
                        g[v][j].second=w;
            }
            else
            {
                g[v].push_back(make_pair(u, w));
                check[v][u]=true;
            }

        }
        int s;
        cin>>s;
        bfs(s);
        cout<<"Case "<<cs<<":"<<endl;
        for(int i=0; i<n; i++)
        {
            if(dist[i]==inf)
            {
                cout<<"Impossible"<<endl;
            }
            else
            {
                cout<<dist[i]<<endl;
            }
        }

    }

}
