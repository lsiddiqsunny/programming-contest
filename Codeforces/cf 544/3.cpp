#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];

    }
    sort(a,a+n);
    vector<int>v;
    for(int i=0; i<n; i++)
    {
        v.push_back(a[i]);
    }
   // cout<<endl;

    int ans=1;
    int now=a[0];
    for(int i=0; i<n; i++)
    {
        vector<int>::iterator low,up;
        low=upper_bound (v.begin(), v.end(), v[i]+5); //

        ans=max(ans,((low- v.begin())-i));


    }
    cout<<ans<<endl;


}
