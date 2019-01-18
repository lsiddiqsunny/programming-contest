
#include<bits/stdc++.h>
using namespace std;
#define mx 50005
typedef pair<long long int,int> PII;
vector<PII>g[mx],rg[mx];
bool marked[mx];
long long prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();
        Q.pop();
        x = p.second;
        // Checking for cycle
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0; i < g[x].size(); ++i)
        {
            y = g[x][i].second;
            if(marked[y] == false)
                Q.push(g[x][i]);
        }
    }
    return minimumCost;
}
long long rprim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();
        Q.pop();
        x = p.second;
        // Checking for cycle
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0; i < rg[x].size(); ++i)
        {
            y = rg[x][i].second;
            if(marked[y] == false)
                Q.push(rg[x][i]);
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
        for(int i=0; i<mx; i++)
        {
            g[i].clear();
            rg[i].clear();
            marked[i]=0;
        }
        int n;
        scanf("%d",&n);

        int x,y;
        long long w;
        while(1)
        {
            scanf("%d%d%lld",&x,&y,&w);
            if(x==0&&y==0&&w==0) break;
            g[x].push_back(make_pair(w,y));
            g[y].push_back(make_pair(w,x));
            rg[x].push_back(make_pair(-w,y));
            rg[y].push_back(make_pair(-w,x));
        }
        long long  int lowcost=prim(1);
        memset(marked,0,sizeof marked);
        long long   int maxcost=-(rprim(1));
        long long total=lowcost+maxcost;
        if(total%2==0)
        {
            total/=2;
            printf("Case %d: %lld\n",cs,total);
        }
        else
        {
            printf("Case %d: %lld/2\n",cs,total);
        }

    }
}
