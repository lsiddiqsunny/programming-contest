# include <bits/stdc++.h>
using namespace std ;
# define pii pair<long long int,int>
# define pb push_back
# define INF 1e18
# define sz 300005
priority_queue<pii, vector <pii>,greater<pii> >q;
vector <pair<pair<long long int,int>,int> >G[sz];
long long int dist[sz];
bool vis[sz];
int parent[sz];
int n,m;

void dijktras ( int src)
{
    for ( int i= 1 ; i<=n; i++)
    {
        dist[i]=INF;
        vis[i]= false ;
        //parent[i]= -1 ;
    }
    dist[src]= 0 ;
    q.push(pii( 0,src));
    while (!q.empty())
    {
        int s=q.top().second;
        long long w1=q.top().first;
        q.pop();
        ///vis[s]=1;
        if(dist[s]!=w1) continue;
        for ( int i= 0 ; i<G[s].size(); i++)
        {
            int v=G[s][i].first.second;
            long long int w=G[s][i].first.first;
            if ( dist[s]+w<dist[v])
            {
                dist[v]=dist[s]+w;
                q.push(pii(dist[v],v));
               // vis[v]=1;
               // parent[v]=s;
            }
        }
      //  vis[s]= true ;
    }
}
int dfs(int s, int rem)
{
    if(rem==0)
        return 0;
    vis[s] = 1;
    for(int i = 0; i<G[s].size(); i++)
    {
        int u=G[s][i].first.second;
        long long w=G[s][i].first.first;
        int id=G[s][i].second;
        if(vis[u]==0 && dist[u]==dist[s] + w)
        {
            printf("%d ",id);
            rem = dfs(u,rem-1);
            if(rem==0)
                return 0;
        }
    }

    return rem;
}
int main()
{
    int k;
    scanf("%d%d%d",&n,&m,&k);
     int u,v;
    long long w;
    for(int i=0; i<m; i++)
    {

        scanf("%d%d%lld",&u,&v,&w);
        // mp[{min(u,v),max(u,v)}]=i+1;
        G[u].pb({{w,v},i+1});
        G[v].pb({{w,u},i+1});

    }
    dijktras(1);
    int ans=min(n-1,k);
    printf("%d\n",ans);
    memset(vis,0,sizeof(vis));
    dfs(1,ans);


}
