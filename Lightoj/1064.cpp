#include<bits/stdc++.h>
using namespace std;
unsigned long long dp[200][200];
int main()
{
    unsigned long long disk[26];
    disk[0]=1;
    for(int i=1; i<=25; i++)
    {
        disk[i]=disk[i-1]*6*1LL;
       // cout<<disk[i]<<endl;
    }
    int test;
    cin>>test;
    for(int cs=1; cs<=test; cs++)
    {
        int n;
        int x;
        cin>>n>>x;
        memset(dp,0,sizeof(dp));
        dp[0][x]=1;
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=x; j++)
            {
                for(int k=1; k<=6; k++)
                {
                    int z=j+k;
                    if(z>x) z=x;
                    dp[i][j]+=dp[i-1][z];

                }
            }
        }
        unsigned long long gcd=__gcd(dp[n][0],disk[n]);

        if(dp[n][0]%disk[n]==0)
        {
            cout<<"Case "<<cs<<": "<<dp[n][0]/disk[n]<<endl;

        }
        else
        {
            cout<<"Case "<<cs<<": "<<dp[n][0]/gcd<<"/"<<disk[n]/gcd<<endl;

        }


    }

}
