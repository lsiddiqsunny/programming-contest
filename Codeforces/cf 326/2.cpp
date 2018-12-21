#include<bits/stdc++.h>
using namespace std;
long long a[1005];

int n;
bool check(long long mid,long long s)
{
    long long sum=0;
    for(int i=n-1; i>=0; i--)
    {
        if(a[i]<mid)
            continue;
        sum+=a[i]-mid;
    }
    if(sum>=s)
        return 1;
    else
        return 0;

}
int main()
{

    long long s;
    cin>>n>>s;

    long long sum=0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(sum<s)
    {
        cout<<-1<<endl;
        return 0;
    }
    long long x=ceil(s/(n*1.0));
    sort(a,a+n);
    long long lo=0,hi=*max_element(a,a+n);
    long long mid;
    long long ans=lo;
    while(lo<=hi)
    {
        mid=(lo+hi)/2.0;
       // cout<<mid<<endl;
        if(check(mid,s))
        {
            lo=mid+1;
            ans=max(ans,mid);
        }
        else
        {
            hi=mid-1;
        }

    }

    cout<<ans<<endl;


}
