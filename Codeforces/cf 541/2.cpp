#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x=0,y=0;

    int u,v;
    int ans=1;
    for(int i=1; i<=n; i++)
    {
        cin>>u>>v;
        int x1=max(x,y);
        int y1=min(u,v);
        // if(x==u and y==v) continue;
        //  cout<<x1<<" "<<y1<<endl;

        ans+=(y1>=x1)*(y1-x1+1);
        if(x==y)
            ans--;

        x=u;
        y=v;


    }
    cout<<ans<<endl;


}
