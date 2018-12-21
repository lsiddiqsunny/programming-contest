#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005];
ll b[100005];
int n,m;
ll f(int x)
{
    ll ans=0;
    for(int i=0; i<n; i++)
    {
        if(a[i]<x)
        {
            ans+=(x-a[i]);
        }
    }
    for(int i=0; i<m; i++)
    {
        if(b[i]>x)
        {
            ans+=(b[i]-x);
        }
    }
    return ans;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    ll ans=(INT_MAX-1LL)*(INT_MAX-1LL);
    //cout<<ans<<endl;
    ll lo=1LL;
    ll hi=INT_MAX;

    for (int i = 0; i < 100; i++) {
        ll mid1 = lo + (hi - lo) / 3;
        ll mid2 = hi - (hi - lo) / 3;

        if (f(mid1) < ans) {
            ans = f(mid1);
        }
        if (f(mid2) < ans) {
            ans = f(mid2);
        }
        if (f(mid1) >= f(mid2)) {
            lo = mid1;
        } else {
            hi = mid2;
        }
    }
    cout << ans << endl;

}
