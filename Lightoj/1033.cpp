#include<bits/stdc++.h>
using namespace std;
#define SIZE 105
int dp[SIZE][SIZE];
string s;
int co(int i,int j)
{
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==s[j])
        dp[i][j]=co(i+1,j-1);
    else
    {
        dp[i][j]=1+min(co(i+1,j),co(i,j-1));
    }
    return dp[i][j];
}

int main()
{
    int test;
    cin>>test;
    for(int i=1; i<=test; i++)
    {
        cin>>s;
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<i<<": "<<co(0,s.size()-1)<<endl;


    }
}
