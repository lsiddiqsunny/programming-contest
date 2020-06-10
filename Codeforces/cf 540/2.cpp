#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long a[n+1];
    long long oddsum[n+1],evensum[n+1];
    memset(oddsum,0,sizeof(oddsum));
    memset(evensum,0,sizeof(evensum));
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        if(i%2==0)
        {
            evensum[i]+=(evensum[i-1]+a[i]);
            oddsum[i]=oddsum[i-1];

        }
        else
        {
            oddsum[i]+=(oddsum[i-1]+a[i]);
            evensum[i]=evensum[i-1];
        }
    }
    for(int i=1; i<=n; i++)
    {

      //  cout<<oddsum[i]<<" "<<evensum[i]<<endl;
    }

    int ans=0;
    for(int i=1; i<=n; i++)
    {
        if(i%2==1)
        {
            long long x=oddsum[i-1];
            long long y=evensum[i-1];
            x+=(evensum[n]-evensum[i]);
            y+=(oddsum[n]-oddsum[i]);
            if(x==y)
            {
                ans++;
            }
           // cout<<i<<" "<<ans<<endl;

        }
        else
        {
            long long x=oddsum[i-1];
            long long y=evensum[i-1];
            x+=(evensum[n]-evensum[i]);
            y+=(oddsum[n]-oddsum[i]);
            if(x==y)
            {
                ans++;
            }


        }

    }
    cout<<ans<<endl;
}
