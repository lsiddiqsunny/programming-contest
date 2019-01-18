#include<bits/stdc++.h>
using namespace std;
#define MAX 10005
int color[MAX];
map<string,int>mp;
vector<int>g[MAX];
bool dfs(int s)
{

    color[s]=1;
    for(int i=0; i<g[s].size(); i++)
    {
        if(color[g[s][i]]==0)
        {
            dfs(g[s][i]);
        }
        else  if(color[g[s][i]]==1)
        {
            return true;
        }
    }
    color[s]=2;
    return false;
}

int main()
{
    int test;
    scanf("%d",&test);
    for(int i=1; i<=test; i++)
    {
        mp.clear();
        for(int i=0; i<MAX; i++)
        {
            g[i].clear();
            color[i]=0;
        }
        int m;
        scanf("%d",&m);
        string s,e;
        int n=0;
        while(m--)
        {
            cin>>s>>e;

            if(!mp[s]) mp[s] = ++n;
            if(!mp[e]) mp[e] = ++n;
            g[mp[s]].push_back(mp[e]);
        }
        printf("Case %d: ",i);
        bool flag=false;
        for(int j=1; j<=n; j++)
        {
            if(dfs(j))
            {
                printf("No\n");
                flag=true;
                break;
            }
        }
        if(!flag)
        {
            printf("Yes\n");
        }
    }
}
