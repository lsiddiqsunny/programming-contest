#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    for(int i=1; i<=test; i++)
    {
        int n;
        cin>>n;
        vector<int>a,b;
        int x;
        for(int j=0; j<n; j++)
        {
            cin>>x;
            a.push_back(x);
        }
        for(int j=0; j<n; j++)
        {
            cin>>x;
            b.push_back(x);
        }
        sort(a.begin(),a.end());
        sort(b.rbegin(),b.rend());
        int ans=0;
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                if(a[k]!=-1)
                {
                    if(a[k]>b[j])
                    {
                        ans=ans+2;
                        a[k]=b[j]=-1;
                        break;
                    }
                }
            }
        }
         for(int j=0; j<n; j++)
        {
            if(b[j]!=-1)
            for(int k=0; k<n; k++)
            {
                if(a[k]!=-1)
                {
                    if(a[k]==b[j])
                    {
                        ans=ans+1;
                        a[k]=b[j]=-1;
                        break;
                    }
                }
            }
        }
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
}
