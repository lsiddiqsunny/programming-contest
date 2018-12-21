#include<bits/stdc++.h>
using namespace std;
int mod=10056;
#define mx 1005
int com [mx][mx];
int dp [mx];
int main()
{
    for(int i=0; i<mx; i++)
    {
        com[i][0]=com[i][i]=1;
    }
    for(int i=2;i<mx;i++){
        for(int j=1;j<i;j++){
            com[i][j]=(com[i-1][j]%mod+com[i-1][j-1]%mod)%mod;
        }
    }
    dp[0]=dp[1]=1;
    for(int i=2;i<mx;i++){
        dp[i]=0;
        for(int j=1;j<=i;j++){
            dp[i]=(dp[i]%mod+(dp[i-j]%mod*(com[i][j]%mod)%mod)%mod)%mod;
        }
    }
    int test;
    cin>>test;
    for(int i=1;i<=test;i++){
        int n;
        cin>>n;
        cout<<"Case "<<i<<": "<<dp[n]<<endl;
    }
}
