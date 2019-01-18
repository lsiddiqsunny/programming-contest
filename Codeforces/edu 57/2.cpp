#include <bits/stdc++.h>
using namespace std;
long long mod=998244353;
int main()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<1<<endl;
        return 0;

    }
    string s;
    cin>>s;
    long long co=0LL;
    char c=s[0];
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]==c)
        {
            co++;
        }
        else
            break;
    }
    if(co==s.size())
    {
        co=n*(n+1);
        co/=2LL;
        cout<<(co%mod)<<endl;
        return 0;
    }
    co=0;
    int i;
    long long z=0;
    for(i=0; i<s.size(); i++)
    {
        if(s[i]==c)
        {
            co++;
            z++;
        }
        else
            break;
    }
    c=s[s.size()-1];
    long long int y=0;
    for(i=s.size()-1; i>=0; i--)
    {
        if(s[i]==c)
        {
            co++;
            y++;
        }
        else
            break;
    }
   // cout<<co<<endl;

    if(s[0]==s[n-1])
    {

        co=co+(z)*(y);
       // co++;

        co%=mod;

    }

    cout<<(co+1)%mod<<endl;

    return 0;
}
