#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    map<int,int>mp;
    int a[n];
vector<int>v;

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        mp[a[i]]++;
        v.push_back(a[i]);
    }
    sort(v.rbegin(),v.rend());
    v.erase(unique(v.begin(), v.end()), v.end());

    int ans=0;
    for(int i=0; i<v.size(); i++)
    {
        for(int j=30; j>=0; j--)
        {
            if(mp[v[i]]==0)
                continue;
            int x=  (1<<j)-v[i];
            if(mp.find(x)==mp.end()) continue;
            int now=mp[x];
            if(v[i]==x){
                now/=2;
            }
            else{
                now=min(mp[x],mp[v[i]]);
            }
            ans+=now;
            mp[v[i]]-=now;
            mp[x]-=now;

        }

    }
    cout<<ans<<endl;


}
