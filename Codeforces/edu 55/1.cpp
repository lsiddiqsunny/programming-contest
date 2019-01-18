#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        long long n,x,y,d;
        cin>>n>>x>>y>>d;
        long long ans=abs(y-x);
        if(ans%d==0)
        {
            cout<<ans/d<<endl;;
        }
        else
        {
            long long ans=INT_MAX;
            if ((y - 1) % d == 0)
            {
                ans=min(ans,(y-1)/d+(x-1)/d+((x-1)%d!=0));
            }

            if((n-y)%d==0)
            {
                ans=min(ans,(n-y)/d+(n-x)/d+((n-x)%d!=0));
            }
            if(ans==INT_MAX)
                ans=-1;
            cout<<ans<<endl;


        }

    }

}
