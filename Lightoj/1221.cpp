#include<bits/stdc++.h>
#define mx 1005
using namespace std;
int inf=1e9;

vector< pair< pair<int,int>,int> >edge;
int w[mx][mx];
int b[mx];
int dist[mx],parent[mx];

int n,m,r,p;

bool bellman(int s)
{
    dist[s]=0;
    for(int i=1; i<=n-1; i++)
    {
        for(int j=0; j<edge.size(); j++)
        {
            int x=edge[j].first.first;
            int y=edge[j].first.second;
            int z=edge[j].second;
            // cout<<x<<" "<<y<<endl;
            if( (dist[x]+z) < dist[y])
            {
                dist[y] = dist[x] + z;
                parent[y]=x;
            }
        }
    }
    for(int j=0; j<m; j++)
    {
        int x=edge[j].first.first;
        int y=edge[j].first.second;
        int z=edge[j].second;
        if((dist[x] + z) < dist[y] )
        {
            return false;

        }
    }

    return true;
}
int main()
{

    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {

        edge.clear();
        for(int i=0; i<mx; i++)
        {
            dist[i]=inf;
            parent[i]=0-1;
        }


        scanf("%d",&n);

        scanf("%d",&m);
        scanf("%d",&p);
        for(int i=0; i<m; i++)
        {
            int x,y,I,e;
            scanf("%d%d%d%d",&x,&y,&I,&e);


            edge.push_back( make_pair(make_pair(x,y),p*e-I) );

        }


        if(!bellman(0))
        {
            printf("Case %d: YES\n",cs);
        }
        else
        {

            printf("Case %d: NO\n",cs);


        }

    }

}
