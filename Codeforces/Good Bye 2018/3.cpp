#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long m;
    cin>>m;
    long long start=2;
    set<long long int>a;
    for(; start<m; start=start+1)
    {
        int ans=0;
        int x=1;
        ans+=x;
        x+=start;
        cout<<start<<" "<<x<<" ";
        while(x!=1){

            ans+=x;
            x+=start;
            x%=m;
            if(x==0) x=m;
            cout<<x<<" ";

        }
        cout<<endl<<ans<<endl;
        a.insert(ans);
    }

    a.insert(1);
    // cout<<n<<" "<<ans<<endl;


    for(auto x:a)
    {
        cout<<x<<" ";
    }

}
