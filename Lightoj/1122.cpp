
#include<bits/stdc++.h>
using namespace std;
#define mx 110
long long int a[mx];
long long int dp[mx][mx];
int N;
int check(int m,int n)
{
    if(m==1) return 1;
    if(dp[m][n]==-1)
    {
      long long   int total=0;
        for(int i=1; i<=N; i++)
        {
            if(abs(a[i]-a[n])<=2)
                total+=check(m-1,i);
        }
        dp[m][n]=total;
    }
    return dp[m][n];
}
int main()
{
    int test;
    cin>>test;
    for(int i=1; i<=test; i++)
    {

        int m;

        cin>>N>>m;
        for(int j=1; j<=N; j++)
        {
            cin>>a[j];
        }
      long long   int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int j=1; j<=N; j++)
        {
            ans+=check(m,j);
        }
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
}
