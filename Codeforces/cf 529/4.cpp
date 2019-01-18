#include<bits/stdc++.h>
using namespace std;
#define mx 200005
int vis[200005];
pair<int,int>a[200005];
vector<int>topo;
void dfs(int s)
{
    vis[s]=1;
    int x=a[s].first;
    int y=a[s].second;
    if(vis[x]==0)
    {
        dfs(x);
    }
    if(vis[y]==0)
    {
        dfs(y);
    }
    topo.push_back(s);

}
int main()
{

    int n;
    cin>>n;


    for(int i=1; i<=n; i++)
    {
        int x,y;
        cin>>x>>y;
        a[i]=make_pair(x,y);

    }
    dfs(1);
    //  cout<<topo[0]<<endl;
    vector<int>ans;
    for(int i=topo[0]; ;)
    {
        ans.push_back(i);
        if(ans.size()==n)
            break;

        int x=a[i].first,y=a[i].second;
        if(a[x].first==y|| a[x].second==y)
        {
            i=x;
        }
        else
        {
            i=y;
        }



    }
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }


}
