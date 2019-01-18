#include<bits/stdc++.h>
using namespace std;
vector<int>g[5005];
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    int mark[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        mark[i]=0;
        g[a[i]].push_back(i);
    }
    int maink=k;
    bool ok=false;
    for(int i=1; i<=5000; i++)
    {
        if(g[i].size()==0)
            continue;
        if(g[i].size()>maink)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        int m=k;
        if(m<=0)
        {
            ok=true;
            m=maink;
        }
        for(int j=0; j<g[i].size(); j++)
        {
            mark[g[i][j]]=m;

            m--;
            if(m<=0)
            {
                ok=true;
                m=maink;
            }
        }
        k=m;
    }
    if(!ok)
    {
        cout<<"NO"<<endl;
        return 0;
    }

    cout<<"YES"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<mark[i]<<" ";
    }
}
