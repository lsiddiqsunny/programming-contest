#include<bits/stdc++.h>
using namespace std;
#define mx 200005
vector<int>g[mx];
long long cost[mx];
vector<pair<long long,pair<int,int> > > edge;
long long ans=0;




int id[mx];
void initialize()
{
    for(int i = 0; i < mx; ++i)
        id[i] = i;
}

int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

long long kruskal(int k)
{
    int x, y;
    long long cost, minimumCost = 0;
    sort(edge.begin(),edge.end());
    initialize();

    int co=0;;
    for(int i = 0; i < edge.size(); ++i)
    {
        x = edge[i].second.first;
        y = edge[i].second.second;
        cost = edge[i].first;
        if(root(x) != root(y))
        {
            co++;
            if(co==k)
            {
                break;
            }

            minimumCost += cost;
            union1(x, y);

        }
    }
    return minimumCost;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector<pair<long long,int> > v;
    for(int i=1; i<=n; i++)
    {
        scanf("%I64d",&cost[i]);
        v.push_back(make_pair(cost[i],i));
    }
    sort(v.begin(),v.end());
    int x=v[0].second;
    for(int i=0; i<m; i++)
    {
        int u,v;
        long long w;
        scanf("%d%d%I64d",&u,&v,&w);
        edge.push_back(make_pair(w,make_pair(u,v)));

    }



    for(int i=1; i<=n; i++)
    {
        if(x==i)
            continue;
        edge.push_back(make_pair(cost[i]+cost[x],make_pair(i,x)));
    }

    ans=kruskal(n);

    cout<<ans<<endl;


}
