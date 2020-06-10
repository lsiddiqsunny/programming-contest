#include<bits/stdc++.h>
using namespace std;


#define mx 500005

int id[mx],n,m;

vector<pair<int,int> > edge;
vector<pair <int, pair<int, int> > >p;
int g[mx];
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

int kruskal(int k)
{
    int x, y;
    int cost, minimumCost = 0;

    initialize();
    for(int i = 0; i < k; ++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x) != root(y))
        {

            minimumCost += cost;
            union1(x, y);
            edge.push_back(make_pair(x,y));

        }
    }
    return minimumCost;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++)
    {

        int x,y;
        scanf("%d%d",&x,&y);
        p.push_back(make_pair(0,make_pair(x,y)));
        g[x]++;
        g[y]++;

    }



    for(int i=0; i<m; i++)
    {


        p[i].first=(g[p[i].second.first]+g[p[i].second.second]);
        p[i].first*=-1;

    }
    sort(p.begin(),p.end());

    kruskal(n);
    //  cout<<edge.size()<<endl;
    for(int i=0; i<n-1; i++)
    {

        cout<<edge[i].first<<" "<<edge[i].second<<endl;
    }



}
