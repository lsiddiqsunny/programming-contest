
#include<bits/stdc++.h>
using namespace std;
#define mx 50005
#define inf 1000000000
int dist[mx];
vector<int>g[mx];
vector<int>cost[mx];
int visited[mx];
void bfs(int s)
{
    visited[s]=1;
    dist[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<g[u].size(); i++)
        {
            int v=g[u][i];
            int   vcost = cost[ u ][i] +dist[u];


            if( dist[v] > vcost )
            {
                dist[v] = vcost;
                //cout<<vcost<<endl;
                q.push( v );
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
        int x,y,w;
        for(int i=0; i<mx; i++)
        {
            g[i].clear();
            visited[i]=0;
            cost[i].clear();
            dist[i]=inf;
        }
        for(int i=0; i<m; i++)
        {
            cin>>x>>y>>w;
            g[x].push_back(y);
            g[y].push_back(x);
            cost[x].push_back(w);
            cost[y].push_back(w);

        }
        bfs(1);
        if(dist[n]==inf)
        {
            cout<<"Case "<<cs<<": Impossible"<<endl;
        }
        else
        {
            cout<<"Case "<<cs<<": "<<dist[n]<<endl;

        }
    }

}
