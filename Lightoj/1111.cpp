#include<bits/stdc++.h>
using namespace std;
#define MAX 1005
int visited[MAX];
int city[MAX];
int co[MAX];
vector<int>g[MAX];
void dfs(int s,int c){
co[s]+=c;
for(int i=0;i<g[s].size();i++){
    if(!visited[g[s][i]]){
        visited[g[s][i]]=1;
        dfs(g[s][i],c);
    }
}

}
int main()
{
    int test;
    scanf("%d",&test);
    for(int i=1; i<=test; i++)
    {
        for(int j=0; j<MAX; j++)
        {
            city[j]=visited[j]=0;
            g[j].clear();
            co[j]=0;
        }
        int k,n,m;
        scanf("%d%d%d",&k,&n,&m);
        int x;
        for(int j=0; j<k; j++)
        {
            scanf("%d",&x);
            city[x]++;
        }
        int u,v;
        for(int j=0; j<m; j++)
        {
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
        }
        for(int j=1; j<=n; j++)
        {
            memset(visited,0,sizeof(visited));
            if(city[j])
            {
                visited[j]=1;
                dfs(j,city[j]);
            }
        }
        int ans=0;
        for(int j=1;j<=n;j++){
           if(co[j]>=k) ans++;
        }
        cout<<"Case "<<i<<": "<<ans<<endl;
    }

}
