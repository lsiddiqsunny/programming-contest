#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int>mp;
int main()
{
    int n;
    cin>>n;
    pair<int,int>a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i].first>>a[i].second;

    }
    pair<int,int>b[n];
    for(int i=0; i<n; i++)
    {
        cin>>b[i].first>>b[i].second;
        mp[b[i]]=i;
    }
    int mark[n];
    memset(mark,0,sizeof(mark));
    int x=b[0].first,y=b[0].second;
    for(int i=0; i<n; i++)
    {
        memset(mark,0,sizeof(mark));
        mark[i]=1;
        int nx=a[i].first+x,ny=a[i].second+y;
        int co=1;
        for(int j=0; j<n; j++)
        {
            if(mark[j]==1)
            {
                continue;
            }
            int px=nx-a[j].first;
            int py=ny-a[j].second;
            if(mp.find(make_pair(px,py))!=mp.end())
            {
                co++;
                mark[j]=1;

            }

        }
        if(co==n)
        {
            cout<<nx<<" "<<ny<<endl;
            return 0;
        }

    }



}
