#include<bits/stdc++.h>
using namespace std;
#define mx 100005

int id[mx],n,m,edge,k;
long long int a;
pair <long long, pair<int, int> > p[mx];
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

long long kruskal(pair<long long, pair<int, int> > p[])
{
    int x, y;
    long long cost, minimumCost = 0;
    initialize();
    for(int i = 0; i < m; ++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if (cost >= a)
      break;
                if(root(x) != root(y))
        {

            minimumCost += cost;
            union1(x, y);

        }
    }
    return minimumCost;
}


int main()
{
    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {


        scanf("%d%d%d",&n,&m,&a);

        edge=0;
        long long    int total=0;
        int t;
        k=0;
        for(int i=0; i<m; i++)
        {
            int x,y;
            long long cost;
            scanf("%d%d%lld",&x,&y,&cost);
            x--;
            y--;
            p[i]=make_pair(cost,make_pair(x,y));
        }
        sort(p, p + m);


        long long cost=kruskal(p);
       // cout<<cost<<endl;
        long long d=0;
        for(int i=0; i<n; i++)
        {
            if(root(i)==i) d++;
        }

        cout<<"Case "<<cs<<": "<<(cost+d*a)<<" "<<d<<endl;


    }

}


