#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {
        int n;
        scanf("%d",&n);
        pair<int,int>a[n];
        for(int i=0; i<n; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i]=make_pair(x,y);
        }
        vector<pair<int,int> > v;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                v.push_back(make_pair(a[i].first+a[j].first,a[i].second+a[j].second));
            }
        }
        sort(v.begin(),v.end());
        long long ans=0;
        long long co=0;
        for(int i=1;i<v.size();i++){
            if(v[i]==v[i-1]){
                co++;
            }
            else{
                ans+=((co*(co+1))/2);
                co=0;
            }
        }
        ans+=((co*(co+1))/2);
        cout<<"Case "<<cs<<": "<<ans<<endl;

    }

}

