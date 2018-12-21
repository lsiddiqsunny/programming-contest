/*http://lbv-pc.blogspot.com/2012/06/not-best.html*/
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pb push_back
#define INF 0x7fffffff
#define sz 5005

vector<pii>G[sz];
long long int  d[2][sz];
bool vis[sz];

int n,m;
struct node
{
    int op, v, w;
    node() {}
    node(int a, int b, int c) : op(a), v(b), w(c) {}
    bool operator < (const node &o) const
    {
        if (op == o.op)
            if(w == o.w ) return v > o.v;
        return w > o.w;
        return op > o.op;
    }
};

int dijktras(int src,int n)
{
  priority_queue<node> q;

    d[0][src]=0;

    q.push(node(0,src,0));

    while(!q.empty())
    {

        int s = q.top().v;
        int dist = q.top().w;
        int op   = q.top().op;
        q.pop();


        if(dist > d[op][s]) continue;


        for(int i = 0; i < G[s].size(); ++i)
        {
            int to = G[s][i].second;
            int w_extra = G[s][i].first;


            if(dist + w_extra < d[0][to])
            {
                d[1][to] = d[0][to];
                d[0][to] = dist + w_extra;
                q.push(node(1, to, d[1][to]));
                q.push(node(0, to, d[0][to]));

            }
            else if(dist + w_extra > d[0][to] && dist + w_extra < d[1][to])
            {
                d[1][to] = dist + w_extra;
                q.push(node(1, to, d[1][to]));
            }
        }
    }


    return INF;
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {
        scanf("%d%d",&n,&m);
        for(int i=0; i<=n; i++)
        {
            d[0][i]=d[1][i]=INF;
            vis[i]=false;

            G[i].clear();
        }
        while(m--)
        {
            int a,b,w;
            scanf("%d%d%d",&a,&b,&w);
            a--,b--;
            G[a].pb(pii(w,b));
            G[b].pb(pii(w,a));
        }
        dijktras(0,n);
        cout<<"Case "<<cs<<": "<<d[1][n-1]<<endl;
    }




}
