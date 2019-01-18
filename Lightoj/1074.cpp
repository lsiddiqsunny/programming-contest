#include<bits/stdc++.h>
using namespace std;
int inf=INT_MAX;
vector< pair<int,int> >edge;
int w[205][205];
int b[205];
int cycle[205],dist[205];

int n,m;
int cube(int x)
{
    return x*x*x;
}
void dfs(int s)
{
    if(cycle[s]) return ;
    cycle[s]=1;
    for(int i=0; i<n; i++)
    {
        if(w[s][i]!=inf) dfs(i);
    }
}
void bellman(int s)
{
    dist[s]=0;
    for(int i=1; i<=n-1; i++)
    {
        for(int j=0; j<edge.size(); j++)
        {
            int x=edge[j].first;
            int y=edge[j].second;
            int z=w[x][y];
            //cout<<z<<endl;
            if(dist[x] < inf && (dist[x] + z) < dist[y])
            {
                dist[y] = dist[x] + z;
            }
        }
    }
    for(int j=0; j<m; j++)
    {
        int x=edge[j].first;
        int y=edge[j].second;
        int z=w[x][y];
        if(dist[x] < inf && (dist[x] + z) < dist[y] &&!cycle[x])
        {
            dfs(x);
        }
    }


}
int main()
{
    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {
        edge.clear();
        for(int i=0; i<205; i++)
        {
            for(int j=0; j<205; j++)
            {
                w[i][j]=inf;
                b[i]=0;
                cycle[i]=0;
                dist[i]=inf;
            }

        }


        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&b[i]);
        }
        scanf("%d",&m);
        for(int i=0; i<m; i++)
        {
            int x,y,z;
            scanf("%d%d",&x,&y);
            y--,x--;
            z=cube(b[y]-b[x]);
            edge.push_back( make_pair(x,y) );
            w[x][y]=z;


        }


        bellman(0);
        printf("Case %d:\n",cs);
        int q;
        scanf("%d",&q);

        while(q--)
        {
            int t;
            scanf("%d",&t);
            t--;
            if(dist[t]<3 || cycle[t] || dist[t]==inf)
            {
                printf("?\n");
            }
            else printf("%d\n",dist[t]);
        }



    }
}

