#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int sz=s.size();

    long long sum=1;

    long long co=0;
    vector<long long>v;
    for(int i=0; i<sz; i++)
    {
        if(s[i]=='b' and co>0)
        {
            v.push_back(co+1);
            co=0;
        }
        else if(s[i]=='a')
            co++;


    }
    if(co>0)
        v.push_back(co+1);
    for(int i=0; i<v.size(); i++)
    {
        sum=sum*v[i];
        sum%=1000000007;
    }

    sum--;
    sum=sum+1000000007;
     sum%=1000000007;
    cout<<sum<<endl;

}
