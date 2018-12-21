#include<bits/stdc++.h>
using namespace std;
int inf=1000000;
vector< pair<int,int> >edge;
int w[1005][1005];
vector<int>rg[1005];

int cycle[1005],dist[1005];

int n,m;

void dfs(int s)
{

    cycle[s]=1;
    for(int i=0; i<rg[s].size(); i++)
    {
        int v=rg[s][i];
        if(cycle[v]==0) dfs(v);
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
            if((dist[x] + z) < dist[y])
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
        if( (dist[x] + z) < dist[y]  )
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
        for(int i=0; i<1005; i++)
        {
            rg[i].clear();
            for(int j=0; j<1005; j++)
            {
                w[i][j]=inf;

                cycle[i]=0;
                dist[i]=inf;
            }

        }


        scanf("%d",&n);

        scanf("%d",&m);
        for(int i=0; i<m; i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);

            edge.push_back( make_pair(y,x) );
            w[y][x]=z;
            rg[y].push_back(x);


        }


        bellman(0);
        printf("Case %d:",cs);
        vector<int>in_cycle;
        for(int i=0; i<n; i++)
        {
            if(cycle[i]) in_cycle.push_back(i);
        }
        if(in_cycle.empty())
        {
            printf(" impossible\n");

        }
        else
        {
            for(int i=0; i<in_cycle.size(); i++)
            {
                printf(" %d",in_cycle[i]);
            }
            cout<<endl;
        }


    }
}


