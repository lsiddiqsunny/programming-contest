#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long m;
    cin>>m;
    long long start=2;
    set<long long int>a;
    for(; start<=((m+1)/2); start=start*2)
    {

        //start=min(start,m-start);
        long long n=(ceil((m+1.0)/start));
        //  if(m%2 and start%2) n++;
        cout<<start<<" "<<n<<endl;
        long long ans=(n)*(2+(n-1)*start);
        ans/=2;
        cout<<start<<" "<<ans<<endl;
        if(m%2)
        {
            long long x=(n-1)*(4+(n-2)*start);
            x/=2;
            ans+=x;
        }

        a.insert(ans);
    }

    a.insert(1);
    a.insert((m*(m+1))/2);
    start=m/2;
    if(start!=0 and m%2==0)
    {
        long long n=(m/start);
        long long ans=(n)*(2+(n-1)*start);
        ans/=2;

        // cout<<n<<" "<<ans<<endl;
        a.insert(ans);
    }

    for(auto x:a)
    {
        cout<<x<<" ";
    }

}
