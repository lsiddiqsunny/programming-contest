#include<bits/stdc++.h>
using namespace std;
#define mx 50000

int id[mx],n,m,edge,k;
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
    for(int i = 0; i < k; ++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x) != root(y))
        {
            edge++;
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


        scanf("%d",&m);

        edge=0;
        long long    int total=0;
        int t;
        k=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<m; j++)
            {
                scanf("%d",&t);
                total+=t;
                if(t>0)
                {
                    p[k]=make_pair(t,make_pair(i,j));
                    k++;
                }
            }
        }
        sort(p, p + k);


        long long cost=kruskal(p);
        if(edge!=(m-1))
        {
            cout<<"Case "<<cs<<": -1"<<endl;
        }
        else
        {
            cout<<"Case "<<cs<<": "<<total-cost<<endl;
        }

    }

}

