#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int main()
{
    int n,k;
    cin>>n>>k;
    int d[n];
    int isUsed[n];
    for(int i=0; i<n; i++)
    {
        cin>>d[i];
        d[i]=d[i]%k;
        mp[d[i]]++;
    }
    int ans=0;
    if(mp.find(0)!=mp.end())
    {
        ans+=(mp[0]);
        if(mp[0]%2==1)
            ans--;
    }
    for(int i=1; i<k; i++)
    {
        if(mp.find(i)!=mp.end() and mp.find(k-i)!=mp.end())
        {
            // cout<<i<<" "<<mp[i]<<endl;

            if(i!=k-i)
                ans+=2*min(mp[i],mp[k-i]);
            else
            {
                ans+=mp[i];
                if(mp[i]%2==1){
                    ans--;
                }
            }
            mp[i]=0;
            mp[k-i]=0;

        }

    }
    cout<<ans<<endl;

}
