#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    for(int cs=1; cs<=test; cs++)
    {
        int n,p;
        cin>>n>>p;
        long long a[n+1];
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        long long cost=0;
        for(int i=1; i<=p; i++)
        {
            cost+=(a[p]-a[i]);
        }
        long long nowcost=cost;
        for(int i=p+1; i<=n; i++)
        {
            nowcost-=(a[i-1]-a[i-p]);
            //cout<<nowcost<<endl;
            nowcost+=(p-1)*(a[i]-a[i-1]);

            cost=min(nowcost,cost);
        }

        cout<<"Case #"<<cs<<":"<<cost<<endl;


    }


}
