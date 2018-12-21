#include<bits/stdc++.h>
using namespace std;
long long int dp[70][70];
string s;
long long int pal(int i,int j)
{
    if(i>j) return dp[i][j]=0;
    if(i==j) return dp[i][j]=1;
    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i] == s[j])
        return dp[i][j] = (1 + pal(i+1, j-1)) + (pal(i+1, j) +pal(i, j-1) - pal(i+1, j-1));
    else
        return dp[i][j] = pal(i+1, j) +pal(i, j-1) - pal(i+1, j-1);
}

int main()
{
    int test;
    cin>>test;
    for(int i=1; i<=test; i++)
    {

        cin>>s;


        memset(dp,-1,sizeof(dp));

        cout<<"Case "<<i<<": "<< pal(0,s.size()-1)<<endl;
    }
}
