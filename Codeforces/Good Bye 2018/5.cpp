#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long m;
    cin>>m;
    vector<long long >div;
    for(int i=1; i<=sqrt(m); i++)
    {
        if(m%i==0)
        {
            div.push_back(i);
            if(m/i!=i)
            {
                div.push_back(m/i);
            }
        }
    }
    long long start=2;
    set<long long int>a;
    for(int i=0;i<div.size();i++)
    {
        start=div[i];
        long long n=(m/start);
        long long ans=(n)*(2+(n-1)*start);
        ans/=2;

      //  cout<<start<<" "<<ans<<endl;
        a.insert(ans);
    }

    for(auto x:a)
    {
        cout<<x<<" ";
    }

}

