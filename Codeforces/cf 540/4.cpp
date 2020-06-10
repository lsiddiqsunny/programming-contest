#include<bits/stdc++.h>
using namespace std;

#define mx 300005
vector<int>g[mx];
int vis[mx];
pair<int,int> color[mx];
int b,r;
int ans;


pair<int,int> count1[mx];

void numberOfNodes(int s, int e)
{

    count1[s].first = color[s].first;
    count1[s].second= color[s].second;
    for (auto u: g[s])
    {


        if (u == e)
            continue;

        numberOfNodes(u, s);

        count1[s].first += count1[u].first;
        count1[s].second += count1[u].second;
    }
}


int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            color[i].first=1;
            color[i].second=0;
            b++;
        }
        if(x==2)
        {
            color[i].first=0;
            color[i].second=1;
            r++;
        }
    }
    for(int i=1; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);

    }

    numberOfNodes(1,0);
    for(int i=1; i<=n; i++)
    {
        if(count1[i].first==0 and count1[i].second==r)
            ans++;
        if(count1[i].first==b and count1[i].second==0)
            ans++;
    }
    cout<<ans<<endl;

}
