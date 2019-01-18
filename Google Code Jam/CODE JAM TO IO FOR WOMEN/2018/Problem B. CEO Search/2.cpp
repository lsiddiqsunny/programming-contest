#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("B-large-practice.in","r",stdin);
    freopen("output.txt", "w", stdout);
    int test;
    cin>>test;
    for(int cs=1; cs<=test; cs++)
    {
        int n;
        cin>>n;
        long long ans=0;
        long long maxi=0;
        for(int i=0; i<n; i++)
        {
            long long x,y;
            cin>>x>>y;
            ans-=(x*y);
            ans=max(0LL,ans);
            maxi=max(maxi,y);
            ans+=x;


        }
        cout<<"Case #"<<cs<<": "<<max(ans,maxi+1)<<endl;


    }

}
