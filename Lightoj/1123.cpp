#include<bits/stdc++.h>
using namespace std;
#define mx 205

int id[mx],n,m,edge,k;
long long int a;
vector<pair <long long, pair<int, int> > >p,nw;
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

long long kruskal()
{
    sort(p.begin(),p.end());
    int x, y;
    nw.clear();
    long long cost, minimumCost = 0;
    initialize();
    int co=0;
    for(int i = 0; i < p.size(); ++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;

        if(root(x) != root(y))
        {
            nw.push_back(p[i]);

            minimumCost += cost;
co++;
            if(co==n-1) break;
            union1(x, y);

        }
    }
    if(co==n-1)
    {
        p=nw;
        return minimumCost;
    }
    else return -1;
}


int main()
{
    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {


        scanf("%d%d",&n,&m);
        p.clear();
        nw.clear();
        edge=0;


        printf("Case %d:\n",cs);
        for(int i=0; i<m; i++)
        {
            int x,y;
            long long cost;
            scanf("%d%d%lld",&x,&y,&cost);
            x--;
            y--;
            p.push_back(make_pair(cost,make_pair(x,y)));
            if(i<n-1)
            {
                printf("-1\n");
            }
            else
            {

                printf("%lld\n",kruskal());
            }
        }



    }

}



