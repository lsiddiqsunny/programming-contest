#include<bits/stdc++.h>
using namespace std;
#define i64 unsigned long long

i64 dp[105][105];

i64 nCr(int n, int r)
{
    if(n==r) return dp[n][r] = 1;
    if(r==0) return dp[n][r] = 1;
    if(r==1) return dp[n][r] = (i64)n;
    if(dp[n][r]) return dp[n][r];
    return dp[n][r] = nCr(n-1,r) + nCr(n-1,r-1);
}

int main()
{
    int test;
    cin>>test;
    for(int i=1;i<=test;i++){
        long long n,k;
        cin>>n>>k;
        cout<<"Case "<<i<<": ";
        if(n<k) cout<<0<<endl;
      else  if(k==0) cout<<1<<endl;
        else{
            long long ans=nCr(n,k);
            for(int j=n;j>(n-k);j--) ans*=(long long )j;
            cout<<ans<<endl;
        }
    }

}
