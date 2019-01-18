#include<bits/stdc++.h>
using namespace std;
#define MAX 50005
vector<int>g[MAX];
bool visited[MAX];
int parent[MAX];
void bfs(int s,int e)
{for(int i=1;i<50000;i++)
    {
        parent[i] = i;
        visited[i] = false;
        sort(g[i].begin(),g[i].end());
    }

    queue<int>q;
    q.push(s);
    visited[s]=1;
    while(!q.empty())
    {
        int u = q.front();

        if(u == e) return;
        q.pop();

        for(int i=0; i<g[u].size(); i++)
        {
            int v = g[u][i];

            if(!visited[v])
            {
                parent[v] = u;
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}
void printpath(int u)
{
    if(parent[u] == u)
    {
        printf("%d",u);
        return;
    }
    printpath(parent[u]);
    printf(" %d",u);
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int i=1; i<=test; i++)
    {
        int n;
        scanf("%d",&n);
        for(int j=0; j<MAX; j++)
        {
            g[j].clear();

        }
        int a[n];
        for(int j=0; j<n; j++)
            scanf("%d",&a[j]);

        for(int j=1; j<n; j++)
        {
            g[ a[j-1] ].push_back(a[j]);
            g[ a[j] ].push_back(a[j-1]);
        }


        bfs(a[0],a[n-1]);
        printf("Case %d:\n",i);
        printpath(a[n-1]);
         puts("");
    }
}
