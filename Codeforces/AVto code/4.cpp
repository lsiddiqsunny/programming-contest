#include<bits/stdc++.h>
using namespace std;
#define mx 500005

int id[mx],n,m;
int k;
pair <long long, pair<int, int> > p[mx];
int co[mx];
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

void Union(int x, int y,long long w)
{
    int p = root(x);
    int q = root(y);
    id[p] = q;
    co[q]+=co[p];
    if(co[q]==k)
    {
        for(int i=0; i<k; i++)
        {
            cout<<w<<" ";
        }
        cout<<endl;;
        exit(0);
    }
}

void kruskal()
{
    int x, y;
    long long cost;
    initialize();
    for(int i = 0; i < m; ++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x) != root(y))
        {

            // minimumCost += cost;
            Union(x, y,cost);

        }
    }

}
int main()
{
    cin>>n>>m>>k;
    for(int i=0; i<k; i++)
    {
        int x;
        cin>>x;
        co[x]++;
    }
    for(int i=0; i<m; i++)
    {
        int u,v;
        long long w;
        cin>>u>>v>>w;
        p[i].first=w;
        p[i].second.first=u;
        p[i].second.second=v;
    }
    sort(p,p+m);
    kruskal();
}
