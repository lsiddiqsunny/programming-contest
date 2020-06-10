#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    int primelist[10005];
    vector<int>prime;
    for(int i=2; i<=10000; i++)
    {
        int ok=0;
        primelist[i]=0;
        for(int j=2; j<=sqrt(i); j++)
        {
            if(i%j==0)
            {
                ok=1;
                break;
            }
        }
        if(!ok)
        {
            prime.push_back(i);
            primelist[i]=1;
            //   cout<<i<<endl;
        }
    }
    for(int cs=1; cs<=test; cs++)
    {
        int n,l;
        cin>>n>>l;
        int a[l+1];
        for(int i=1; i<=l; i++)
        {
            cin>>a[i];
        }
        int p1,p2;
        for(int i=0; i<prime.size(); i++)
        {
            if(a[1]%prime[i]==0)
            {
                p1=prime[i];
                p2=a[1]/prime[i];
                break;
            }
        }
        //  cout<<p1<<" "<<p2<<endl;
        int ans[l+2];
        ans[0]=p1;
        int ok=1;
        for(int i=1; i<=l; i++)
        {
            ans[i]=a[i]/ans[i-1];
            if(ans[i]<2 || ans[i]>n || primelist[ans[i]]!=1)


            {
                ok=0;
                break;
            }
        }
        if(ok==0)
        {
           // cout<<"here"<<endl;
            ans[0]=p2;
            for(int i=1; i<=l; i++)
            {
                ans[i]=a[i]/ans[i-1];

            }
        }
        set<int>pr;
        for(int i=0; i<=l; i++)
        {
            pr.insert(ans[i]);
        }
        map<int,char> mp;
        int z=0;
        for(auto x: pr)
        {
            mp[x]='A'+z;
            z++;
            //  cout<<x<<endl;

        }
        cout<<"Case #"<<cs<<": ";
        for(int i=0; i<=l; i++)
        {
            cout<<mp[ans[i]];
        }
        cout<<endl;



    }

}
