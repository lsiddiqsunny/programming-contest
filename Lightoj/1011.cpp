#include<bits/stdc++.h>
using namespace std;
#define mx 17
#define check(n, pos) (n & (1<<pos))
#define set(n, pos) (n | (1<<pos))
long long a[mx][mx];
long long dp[mx][1<<mx];
int n;
long long DP(int boy,long long int girl)
{
    if(boy==n) return 0;
    if(dp[boy][girl]!=-1) return dp[boy][girl];
    long long sum=INT_MIN;
    for(int i=0; i<n; i++)
    {
        if(check(girl, i) == 0)
            sum=max(sum,a[boy][i]+DP(boy+1,set(girl,i)));
    }
    return dp[boy][girl]=sum;
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {

        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        memset(dp,-1,sizeof(dp));
        long long sum=DP(0,0);
        printf("Case %d: %lld\n",cs,sum);

    }

}
