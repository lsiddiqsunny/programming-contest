#include<bits/stdc++.h>
using namespace std;
int mp[200005];
int main()
{
    freopen("A-large-practice.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int test;
    cin>>test;
    for(int cs=1; cs<=test; cs++)
    {
        int n;
        cin>>n;
        long long a[n];
        long long int z=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(!a[i])
                z++;
            else
                mp[a[i]]++;
        }
        sort(a,a+n);
        long long ans=0;
        for(int i=0; i<n; i++)
        {
            if(a[i]==0)
                continue;
            memset(mp,0,sizeof(mp));
            for(int j=i+1; j<n; j++)
            {

                mp[a[j]]++;
            }
            for(int j=i+1; j<n; j++)
            {

                mp[a[j]]--;
                if(a[i]*a[j]>200000) continue;
                ans+=(mp[a[i]*a[j]]);
            }

        }
        ans+=((z*(z-1)*(z-2))/6);
        ans+=(((z*(z-1))/2)*(n-z));
        cout<<"Case #"<<cs<<": "<<ans<<endl;



    }


}
