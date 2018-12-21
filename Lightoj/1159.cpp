#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    for(int i=1; i<=test; i++)
    {
        //cin.ignore();
        string a,b,c;
        cin>>a>>b>>c;
        int n=a.size(),m=b.size(),p=c.size();
        if(n==0||m==0||p==0){
                    cout<<"Case "<<i<<": "<<0<<endl;
                    continue;

        }
        int dp[60][60][60];
        memset(dp,0,sizeof(dp));
        for(int i=0; i<=n; i++)
        {
            dp[i][0][0]=0;
        }
        for(int i=0; i<=m; i++)
        {
            dp[0][i][0]=0;
        }
        for(int i=0; i<=p; i++)
        {
            dp[0][0][i]=0;
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                for(int k=0; k<p; k++)
                {
                    if(a[i]==b[j]&&b[j]==c[k])
                    {
                        dp[i+1][j+1][k+1]=dp[i][j][k]+1;
                    }
                    else
                    {
                        dp[i+1][j+1][k+1]=max(dp[i+1][j+1][k],max(dp[i+1][j][k+1],dp[i][j+1][k+1]));
                    }
                }
            }
        }
        cout<<"Case "<<i<<": "<<dp[n][m][p]<<endl;

    }
}
