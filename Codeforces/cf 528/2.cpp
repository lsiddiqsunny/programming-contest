#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int ans=INT_MAX;
    for(int i=1;i<=k-1;i++){
        int now=n/i;
        int x=now*k;       // cout<<i<<" "<<x<<endl;

        x+=i;
        if((int)(x/k)*(x%k)!=n) continue;
        ans=min(ans,x);
    }
    cout<<ans<<endl;

}

