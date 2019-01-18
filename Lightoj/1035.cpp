#include<bits/stdc++.h>
using namespace std;
int ans[101][101];

int main()
{
    int k;
    for(int i=2; i<=100; i++)
    {
        k=i;
        for(int j=2; j<=100; j++)
        {
            if(k==0) break;
            while(k%j==0)
            {
                ans[i][j]++;
                k/=j;
            }
        }
    }
    int test;
    cin>>test;
    for(int k=1; k<=test; k++)
    {
        int n;
        cin>>n;
        int a[101];
        memset(a,0,sizeof a);
        for(int i=2; i<=n; i++)
        {
            for(int j=2; j<=100; j++)
                a[j]+=ans[i][j];
        }
        cout<<"Case "<<k<<": "<<n<<" = ";
        vector<int> ad;
        for(int i=2; i<=100; i++)
        {
            if(a[i]!=0) ad.push_back(i);
        }
        for(int i=0; i<ad.size(); i++)
        {
            cout<<ad[i]<<" ("<<a[ad[i]]<<")";
            if(i!=ad.size()-1) cout<<" * ";
        }
        cout<<endl;
    }


}
