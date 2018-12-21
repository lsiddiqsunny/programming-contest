#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    long long int maxi=INT_MIN;
    vector<long long int>v[n];
    for(int i=0; i<n; i++)
    {
        int m;
        scanf("%d",&m);
       // cout<<i<<" "<<m<<endl;
        for(int j=0; j<m; j++)
        {
            long long int x;
            scanf("%lld",&x);
            v[i].push_back(x);
        }
        maxi=max(maxi,*max_element(v[i].begin(),v[i].end()));
    }
    long long ans=0;
    for(int i=0; i<n; i++)
    {
        ans=ans+v[i].size()*(maxi-(long long )(*max_element(v[i].begin(),v[i].end())));
    }
    printf("%lld",ans);
}
