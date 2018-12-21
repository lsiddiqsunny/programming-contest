#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,m;
    cin>>n>>m;
    if(n==1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    vector<int>a[n+1];
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        if(x>y)
            swap(x,y);
        a[x].push_back(y);

    }
    int ans[n+1],ans2[n+1];
    memset(ans,0,sizeof(ans));
    memset(ans2,0,sizeof(ans2));
    int now=n;
    for(int i=1; i<=n; i++)
    {//cout<<a[i].size()<<" "<<i<<endl;
        if((int)a[i].size()==0)
            continue;

        if(ans[i]==0)
        {
            ans2[i]=ans[i]=now;
            now--;

        for(int j=0; j<a[i].size(); j++)
        {
            int v=a[i][j];

            if(ans[v]==0)
            {
                ans2[v]=ans[v]=now;
                now--;
            }
        }
        }
    }
    int co=0;
    for(int i=1; i<=n; i++)
    {
        if(ans[i]==0)
        {
            co++;
        }
    }for(int i=1; i<=n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<ans2[i]<<" ";
    }cout<<"YES"<<endl;
    if(co==0)
    {
        cout<<"NO"<<endl;
        return 0;
    }

    for(int i=1; i<=n; i++)
    {
        if(ans[i]==0)
        {
            if(co==1)
            {
                ans[i]=now;
                ans2[i]=now+1;
                now--;
            }
            else
            {
                ans2[i]=ans[i]=now;
                now--;
            }
            co--;
        }
    }


    cout<<endl;


}
