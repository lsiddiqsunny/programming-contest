#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define LOGMAXN 20
vector<int>g[MAXN];
int par[MAXN][LOGMAXN];
int depth[MAXN];
int chainNo=0,chainHead[MAXN],chainPos[MAXN];
int chainInd[MAXN],chainSize[MAXN];
int node_serial[MAXN],serial_node[MAXN];
int idx;
int max_subtree[MAXN];
int  dfs(int cur,int prev)
{
    depth[cur]=depth[prev]+1;
    par[cur][0]=prev;
    int total=1;
    int node=-1;
    int maxi=-1;

    for(int i=0; i<g[cur].size(); i++)
    {
        int v=g[cur][i];
        if(par[cur][i]!=prev)
        {
            int temp=dfs(par[cur][i],cur);
            total+=temp;
            if(temp>maxi)
            {
                maxi=temp;
                node=v;
            }
        }
    }
    max_subtree[cur]=node;///special child,having maximum subtree nodes
    return total;

}
void preprocess(int n)
{
    for (int i=1; i<LOGMAXN; i++)
    {
        for (int node = 1; node <= n; node++)
        {
            if (par[node][i-1] != -1)
            {
                par[node][i] =par[par[node][i-1]][i-1];
            }
        }
    }

}
int lca(int u, int v)
{
    if (depth[v] < depth[u])
        swap(u, v);

    int diff = depth[v] - depth[u];

    for (int i=0; i<LOGMAXN; i++)
        if ((diff>>i)&1)
            v = par[v][i];

    if (u == v)
        return u;

    for (int i=LOGMAXN-1; i>=0; i--)
        if (par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }

    return par[u][0];
}

void HLD(int u, int sz)
{
    if(chainHead[chainNo]==-1)
        chainHead[chainNo]=u;
    chainInd[u]=chainNo;
    chainSize[chainNo]=sz;

    node_serial[u]=idx;
    serial_node[idx]=u;
    idx++;
    if(max_subtree[u]==-1)
        return ;

    HLD(max_subtree[u],sz+1);

    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if(v!=par[u][0] && v!=max_subtree[u])
        {
            chainNo++;
            HLD(v,1);
        }
    }
}

void allclear(int n)
{
    chainNo=1;
    idx=1;
    for(int i=0; i<=n; i++)
    {
        g[i].clear();
    }

    memset(chainHead,-1,sizeof(chainHead));
    memset(par,-1,sizeof(par));


}
int main()
{

}
