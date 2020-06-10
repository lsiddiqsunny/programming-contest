#include<bits/stdc++.h>
using namespace std;

map<pair<long long,long long>,int> mp;
int main()
{
    int n;
    cin>>n;
    long long int a[n];
    long long int b[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>b[i];
    }

    for(int i=0; i<n; i++)
    {
        if(a[i]==0)
        {
            continue;
        }

        long long x=__gcd(-b[i],a[i]);
        pair<long long,long long> p=make_pair(-b[i]/x,a[i]/x);
        if(p.first<0 )
        {
            p.first*=-1;
            p.second*=-1;
        }
        cout<<p.first<<" "<<p.second<<endl;
        mp[p]++;

    }
    int ans=0;

    for(auto x: mp)
    {

        ans=max(ans,x.second);
    }
    cout<<ans<<endl;
}
