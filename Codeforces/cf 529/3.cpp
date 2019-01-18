#include<bits/stdc++.h>
using namespace std;
long long two[32];
map<long long,int>mp;
int main()
{
    two[0]=1;
    mp[1]=0;
    for(int i=1; i<32; i++)
    {
        two[i]=2*two[i-1];
        mp[two[i]]=i;
        // cout<<two[i]<<endl;
    }
    int n,k;
    cin>>n>>k;
    if(n<k)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    else if(n==k)
    {
        cout<<"YES"<<endl;
        for(int i=1; i<=k; i++)
        {
            cout<<1<<" ";
        }
        return 0;
    }
    vector<int>ans;
    for(int i=31; i>=0; i--)
    {
        if(two[i]>n)
            continue;
        ans.push_back(two[i]);
        n-=two[i];
    }
    if(k<ans.size())
    {
        cout<<"NO"<<endl;
        return 0;
    }
    else if(k==ans.size())
    {

        cout<<"YES"<<endl;
        reverse(ans.begin(),ans.end());

        for(int i=0; i<ans.size(); i++)
        {
            cout<<ans[i]<<" ";
        }
        return 0;

    }
    // reverse(ans.begin(),ans.end());
    int sz=ans.size();
    vector<int>ans2;
    for(int i=0; i<ans.size(); i++)
    {
        int x=ans[i];
        // if(x==1) continue;
        while(ans[i]!=1)
        {
            ans[i]=ans[i]/2;
            sz++;
            ans.push_back(ans[i]);
            if(sz==k)
                break;


        }
        if(sz==k)
            break;

    }
    if(sz<k)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    sort(ans.begin(),ans.end());
    cout<<"YES"<<endl;
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }


}
