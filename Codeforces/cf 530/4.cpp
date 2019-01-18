#include<bits/stdc++.h>
using namespace std;
#define mx 100005
vector<int>g[mx];
int vis[mx];
long long val[mx];
bool ok;
long long ans=0;
void dfs(int s,long long value,long long x)
{
    // cout<<value<<endl;

    vis[s]=1;
    if(val[s]==-1)
    {
        val[s]=0;
    }
    else if(val[s]<value)
    {
        ok=false;
        return;
    }
    value=max(value,val[s]);
   // val[s]=value;

    for(auto y:g[s])
    {
        if(vis[y]==0)
        {
            dfs(y,value,x);
        }
    }
    if(g[s].size()==1){
        ans+=value;
    }


}

int main()
{
    ok=true;
    int n;
    scanf("%d",&n);
    for(int i=2; i<=n; i++)
    {
        int x;
        scanf("%d",&x);
        g[x].push_back(i);
        g[i].push_back(x);
    }
    for(int i=1; i<=n; i++)
    {
        long long int x;
        scanf("%I64d",&x);
        val[i]=x;
    }
    dfs(1,0,0);
    if(!ok)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    else
    {


    ans-=val[1];
        cout<<ans<<endl;

    }

}
